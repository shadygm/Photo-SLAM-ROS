// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gaussian_interface:msg/GaussianArray.idl
// generated code does not contain a copyright notice

#ifndef GAUSSIAN_INTERFACE__MSG__DETAIL__GAUSSIAN_ARRAY__STRUCT_H_
#define GAUSSIAN_INTERFACE__MSG__DETAIL__GAUSSIAN_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'gaussians'
#include "gaussian_interface/msg/detail/single_gaussian__struct.h"

/// Struct defined in msg/GaussianArray in the package gaussian_interface.
/**
  * GaussianArray.msg
 */
typedef struct gaussian_interface__msg__GaussianArray
{
  /// Array of Single Gaussian messages
  gaussian_interface__msg__SingleGaussian__Sequence gaussians;
} gaussian_interface__msg__GaussianArray;

// Struct for a sequence of gaussian_interface__msg__GaussianArray.
typedef struct gaussian_interface__msg__GaussianArray__Sequence
{
  gaussian_interface__msg__GaussianArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gaussian_interface__msg__GaussianArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GAUSSIAN_INTERFACE__MSG__DETAIL__GAUSSIAN_ARRAY__STRUCT_H_
