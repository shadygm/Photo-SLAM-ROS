#ifndef GAUSSIAN_PUBLISHER__GAUSSIAN_PUBLISHER_HPP_
#define GAUSSIAN_PUBLISHER__GAUSSIAN_PUBLISHER_HPP_

#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <thread>

#include "gaussian_interface/msg/gaussian_array.hpp"
#include "gaussian_interface/msg/single_gaussian.hpp"
#include "gaussian_model.h"
#include "rclcpp/rclcpp.hpp"
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
  std::string topic_name_;
};

#endif // GAUSSIAN_PUBLISHER__GAUSSIAN_PUBLISHER_HPP_
