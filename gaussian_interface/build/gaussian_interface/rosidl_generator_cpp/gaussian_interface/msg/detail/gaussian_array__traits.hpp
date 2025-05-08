// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gaussian_interface:msg/GaussianArray.idl
// generated code does not contain a copyright notice

#ifndef GAUSSIAN_INTERFACE__MSG__DETAIL__GAUSSIAN_ARRAY__TRAITS_HPP_
#define GAUSSIAN_INTERFACE__MSG__DETAIL__GAUSSIAN_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gaussian_interface/msg/detail/gaussian_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'gaussians'
#include "gaussian_interface/msg/detail/single_gaussian__traits.hpp"

namespace gaussian_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const GaussianArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: gaussians
  {
    if (msg.gaussians.size() == 0) {
      out << "gaussians: []";
    } else {
      out << "gaussians: [";
      size_t pending_items = msg.gaussians.size();
      for (auto item : msg.gaussians) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GaussianArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: gaussians
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.gaussians.size() == 0) {
      out << "gaussians: []\n";
    } else {
      out << "gaussians:\n";
      for (auto item : msg.gaussians) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GaussianArray & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace gaussian_interface

namespace rosidl_generator_traits
{

[[deprecated("use gaussian_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gaussian_interface::msg::GaussianArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  gaussian_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gaussian_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const gaussian_interface::msg::GaussianArray & msg)
{
  return gaussian_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<gaussian_interface::msg::GaussianArray>()
{
  return "gaussian_interface::msg::GaussianArray";
}

template<>
inline const char * name<gaussian_interface::msg::GaussianArray>()
{
  return "gaussian_interface/msg/GaussianArray";
}

template<>
struct has_fixed_size<gaussian_interface::msg::GaussianArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<gaussian_interface::msg::GaussianArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<gaussian_interface::msg::GaussianArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GAUSSIAN_INTERFACE__MSG__DETAIL__GAUSSIAN_ARRAY__TRAITS_HPP_
