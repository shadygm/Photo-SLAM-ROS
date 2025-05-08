// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gaussian_interface:msg/SingleGaussian.idl
// generated code does not contain a copyright notice

#ifndef GAUSSIAN_INTERFACE__MSG__DETAIL__SINGLE_GAUSSIAN__BUILDER_HPP_
#define GAUSSIAN_INTERFACE__MSG__DETAIL__SINGLE_GAUSSIAN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gaussian_interface/msg/detail/single_gaussian__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gaussian_interface
{

namespace msg
{

namespace builder
{

class Init_SingleGaussian_spherical_harmonics
{
public:
  explicit Init_SingleGaussian_spherical_harmonics(::gaussian_interface::msg::SingleGaussian & msg)
  : msg_(msg)
  {}
  ::gaussian_interface::msg::SingleGaussian spherical_harmonics(::gaussian_interface::msg::SingleGaussian::_spherical_harmonics_type arg)
  {
    msg_.spherical_harmonics = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gaussian_interface::msg::SingleGaussian msg_;
};

class Init_SingleGaussian_opacity
{
public:
  explicit Init_SingleGaussian_opacity(::gaussian_interface::msg::SingleGaussian & msg)
  : msg_(msg)
  {}
  Init_SingleGaussian_spherical_harmonics opacity(::gaussian_interface::msg::SingleGaussian::_opacity_type arg)
  {
    msg_.opacity = std::move(arg);
    return Init_SingleGaussian_spherical_harmonics(msg_);
  }

private:
  ::gaussian_interface::msg::SingleGaussian msg_;
};

class Init_SingleGaussian_scale
{
public:
  explicit Init_SingleGaussian_scale(::gaussian_interface::msg::SingleGaussian & msg)
  : msg_(msg)
  {}
  Init_SingleGaussian_opacity scale(::gaussian_interface::msg::SingleGaussian::_scale_type arg)
  {
    msg_.scale = std::move(arg);
    return Init_SingleGaussian_opacity(msg_);
  }

private:
  ::gaussian_interface::msg::SingleGaussian msg_;
};

class Init_SingleGaussian_rotation
{
public:
  explicit Init_SingleGaussian_rotation(::gaussian_interface::msg::SingleGaussian & msg)
  : msg_(msg)
  {}
  Init_SingleGaussian_scale rotation(::gaussian_interface::msg::SingleGaussian::_rotation_type arg)
  {
    msg_.rotation = std::move(arg);
    return Init_SingleGaussian_scale(msg_);
  }

private:
  ::gaussian_interface::msg::SingleGaussian msg_;
};

class Init_SingleGaussian_xyz
{
public:
  Init_SingleGaussian_xyz()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SingleGaussian_rotation xyz(::gaussian_interface::msg::SingleGaussian::_xyz_type arg)
  {
    msg_.xyz = std::move(arg);
    return Init_SingleGaussian_rotation(msg_);
  }

private:
  ::gaussian_interface::msg::SingleGaussian msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gaussian_interface::msg::SingleGaussian>()
{
  return gaussian_interface::msg::builder::Init_SingleGaussian_xyz();
}

}  // namespace gaussian_interface

#endif  // GAUSSIAN_INTERFACE__MSG__DETAIL__SINGLE_GAUSSIAN__BUILDER_HPP_
