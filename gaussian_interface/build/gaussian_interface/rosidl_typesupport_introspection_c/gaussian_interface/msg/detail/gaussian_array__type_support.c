// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from gaussian_interface:msg/GaussianArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "gaussian_interface/msg/detail/gaussian_array__rosidl_typesupport_introspection_c.h"
#include "gaussian_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "gaussian_interface/msg/detail/gaussian_array__functions.h"
#include "gaussian_interface/msg/detail/gaussian_array__struct.h"


// Include directives for member types
// Member `gaussians`
#include "gaussian_interface/msg/single_gaussian.h"
// Member `gaussians`
#include "gaussian_interface/msg/detail/single_gaussian__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__GaussianArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gaussian_interface__msg__GaussianArray__init(message_memory);
}

void gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__GaussianArray_fini_function(void * message_memory)
{
  gaussian_interface__msg__GaussianArray__fini(message_memory);
}

size_t gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__size_function__GaussianArray__gaussians(
  const void * untyped_member)
{
  const gaussian_interface__msg__SingleGaussian__Sequence * member =
    (const gaussian_interface__msg__SingleGaussian__Sequence *)(untyped_member);
  return member->size;
}

const void * gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__get_const_function__GaussianArray__gaussians(
  const void * untyped_member, size_t index)
{
  const gaussian_interface__msg__SingleGaussian__Sequence * member =
    (const gaussian_interface__msg__SingleGaussian__Sequence *)(untyped_member);
  return &member->data[index];
}

void * gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__get_function__GaussianArray__gaussians(
  void * untyped_member, size_t index)
{
  gaussian_interface__msg__SingleGaussian__Sequence * member =
    (gaussian_interface__msg__SingleGaussian__Sequence *)(untyped_member);
  return &member->data[index];
}

void gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__fetch_function__GaussianArray__gaussians(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const gaussian_interface__msg__SingleGaussian * item =
    ((const gaussian_interface__msg__SingleGaussian *)
    gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__get_const_function__GaussianArray__gaussians(untyped_member, index));
  gaussian_interface__msg__SingleGaussian * value =
    (gaussian_interface__msg__SingleGaussian *)(untyped_value);
  *value = *item;
}

void gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__assign_function__GaussianArray__gaussians(
  void * untyped_member, size_t index, const void * untyped_value)
{
  gaussian_interface__msg__SingleGaussian * item =
    ((gaussian_interface__msg__SingleGaussian *)
    gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__get_function__GaussianArray__gaussians(untyped_member, index));
  const gaussian_interface__msg__SingleGaussian * value =
    (const gaussian_interface__msg__SingleGaussian *)(untyped_value);
  *item = *value;
}

bool gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__resize_function__GaussianArray__gaussians(
  void * untyped_member, size_t size)
{
  gaussian_interface__msg__SingleGaussian__Sequence * member =
    (gaussian_interface__msg__SingleGaussian__Sequence *)(untyped_member);
  gaussian_interface__msg__SingleGaussian__Sequence__fini(member);
  return gaussian_interface__msg__SingleGaussian__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__GaussianArray_message_member_array[1] = {
  {
    "gaussians",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gaussian_interface__msg__GaussianArray, gaussians),  // bytes offset in struct
    NULL,  // default value
    gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__size_function__GaussianArray__gaussians,  // size() function pointer
    gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__get_const_function__GaussianArray__gaussians,  // get_const(index) function pointer
    gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__get_function__GaussianArray__gaussians,  // get(index) function pointer
    gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__fetch_function__GaussianArray__gaussians,  // fetch(index, &value) function pointer
    gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__assign_function__GaussianArray__gaussians,  // assign(index, value) function pointer
    gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__resize_function__GaussianArray__gaussians  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__GaussianArray_message_members = {
  "gaussian_interface__msg",  // message namespace
  "GaussianArray",  // message name
  1,  // number of fields
  sizeof(gaussian_interface__msg__GaussianArray),
  gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__GaussianArray_message_member_array,  // message members
  gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__GaussianArray_init_function,  // function to initialize message memory (memory has to be allocated)
  gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__GaussianArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__GaussianArray_message_type_support_handle = {
  0,
  &gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__GaussianArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gaussian_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gaussian_interface, msg, GaussianArray)() {
  gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__GaussianArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gaussian_interface, msg, SingleGaussian)();
  if (!gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__GaussianArray_message_type_support_handle.typesupport_identifier) {
    gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__GaussianArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &gaussian_interface__msg__GaussianArray__rosidl_typesupport_introspection_c__GaussianArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
