// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gaussian_interface:msg/SingleGaussian.idl
// generated code does not contain a copyright notice
#include "gaussian_interface/msg/detail/single_gaussian__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `xyz`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `rotation`
#include "geometry_msgs/msg/detail/quaternion__functions.h"
// Member `scale`
#include "geometry_msgs/msg/detail/vector3__functions.h"
// Member `spherical_harmonics`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
gaussian_interface__msg__SingleGaussian__init(gaussian_interface__msg__SingleGaussian * msg)
{
  if (!msg) {
    return false;
  }
  // xyz
  if (!geometry_msgs__msg__Point__init(&msg->xyz)) {
    gaussian_interface__msg__SingleGaussian__fini(msg);
    return false;
  }
  // rotation
  if (!geometry_msgs__msg__Quaternion__init(&msg->rotation)) {
    gaussian_interface__msg__SingleGaussian__fini(msg);
    return false;
  }
  // scale
  if (!geometry_msgs__msg__Vector3__init(&msg->scale)) {
    gaussian_interface__msg__SingleGaussian__fini(msg);
    return false;
  }
  // opacity
  // spherical_harmonics
  if (!rosidl_runtime_c__float__Sequence__init(&msg->spherical_harmonics, 0)) {
    gaussian_interface__msg__SingleGaussian__fini(msg);
    return false;
  }
  return true;
}

void
gaussian_interface__msg__SingleGaussian__fini(gaussian_interface__msg__SingleGaussian * msg)
{
  if (!msg) {
    return;
  }
  // xyz
  geometry_msgs__msg__Point__fini(&msg->xyz);
  // rotation
  geometry_msgs__msg__Quaternion__fini(&msg->rotation);
  // scale
  geometry_msgs__msg__Vector3__fini(&msg->scale);
  // opacity
  // spherical_harmonics
  rosidl_runtime_c__float__Sequence__fini(&msg->spherical_harmonics);
}

bool
gaussian_interface__msg__SingleGaussian__are_equal(const gaussian_interface__msg__SingleGaussian * lhs, const gaussian_interface__msg__SingleGaussian * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // xyz
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->xyz), &(rhs->xyz)))
  {
    return false;
  }
  // rotation
  if (!geometry_msgs__msg__Quaternion__are_equal(
      &(lhs->rotation), &(rhs->rotation)))
  {
    return false;
  }
  // scale
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->scale), &(rhs->scale)))
  {
    return false;
  }
  // opacity
  if (lhs->opacity != rhs->opacity) {
    return false;
  }
  // spherical_harmonics
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->spherical_harmonics), &(rhs->spherical_harmonics)))
  {
    return false;
  }
  return true;
}

bool
gaussian_interface__msg__SingleGaussian__copy(
  const gaussian_interface__msg__SingleGaussian * input,
  gaussian_interface__msg__SingleGaussian * output)
{
  if (!input || !output) {
    return false;
  }
  // xyz
  if (!geometry_msgs__msg__Point__copy(
      &(input->xyz), &(output->xyz)))
  {
    return false;
  }
  // rotation
  if (!geometry_msgs__msg__Quaternion__copy(
      &(input->rotation), &(output->rotation)))
  {
    return false;
  }
  // scale
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->scale), &(output->scale)))
  {
    return false;
  }
  // opacity
  output->opacity = input->opacity;
  // spherical_harmonics
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->spherical_harmonics), &(output->spherical_harmonics)))
  {
    return false;
  }
  return true;
}

gaussian_interface__msg__SingleGaussian *
gaussian_interface__msg__SingleGaussian__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gaussian_interface__msg__SingleGaussian * msg = (gaussian_interface__msg__SingleGaussian *)allocator.allocate(sizeof(gaussian_interface__msg__SingleGaussian), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gaussian_interface__msg__SingleGaussian));
  bool success = gaussian_interface__msg__SingleGaussian__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gaussian_interface__msg__SingleGaussian__destroy(gaussian_interface__msg__SingleGaussian * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gaussian_interface__msg__SingleGaussian__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gaussian_interface__msg__SingleGaussian__Sequence__init(gaussian_interface__msg__SingleGaussian__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gaussian_interface__msg__SingleGaussian * data = NULL;

  if (size) {
    data = (gaussian_interface__msg__SingleGaussian *)allocator.zero_allocate(size, sizeof(gaussian_interface__msg__SingleGaussian), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gaussian_interface__msg__SingleGaussian__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gaussian_interface__msg__SingleGaussian__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
gaussian_interface__msg__SingleGaussian__Sequence__fini(gaussian_interface__msg__SingleGaussian__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      gaussian_interface__msg__SingleGaussian__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

gaussian_interface__msg__SingleGaussian__Sequence *
gaussian_interface__msg__SingleGaussian__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gaussian_interface__msg__SingleGaussian__Sequence * array = (gaussian_interface__msg__SingleGaussian__Sequence *)allocator.allocate(sizeof(gaussian_interface__msg__SingleGaussian__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gaussian_interface__msg__SingleGaussian__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gaussian_interface__msg__SingleGaussian__Sequence__destroy(gaussian_interface__msg__SingleGaussian__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gaussian_interface__msg__SingleGaussian__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gaussian_interface__msg__SingleGaussian__Sequence__are_equal(const gaussian_interface__msg__SingleGaussian__Sequence * lhs, const gaussian_interface__msg__SingleGaussian__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gaussian_interface__msg__SingleGaussian__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gaussian_interface__msg__SingleGaussian__Sequence__copy(
  const gaussian_interface__msg__SingleGaussian__Sequence * input,
  gaussian_interface__msg__SingleGaussian__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gaussian_interface__msg__SingleGaussian);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gaussian_interface__msg__SingleGaussian * data =
      (gaussian_interface__msg__SingleGaussian *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gaussian_interface__msg__SingleGaussian__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gaussian_interface__msg__SingleGaussian__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gaussian_interface__msg__SingleGaussian__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
