// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gaussian_interface:msg/GaussianArray.idl
// generated code does not contain a copyright notice

#ifndef GAUSSIAN_INTERFACE__MSG__DETAIL__GAUSSIAN_ARRAY__STRUCT_HPP_
#define GAUSSIAN_INTERFACE__MSG__DETAIL__GAUSSIAN_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'gaussians'
#include "gaussian_interface/msg/detail/single_gaussian__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__gaussian_interface__msg__GaussianArray __attribute__((deprecated))
#else
# define DEPRECATED__gaussian_interface__msg__GaussianArray __declspec(deprecated)
#endif

namespace gaussian_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GaussianArray_
{
  using Type = GaussianArray_<ContainerAllocator>;

  explicit GaussianArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit GaussianArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _gaussians_type =
    std::vector<gaussian_interface::msg::SingleGaussian_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<gaussian_interface::msg::SingleGaussian_<ContainerAllocator>>>;
  _gaussians_type gaussians;

  // setters for named parameter idiom
  Type & set__gaussians(
    const std::vector<gaussian_interface::msg::SingleGaussian_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<gaussian_interface::msg::SingleGaussian_<ContainerAllocator>>> & _arg)
  {
    this->gaussians = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gaussian_interface::msg::GaussianArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const gaussian_interface::msg::GaussianArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gaussian_interface::msg::GaussianArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gaussian_interface::msg::GaussianArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gaussian_interface::msg::GaussianArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gaussian_interface::msg::GaussianArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gaussian_interface::msg::GaussianArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gaussian_interface::msg::GaussianArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gaussian_interface::msg::GaussianArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gaussian_interface::msg::GaussianArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gaussian_interface__msg__GaussianArray
    std::shared_ptr<gaussian_interface::msg::GaussianArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gaussian_interface__msg__GaussianArray
    std::shared_ptr<gaussian_interface::msg::GaussianArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GaussianArray_ & other) const
  {
    if (this->gaussians != other.gaussians) {
      return false;
    }
    return true;
  }
  bool operator!=(const GaussianArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GaussianArray_

// alias to use template instance with default allocator
using GaussianArray =
  gaussian_interface::msg::GaussianArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gaussian_interface

#endif  // GAUSSIAN_INTERFACE__MSG__DETAIL__GAUSSIAN_ARRAY__STRUCT_HPP_
