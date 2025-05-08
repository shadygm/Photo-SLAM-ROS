// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from gaussian_interface:msg/SingleGaussian.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "gaussian_interface/msg/detail/single_gaussian__rosidl_typesupport_introspection_c.h"
#include "gaussian_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "gaussian_interface/msg/detail/single_gaussian__functions.h"
#include "gaussian_interface/msg/detail/single_gaussian__struct.h"


// Include directives for member types
// Member `xyz`
#include "geometry_msgs/msg/point.h"
// Member `xyz`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `rotation`
#include "geometry_msgs/msg/quaternion.h"
// Member `rotation`
#include "geometry_msgs/msg/detail/quaternion__rosidl_typesupport_introspection_c.h"
// Member `scale`
#include "geometry_msgs/msg/vector3.h"
// Member `scale`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"
// Member `spherical_harmonics`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__SingleGaussian_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gaussian_interface__msg__SingleGaussian__init(message_memory);
}

void gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__SingleGaussian_fini_function(void * message_memory)
{
  gaussian_interface__msg__SingleGaussian__fini(message_memory);
}

size_t gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__size_function__SingleGaussian__spherical_harmonics(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__get_const_function__SingleGaussian__spherical_harmonics(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__get_function__SingleGaussian__spherical_harmonics(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__fetch_function__SingleGaussian__spherical_harmonics(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__get_const_function__SingleGaussian__spherical_harmonics(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__assign_function__SingleGaussian__spherical_harmonics(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__get_function__SingleGaussian__spherical_harmonics(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__resize_function__SingleGaussian__spherical_harmonics(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__SingleGaussian_message_member_array[5] = {
  {
    "xyz",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gaussian_interface__msg__SingleGaussian, xyz),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rotation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gaussian_interface__msg__SingleGaussian, rotation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "scale",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gaussian_interface__msg__SingleGaussian, scale),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "opacity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gaussian_interface__msg__SingleGaussian, opacity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "spherical_harmonics",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gaussian_interface__msg__SingleGaussian, spherical_harmonics),  // bytes offset in struct
    NULL,  // default value
    gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__size_function__SingleGaussian__spherical_harmonics,  // size() function pointer
    gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__get_const_function__SingleGaussian__spherical_harmonics,  // get_const(index) function pointer
    gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__get_function__SingleGaussian__spherical_harmonics,  // get(index) function pointer
    gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__fetch_function__SingleGaussian__spherical_harmonics,  // fetch(index, &value) function pointer
    gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__assign_function__SingleGaussian__spherical_harmonics,  // assign(index, value) function pointer
    gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__resize_function__SingleGaussian__spherical_harmonics  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__SingleGaussian_message_members = {
  "gaussian_interface__msg",  // message namespace
  "SingleGaussian",  // message name
  5,  // number of fields
  sizeof(gaussian_interface__msg__SingleGaussian),
  gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__SingleGaussian_message_member_array,  // message members
  gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__SingleGaussian_init_function,  // function to initialize message memory (memory has to be allocated)
  gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__SingleGaussian_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__SingleGaussian_message_type_support_handle = {
  0,
  &gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__SingleGaussian_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gaussian_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gaussian_interface, msg, SingleGaussian)() {
  gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__SingleGaussian_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__SingleGaussian_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Quaternion)();
  gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__SingleGaussian_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__SingleGaussian_message_type_support_handle.typesupport_identifier) {
    gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__SingleGaussian_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &gaussian_interface__msg__SingleGaussian__rosidl_typesupport_introspection_c__SingleGaussian_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
