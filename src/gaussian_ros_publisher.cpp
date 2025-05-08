#include "include/gaussian_ros_publisher.h"
#include "rclcpp_components/register_node_macro.hpp"

GaussianPublisher::GaussianPublisher(const rclcpp::NodeOptions &options)
    : Node("gaussian_publisher", options), running_(true) {
  topic_name_ =
      this->declare_parameter<std::string>("topic", "gaussiansblehbleh");

  publisher_ = this->create_publisher<gaussian_interface::msg::GaussianArray>(
      topic_name_, rclcpp::QoS(10));

  worker_thread_ = std::thread(&GaussianPublisher::publishingThread, this);
}

GaussianPublisher::~GaussianPublisher() {
  running_ = false;
  cv_.notify_all();
  if (worker_thread_.joinable())
    worker_thread_.join();
}

void GaussianPublisher::publishGaussianMap(
    std::shared_ptr<GaussianModel> gaussians) {
  {
    std::lock_guard<std::mutex> lock(model_mutex_);
    latest_model_ = gaussians;
  }
  cv_.notify_one(); // wake up thread to publish
}

void GaussianPublisher::publishingThread() {
  while (running_) {
    std::shared_ptr<GaussianModel> model_copy;

    {
      std::unique_lock<std::mutex> lock(model_mutex_);
      cv_.wait(lock, [&] { return !running_ || latest_model_; });

      if (!running_)
        break;

      model_copy = latest_model_;
      latest_model_.reset(); // Clear after consuming
    }

    if (!model_copy || model_copy->xyz_.numel() == 0)
      continue;

    torch::NoGradGuard no_grad;

    auto xyz_cpu = model_copy->xyz_.to(torch::kCPU);
    auto rotation_cpu = model_copy->rotation_.to(torch::kCPU);
    auto scaling_cpu = model_copy->scaling_.to(torch::kCPU);
    auto opacity_cpu = model_copy->opacity_.to(torch::kCPU);
    auto feats_dc_cpu = model_copy->features_dc_.to(torch::kCPU);
    auto feats_rest_cpu = model_copy->features_rest_.to(torch::kCPU);

    const int N = xyz_cpu.size(0);
    auto sh_3d = torch::cat({feats_dc_cpu, feats_rest_cpu}, 1); // [N,16,3]
    auto sh_flat = sh_3d.view({N, -1});                         // [N, 48]

    gaussian_interface::msg::GaussianArray msg;
    for (int i = 0; i < N; ++i) {
      gaussian_interface::msg::SingleGaussian g;

      g.xyz.x = xyz_cpu[i][0].item<float>();
      g.xyz.y = xyz_cpu[i][1].item<float>();
      g.xyz.z = xyz_cpu[i][2].item<float>();

      g.rotation.w = rotation_cpu[i][0].item<float>();
      g.rotation.x = rotation_cpu[i][1].item<float>();
      g.rotation.y = rotation_cpu[i][2].item<float>();
      g.rotation.z = rotation_cpu[i][3].item<float>();

      g.opacity = opacity_cpu[i][0].item<float>();

      g.scale.x = scaling_cpu[i][0].item<float>();
      g.scale.y = scaling_cpu[i][1].item<float>();
      g.scale.z = scaling_cpu[i][2].item<float>();

      g.spherical_harmonics.reserve(sh_flat.size(1));
      for (int k = 0; k < sh_flat.size(1); ++k) {
        g.spherical_harmonics.push_back(sh_flat[i][k].item<float>());
      }

      msg.gaussians.push_back(std::move(g));
    }

    publisher_->publish(std::move(msg));
  }
}

RCLCPP_COMPONENTS_REGISTER_NODE(GaussianPublisher)
