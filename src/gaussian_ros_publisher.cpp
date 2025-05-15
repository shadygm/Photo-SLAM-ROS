#include "include/gaussian_ros_publisher.h"
#include "rclcpp_components/register_node_macro.hpp"
#include <sstream> 


GaussianPublisher::GaussianPublisher(const rclcpp::NodeOptions &options)
    : Node("gaussian_publisher", options) {
      topic_name_ = this->declare_parameter<std::string>("topic", "gaussians");

  image_publisher_ = this->create_publisher<sensor_msgs::msg::Image>(
      "gaussian_image", rclcpp::QoS(10));

  gaussian_publisher_ = this->create_publisher<gaussian_interface::msg::GaussianArray>(
      "gaussian_model", rclcpp::QoS(10));

}

GaussianPublisher::~GaussianPublisher() {
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
  // 1) grab everything on CPU, contiguous
  auto xyz     = gaussians->getXYZ()                .to(torch::kCPU).contiguous(); // [N,3]
  auto rot     = gaussians->getRotationActivation() .to(torch::kCPU).contiguous(); // [N,4]
  auto scale   = gaussians->getScalingActivation()  .to(torch::kCPU).contiguous(); // [N,3]
  auto opacity = gaussians->getOpacityActivation()  .to(torch::kCPU).contiguous(); // [N,1]
  auto sh      = gaussians->getFeatures()           .to(torch::kCPU).contiguous(); // [N,16,3]

  const int64_t N = xyz.size(0);
  const int64_t C = sh.size(1);
  const int64_t K = sh.size(2);

  gaussian_interface::msg::GaussianArray msg;
  msg.gaussians.reserve(N);

  for (int64_t i = 0; i < N; ++i) {
    gaussian_interface::msg::SingleGaussian sg;

    // fill position
    sg.xyz.x = xyz[i][0].item<float>();
    sg.xyz.y = xyz[i][1].item<float>();
    sg.xyz.z = xyz[i][2].item<float>();

    // fill quaternion
    sg.rotation.x = rot[i][0].item<float>();
    sg.rotation.y = rot[i][1].item<float>();
    sg.rotation.z = rot[i][2].item<float>();
    sg.rotation.w = rot[i][3].item<float>();

    // fill scale
    sg.scale.x = scale[i][0].item<float>();
    sg.scale.y = scale[i][1].item<float>();
    sg.scale.z = scale[i][2].item<float>();

    // fill opacity (extract scalar from [1]-dim tensor)
    sg.opacity = opacity[i][0].item<float>();

    // flatten [C, K] into C*K floats
    auto sh_ik = sh[i].view({C * K});  
    sg.spherical_harmonics.reserve(C * K);
    for (int64_t idx = 0; idx < C * K; ++idx) {
      sg.spherical_harmonics.push_back(sh_ik[idx].item<float>());
    }

    msg.gaussians.push_back(std::move(sg));
  }
  gaussian_publisher_->publish(std::move(msg));
}