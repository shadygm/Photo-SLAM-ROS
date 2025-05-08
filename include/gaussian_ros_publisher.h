#ifndef GAUSSIAN_PUBLISHER__GAUSSIAN_PUBLISHER_HPP_
#define GAUSSIAN_PUBLISHER__GAUSSIAN_PUBLISHER_HPP_

#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

#include "gaussian_interface/msg/gaussian_array.hpp"
#include "gaussian_interface/msg/single_gaussian.hpp"
#include "gaussian_model.h"
#include "rclcpp/rclcpp.hpp"

class GaussianPublisher : public rclcpp::Node {
public:
  explicit GaussianPublisher(
      const rclcpp::NodeOptions &options = rclcpp::NodeOptions());
  ~GaussianPublisher();

  void publishGaussianMap(std::shared_ptr<GaussianModel> gaussians);

private:
  void publishingThread();

  rclcpp::Publisher<gaussian_interface::msg::GaussianArray>::SharedPtr
      publisher_;
  std::string topic_name_;

  std::thread worker_thread_;
  std::atomic<bool> running_;
  std::mutex model_mutex_;
  std::shared_ptr<GaussianModel> latest_model_;
  std::condition_variable cv_;
};

#endif // GAUSSIAN_PUBLISHER__GAUSSIAN_PUBLISHER_HPP_
