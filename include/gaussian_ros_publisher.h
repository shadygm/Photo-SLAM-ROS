#ifndef GAUSSIAN_PUBLISHER__GAUSSIAN_PUBLISHER_HPP_
#define GAUSSIAN_PUBLISHER__GAUSSIAN_PUBLISHER_HPP_

#include <memory>
#include <vector>

#include "gaussian_interface/msg/gaussian_array.hpp"
#include "gaussian_interface/msg/single_gaussian.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/quaternion.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "rclcpp/rclcpp.hpp"

namespace gaussian_publisher {

class GaussianPublisher : public rclcpp::Node {
public:
  explicit GaussianPublisher(
      const rclcpp::NodeOptions &options = rclcpp::NodeOptions());

private:
  void publishGaussians();

  rclcpp::Publisher<gaussian_interface::msg::GaussianArray>::SharedPtr
      publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  double publish_rate_;
  std::string topic_name_;
};

} // namespace gaussian_publisher

#endif // GAUSSIAN_PUBLISHER__GAUSSIAN_PUBLISHER_HPP_
