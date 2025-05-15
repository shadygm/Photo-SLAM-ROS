#ifndef GAUSSIAN_PUBLISHER__GAUSSIAN_PUBLISHER_HPP_
#define GAUSSIAN_PUBLISHER__GAUSSIAN_PUBLISHER_HPP_

#include <atomic>
#include <condition_variable>
#include <functional>
#include <future>
#include <memory>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

#include "gaussian_interface/msg/gaussian_array.hpp"
#include "gaussian_interface/msg/single_gaussian.hpp"
#include "gaussian_model.h"
#include "rclcpp/rclcpp.hpp"
#include <std_msgs/msg/empty.hpp>
#include "sensor_msgs/msg/image.hpp"
#include <torch/torch.h>
#include <opencv2/opencv.hpp>

class GaussianPublisher : public rclcpp::Node {
public:
  explicit GaussianPublisher(const rclcpp::NodeOptions &options = rclcpp::NodeOptions());
  ~GaussianPublisher();

  void publishImage(torch::Tensor image);
  void publishGaussians(std::shared_ptr<GaussianModel> gaussians);
  void publishCVImage(cv::Mat image);

private:
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_publisher_;
  rclcpp::Publisher<gaussian_interface::msg::GaussianArray>::SharedPtr gaussian_publisher_;
  rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr refresh_publisher_;
  std::string topic_name_;

  // --- Thread pool members ---
  std::vector<std::thread> workers_;
  std::queue<std::function<void()>> tasks_;
  std::mutex queue_mutex_;
  std::condition_variable condition_;
  std::atomic<bool> stop_pool_;

  void startThreadPool(size_t num_threads);
  void stopThreadPool();
  void enqueueTask(std::function<void()> task);
};

#endif // GAUSSIAN_PUBLISHER__GAUSSIAN_PUBLISHER_HPP_
