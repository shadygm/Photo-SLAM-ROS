// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gaussian_interface:msg/GaussianArray.idl
// generated code does not contain a copyright notice

#ifndef GAUSSIAN_INTERFACE__MSG__DETAIL__GAUSSIAN_ARRAY__BUILDER_HPP_
#define GAUSSIAN_INTERFACE__MSG__DETAIL__GAUSSIAN_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gaussian_interface/msg/detail/gaussian_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gaussian_interface
{

namespace msg
{

namespace builder
{

class Init_GaussianArray_gaussians
{
public:
  Init_GaussianArray_gaussians()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gaussian_interface::msg::GaussianArray gaussians(::gaussian_interface::msg::GaussianArray::_gaussians_type arg)
  {
    msg_.gaussians = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gaussian_interface::msg::GaussianArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gaussian_interface::msg::GaussianArray>()
{
  return gaussian_interface::msg::builder::Init_GaussianArray_gaussians();
}

}  // namespace gaussian_interface

#endif  // GAUSSIAN_INTERFACE__MSG__DETAIL__GAUSSIAN_ARRAY__BUILDER_HPP_
