// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gaussian_interface:msg/SingleGaussian.idl
// generated code does not contain a copyright notice

#ifndef GAUSSIAN_INTERFACE__MSG__DETAIL__SINGLE_GAUSSIAN__STRUCT_H_
#define GAUSSIAN_INTERFACE__MSG__DETAIL__SINGLE_GAUSSIAN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'xyz'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'rotation'
#include "geometry_msgs/msg/detail/quaternion__struct.h"
// Member 'scale'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'spherical_harmonics'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/SingleGaussian in the package gaussian_interface.
/**
  * Gaussian.msg
 */
typedef struct gaussian_interface__msg__SingleGaussian
{
  /// 3D Pose
  geometry_msgs__msg__Point xyz;
  /// Rotation as Quaternion
  geometry_msgs__msg__Quaternion rotation;
  /// Scale along each axis
  geometry_msgs__msg__Vector3 scale;
  /// Opacity
  float opacity;
  /// Spherical Harmonics
  rosidl_runtime_c__float__Sequence spherical_harmonics;
} gaussian_interface__msg__SingleGaussian;

// Struct for a sequence of gaussian_interface__msg__SingleGaussian.
typedef struct gaussian_interface__msg__SingleGaussian__Sequence
{
  gaussian_interface__msg__SingleGaussian * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gaussian_interface__msg__SingleGaussian__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GAUSSIAN_INTERFACE__MSG__DETAIL__SINGLE_GAUSSIAN__STRUCT_H_
