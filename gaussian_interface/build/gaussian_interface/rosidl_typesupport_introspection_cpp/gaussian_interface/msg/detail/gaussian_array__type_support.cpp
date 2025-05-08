// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from gaussian_interface:msg/GaussianArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "gaussian_interface/msg/detail/gaussian_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace gaussian_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void GaussianArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) gaussian_interface::msg::GaussianArray(_init);
}

void GaussianArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<gaussian_interface::msg::GaussianArray *>(message_memory);
  typed_message->~GaussianArray();
}

size_t size_function__GaussianArray__gaussians(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<gaussian_interface::msg::SingleGaussian> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GaussianArray__gaussians(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<gaussian_interface::msg::SingleGaussian> *>(untyped_member);
  return &member[index];
}

void * get_function__GaussianArray__gaussians(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<gaussian_interface::msg::SingleGaussian> *>(untyped_member);
  return &member[index];
}

void fetch_function__GaussianArray__gaussians(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const gaussian_interface::msg::SingleGaussian *>(
    get_const_function__GaussianArray__gaussians(untyped_member, index));
  auto & value = *reinterpret_cast<gaussian_interface::msg::SingleGaussian *>(untyped_value);
  value = item;
}

void assign_function__GaussianArray__gaussians(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<gaussian_interface::msg::SingleGaussian *>(
    get_function__GaussianArray__gaussians(untyped_member, index));
  const auto & value = *reinterpret_cast<const gaussian_interface::msg::SingleGaussian *>(untyped_value);
  item = value;
}

void resize_function__GaussianArray__gaussians(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<gaussian_interface::msg::SingleGaussian> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GaussianArray_message_member_array[1] = {
  {
    "gaussians",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<gaussian_interface::msg::SingleGaussian>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gaussian_interface::msg::GaussianArray, gaussians),  // bytes offset in struct
    nullptr,  // default value
    size_function__GaussianArray__gaussians,  // size() function pointer
    get_const_function__GaussianArray__gaussians,  // get_const(index) function pointer
    get_function__GaussianArray__gaussians,  // get(index) function pointer
    fetch_function__GaussianArray__gaussians,  // fetch(index, &value) function pointer
    assign_function__GaussianArray__gaussians,  // assign(index, value) function pointer
    resize_function__GaussianArray__gaussians  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GaussianArray_message_members = {
  "gaussian_interface::msg",  // message namespace
  "GaussianArray",  // message name
  1,  // number of fields
  sizeof(gaussian_interface::msg::GaussianArray),
  GaussianArray_message_member_array,  // message members
  GaussianArray_init_function,  // function to initialize message memory (memory has to be allocated)
  GaussianArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GaussianArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GaussianArray_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace gaussian_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<gaussian_interface::msg::GaussianArray>()
{
  return &::gaussian_interface::msg::rosidl_typesupport_introspection_cpp::GaussianArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, gaussian_interface, msg, GaussianArray)() {
  return &::gaussian_interface::msg::rosidl_typesupport_introspection_cpp::GaussianArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
