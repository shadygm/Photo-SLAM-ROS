#include "include/gaussian_ros_publisher.h"
#include "rclcpp_components/register_node_macro.hpp"
#include <sstream>
#include <thread>
#include <vector>
#include <future>

GaussianPublisher::GaussianPublisher(const rclcpp::NodeOptions &options)
    : Node("gaussian_publisher", options), stop_pool_(false) {
  topic_name_ = this->declare_parameter<std::string>("topic", "gaussians");

  image_publisher_ = this->create_publisher<sensor_msgs::msg::Image>("gaussian_image", rclcpp::QoS(10));

  rclcpp::QoS qos(200);
  qos.reliable();
  qos.durability_volatile();

  gaussian_publisher_ = this->create_publisher<gaussian_interface::msg::GaussianArray>("gaussian_model", qos);
  
  startThreadPool(std::thread::hardware_concurrency());
}

GaussianPublisher::~GaussianPublisher() {
  stopThreadPool();
}

void GaussianPublisher::startThreadPool(size_t num_threads) {
  for (size_t i = 0; i < num_threads; ++i) {
    workers_.emplace_back([this]() {
      while (true) {
        std::function<void()> task;
        {
          std::unique_lock<std::mutex> lock(queue_mutex_);
          condition_.wait(lock, [this] { return stop_pool_ || !tasks_.empty(); });
          if (stop_pool_ && tasks_.empty()) return;
          task = std::move(tasks_.front());
          tasks_.pop();
        }
        task();
      }
    });
  }
}

void GaussianPublisher::stopThreadPool() {
  {
    std::lock_guard<std::mutex> lock(queue_mutex_);
    stop_pool_ = true;
  }
  condition_.notify_all();
  for (auto& worker : workers_) {
    if (worker.joinable()) worker.join();
  }
}

void GaussianPublisher::enqueueTask(std::function<void()> task) {
  {
    std::lock_guard<std::mutex> lock(queue_mutex_);
    tasks_.push(std::move(task));
  }
  condition_.notify_one();
}

void GaussianPublisher::publishImage(torch::Tensor image) {
  if (image.dim() == 3 && image.size(0) == 3) {
    image = image.permute({1, 2, 0});
  }
  image = image.contiguous().to(torch::kCPU).to(torch::kU8);
  cv::Mat cv_image(image.size(0), image.size(1), CV_8UC3, image.data_ptr());
  sensor_msgs::msg::Image img_msg;
  img_msg.header.stamp = this->now();
  img_msg.header.frame_id = "camera_frame";
  img_msg.height = cv_image.rows;
  img_msg.width = cv_image.cols;
  img_msg.encoding = "bgr8";
  img_msg.is_bigendian = false;
  img_msg.step = static_cast<sensor_msgs::msg::Image::_step_type>(cv_image.step);
  img_msg.data.assign(cv_image.datastart, cv_image.dataend);
  image_publisher_->publish(img_msg);
}

void GaussianPublisher::publishCVImage(cv::Mat image) {
  sensor_msgs::msg::Image img_msg;
  img_msg.header.stamp = this->now();
  img_msg.header.frame_id = "camera_frame";
  img_msg.height = image.rows;
  img_msg.width = image.cols;
  img_msg.encoding = "bgr8";
  img_msg.is_bigendian = false;
  img_msg.step = static_cast<sensor_msgs::msg::Image::_step_type>(image.step);
  img_msg.data.assign(image.datastart, image.dataend);
  image_publisher_->publish(img_msg);
}

void GaussianPublisher::publishGaussians(std::shared_ptr<GaussianModel> gaussians) {
  auto xyz = gaussians->getXYZ().to(torch::kCPU).contiguous();
  auto rot = gaussians->getRotationActivation().to(torch::kCPU).contiguous();
  auto scale = gaussians->getScalingActivation().to(torch::kCPU).contiguous();
  auto opacity = gaussians->getOpacityActivation().to(torch::kCPU).contiguous();
  auto sh = gaussians->getFeatures().to(torch::kCPU).contiguous();

  const int64_t N = xyz.size(0);
  constexpr int SH_OUT = 15;
  constexpr int BATCH_SIZE = 4000;

  auto sh_flat = sh.view({N, 48});
  const float* xyz_ptr = xyz.data_ptr<float>();
  const float* rot_ptr = rot.data_ptr<float>();
  const float* scale_ptr = scale.data_ptr<float>();
  const float* opacity_ptr = opacity.data_ptr<float>();
  const float* sh_ptr = sh_flat.data_ptr<float>();

  RCLCPP_INFO(this->get_logger(), "Publishing %ld gaussians", N);

  bool refresh_sent = false;

  for (int64_t offset = 0; offset < N; offset += BATCH_SIZE) {
    int64_t this_batch = std::min<int64_t>(BATCH_SIZE, N - offset);
    auto msg = std::make_shared<gaussian_interface::msg::GaussianArray>();
    msg->gaussians.resize(this_batch);
    msg->refresh = !refresh_sent;
    refresh_sent = true;

    std::vector<std::future<void>> futures;
    const int num_threads = std::thread::hardware_concurrency();
    const int items_per_thread = (this_batch + num_threads - 1) / num_threads;
    auto publish_start = std::chrono::high_resolution_clock::now();

    for (int t = 0; t < num_threads; ++t) {
      int64_t start = t * items_per_thread;
      int64_t end = std::min<int64_t>(start + items_per_thread, this_batch);
      if (start >= end) continue;

      auto promise = std::make_shared<std::promise<void>>();
      futures.push_back(promise->get_future());

      enqueueTask([=]() {
        for (int64_t i = start; i < end; ++i) {
          int64_t idx = offset + i;
          auto& sg = msg->gaussians[i];

          sg.xyz.x = xyz_ptr[idx * 3 + 0];
          sg.xyz.y = xyz_ptr[idx * 3 + 1];
          sg.xyz.z = xyz_ptr[idx * 3 + 2];

          sg.rotation.x = rot_ptr[idx * 4 + 0];
          sg.rotation.y = rot_ptr[idx * 4 + 1];
          sg.rotation.z = rot_ptr[idx * 4 + 2];
          sg.rotation.w = rot_ptr[idx * 4 + 3];

          sg.scale.x = scale_ptr[idx * 3 + 0];
          sg.scale.y = scale_ptr[idx * 3 + 1];
          sg.scale.z = scale_ptr[idx * 3 + 2];

          sg.opacity = opacity_ptr[idx];

          sg.spherical_harmonics.resize(SH_OUT);
          const float* sh_row = sh_ptr + idx * 48;  // Keep full row stride
          std::memcpy(sg.spherical_harmonics.data(), sh_row, SH_OUT * sizeof(float));
        }
        promise->set_value();
      });
    }

    for (auto& fut : futures) fut.get();  // wait for all threads


    gaussian_publisher_->publish(*msg);

    auto publish_end = std::chrono::high_resolution_clock::now();
    auto duration_us = std::chrono::duration_cast<std::chrono::microseconds>(publish_end - publish_start).count();

    // NOTE: Uncomment the following line to log the time taken for each batch
    // RCLCPP_INFO(this->get_logger(), "Published %ld gaussians in %ld µs", this_batch, duration_us);
  }
  RCLCPP_INFO(this->get_logger(), "Published %ld gaussians in total", N);
}

