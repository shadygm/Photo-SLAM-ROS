// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gaussian_interface:msg/SingleGaussian.idl
// generated code does not contain a copyright notice

#ifndef GAUSSIAN_INTERFACE__MSG__DETAIL__SINGLE_GAUSSIAN__STRUCT_HPP_
#define GAUSSIAN_INTERFACE__MSG__DETAIL__SINGLE_GAUSSIAN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'xyz'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'rotation'
#include "geometry_msgs/msg/detail/quaternion__struct.hpp"
// Member 'scale'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__gaussian_interface__msg__SingleGaussian __attribute__((deprecated))
#else
# define DEPRECATED__gaussian_interface__msg__SingleGaussian __declspec(deprecated)
#endif

namespace gaussian_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SingleGaussian_
{
  using Type = SingleGaussian_<ContainerAllocator>;

  explicit SingleGaussian_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : xyz(_init),
    rotation(_init),
    scale(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->opacity = 0.0f;
    }
  }

  explicit SingleGaussian_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : xyz(_alloc, _init),
    rotation(_alloc, _init),
    scale(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->opacity = 0.0f;
    }
  }

  // field types and members
  using _xyz_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _xyz_type xyz;
  using _rotation_type =
    geometry_msgs::msg::Quaternion_<ContainerAllocator>;
  _rotation_type rotation;
  using _scale_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _scale_type scale;
  using _opacity_type =
    float;
  _opacity_type opacity;
  using _spherical_harmonics_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _spherical_harmonics_type spherical_harmonics;

  // setters for named parameter idiom
  Type & set__xyz(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->xyz = _arg;
    return *this;
  }
  Type & set__rotation(
    const geometry_msgs::msg::Quaternion_<ContainerAllocator> & _arg)
  {
    this->rotation = _arg;
    return *this;
  }
  Type & set__scale(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->scale = _arg;
    return *this;
  }
  Type & set__opacity(
    const float & _arg)
  {
    this->opacity = _arg;
    return *this;
  }
  Type & set__spherical_harmonics(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->spherical_harmonics = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gaussian_interface::msg::SingleGaussian_<ContainerAllocator> *;
  using ConstRawPtr =
    const gaussian_interface::msg::SingleGaussian_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gaussian_interface::msg::SingleGaussian_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gaussian_interface::msg::SingleGaussian_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gaussian_interface::msg::SingleGaussian_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gaussian_interface::msg::SingleGaussian_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gaussian_interface::msg::SingleGaussian_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gaussian_interface::msg::SingleGaussian_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gaussian_interface::msg::SingleGaussian_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gaussian_interface::msg::SingleGaussian_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gaussian_interface__msg__SingleGaussian
    std::shared_ptr<gaussian_interface::msg::SingleGaussian_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gaussian_interface__msg__SingleGaussian
    std::shared_ptr<gaussian_interface::msg::SingleGaussian_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SingleGaussian_ & other) const
  {
    if (this->xyz != other.xyz) {
      return false;
    }
    if (this->rotation != other.rotation) {
      return false;
    }
    if (this->scale != other.scale) {
      return false;
    }
    if (this->opacity != other.opacity) {
      return false;
    }
    if (this->spherical_harmonics != other.spherical_harmonics) {
      return false;
    }
    return true;
  }
  bool operator!=(const SingleGaussian_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SingleGaussian_

// alias to use template instance with default allocator
using SingleGaussian =
  gaussian_interface::msg::SingleGaussian_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gaussian_interface

#endif  // GAUSSIAN_INTERFACE__MSG__DETAIL__SINGLE_GAUSSIAN__STRUCT_HPP_
