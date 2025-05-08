#include "include/gaussian_ros_publisher.h"

using namespace std::chrono_literals;

namespace gaussian_publisher {

GaussianPublisher::GaussianPublisher(const rclcpp::NodeOptions &options)
    : Node("gaussian_publisher", options) {
  // Declare parameters
  publish_rate_ = this->declare_parameter<double>("publish_rate", 10.0);
  topic_name_ = this->declare_parameter<std::string>("topic", "gaussians");

  // Create publisher
  publisher_ = this->create_publisher<gaussian_interface::msg::GaussianArray>(
      topic_name_, rclcpp::QoS(10));

  // Set up timer
  timer_ = this->create_wall_timer(
      std::chrono::duration<double>(1.0 / publish_rate_),
      std::bind(&GaussianPublisher::publishGaussians, this));
}

void GaussianPublisher::publishGaussians() {
  auto msg = gaussian_interface::msg::GaussianArray();

  // Example: publish two dummy Gaussians every tick
  for (int i = 0; i < 2; ++i) {
    gaussian_interface::msg::SingleGaussian g;

    // Position
    g.xyz.x = 1.0 * i;
    g.xyz.y = 2.0 * i;
    g.xyz.z = 0.5 * i;

    // Orientation (identity)
    g.rotation.x = 0.0;
    g.rotation.y = 0.0;
    g.rotation.z = 0.0;
    g.rotation.w = 1.0;

    // Scale
    g.scale.x = 0.1 * (i + 1);
    g.scale.y = 0.2 * (i + 1);
    g.scale.z = 0.3 * (i + 1);

    // Opacity
    g.opacity = 0.8f - 0.2f * i;

    // Spherical harmonics (example data)
    g.spherical_harmonics = {0.1f * i, 0.2f * i, 0.3f * i, 0.4f * i};

    msg.gaussians.push_back(std::move(g));
  }

  publisher_->publish(std::move(msg));
}

} // namespace gaussian_publisher

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(gaussian_publisher::GaussianPublisher)
