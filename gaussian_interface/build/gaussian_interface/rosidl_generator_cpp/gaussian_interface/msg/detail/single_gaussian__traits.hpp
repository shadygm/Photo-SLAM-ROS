// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gaussian_interface:msg/SingleGaussian.idl
// generated code does not contain a copyright notice

#ifndef GAUSSIAN_INTERFACE__MSG__DETAIL__SINGLE_GAUSSIAN__TRAITS_HPP_
#define GAUSSIAN_INTERFACE__MSG__DETAIL__SINGLE_GAUSSIAN__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gaussian_interface/msg/detail/single_gaussian__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'xyz'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'rotation'
#include "geometry_msgs/msg/detail/quaternion__traits.hpp"
// Member 'scale'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace gaussian_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const SingleGaussian & msg,
  std::ostream & out)
{
  out << "{";
  // member: xyz
  {
    out << "xyz: ";
    to_flow_style_yaml(msg.xyz, out);
    out << ", ";
  }

  // member: rotation
  {
    out << "rotation: ";
    to_flow_style_yaml(msg.rotation, out);
    out << ", ";
  }

  // member: scale
  {
    out << "scale: ";
    to_flow_style_yaml(msg.scale, out);
    out << ", ";
  }

  // member: opacity
  {
    out << "opacity: ";
    rosidl_generator_traits::value_to_yaml(msg.opacity, out);
    out << ", ";
  }

  // member: spherical_harmonics
  {
    if (msg.spherical_harmonics.size() == 0) {
      out << "spherical_harmonics: []";
    } else {
      out << "spherical_harmonics: [";
      size_t pending_items = msg.spherical_harmonics.size();
      for (auto item : msg.spherical_harmonics) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const SingleGaussian & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: xyz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "xyz:\n";
    to_block_style_yaml(msg.xyz, out, indentation + 2);
  }

  // member: rotation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rotation:\n";
    to_block_style_yaml(msg.rotation, out, indentation + 2);
  }

  // member: scale
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "scale:\n";
    to_block_style_yaml(msg.scale, out, indentation + 2);
  }

  // member: opacity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "opacity: ";
    rosidl_generator_traits::value_to_yaml(msg.opacity, out);
    out << "\n";
  }

  // member: spherical_harmonics
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.spherical_harmonics.size() == 0) {
      out << "spherical_harmonics: []\n";
    } else {
      out << "spherical_harmonics:\n";
      for (auto item : msg.spherical_harmonics) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SingleGaussian & msg, bool use_flow_style = false)
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
  const gaussian_interface::msg::SingleGaussian & msg,
  std::ostream & out, size_t indentation = 0)
{
  gaussian_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gaussian_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const gaussian_interface::msg::SingleGaussian & msg)
{
  return gaussian_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<gaussian_interface::msg::SingleGaussian>()
{
  return "gaussian_interface::msg::SingleGaussian";
}

template<>
inline const char * name<gaussian_interface::msg::SingleGaussian>()
{
  return "gaussian_interface/msg/SingleGaussian";
}

template<>
struct has_fixed_size<gaussian_interface::msg::SingleGaussian>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<gaussian_interface::msg::SingleGaussian>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<gaussian_interface::msg::SingleGaussian>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GAUSSIAN_INTERFACE__MSG__DETAIL__SINGLE_GAUSSIAN__TRAITS_HPP_
