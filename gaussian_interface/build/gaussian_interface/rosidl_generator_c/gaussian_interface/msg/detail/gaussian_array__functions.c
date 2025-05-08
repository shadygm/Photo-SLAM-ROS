// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gaussian_interface:msg/GaussianArray.idl
// generated code does not contain a copyright notice
#include "gaussian_interface/msg/detail/gaussian_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `gaussians`
#include "gaussian_interface/msg/detail/single_gaussian__functions.h"

bool
gaussian_interface__msg__GaussianArray__init(gaussian_interface__msg__GaussianArray * msg)
{
  if (!msg) {
    return false;
  }
  // gaussians
  if (!gaussian_interface__msg__SingleGaussian__Sequence__init(&msg->gaussians, 0)) {
    gaussian_interface__msg__GaussianArray__fini(msg);
    return false;
  }
  return true;
}

void
gaussian_interface__msg__GaussianArray__fini(gaussian_interface__msg__GaussianArray * msg)
{
  if (!msg) {
    return;
  }
  // gaussians
  gaussian_interface__msg__SingleGaussian__Sequence__fini(&msg->gaussians);
}

bool
gaussian_interface__msg__GaussianArray__are_equal(const gaussian_interface__msg__GaussianArray * lhs, const gaussian_interface__msg__GaussianArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // gaussians
  if (!gaussian_interface__msg__SingleGaussian__Sequence__are_equal(
      &(lhs->gaussians), &(rhs->gaussians)))
  {
    return false;
  }
  return true;
}

bool
gaussian_interface__msg__GaussianArray__copy(
  const gaussian_interface__msg__GaussianArray * input,
  gaussian_interface__msg__GaussianArray * output)
{
  if (!input || !output) {
    return false;
  }
  // gaussians
  if (!gaussian_interface__msg__SingleGaussian__Sequence__copy(
      &(input->gaussians), &(output->gaussians)))
  {
    return false;
  }
  return true;
}

gaussian_interface__msg__GaussianArray *
gaussian_interface__msg__GaussianArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gaussian_interface__msg__GaussianArray * msg = (gaussian_interface__msg__GaussianArray *)allocator.allocate(sizeof(gaussian_interface__msg__GaussianArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gaussian_interface__msg__GaussianArray));
  bool success = gaussian_interface__msg__GaussianArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gaussian_interface__msg__GaussianArray__destroy(gaussian_interface__msg__GaussianArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gaussian_interface__msg__GaussianArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gaussian_interface__msg__GaussianArray__Sequence__init(gaussian_interface__msg__GaussianArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gaussian_interface__msg__GaussianArray * data = NULL;

  if (size) {
    data = (gaussian_interface__msg__GaussianArray *)allocator.zero_allocate(size, sizeof(gaussian_interface__msg__GaussianArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gaussian_interface__msg__GaussianArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gaussian_interface__msg__GaussianArray__fini(&data[i - 1]);
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
gaussian_interface__msg__GaussianArray__Sequence__fini(gaussian_interface__msg__GaussianArray__Sequence * array)
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
      gaussian_interface__msg__GaussianArray__fini(&array->data[i]);
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

gaussian_interface__msg__GaussianArray__Sequence *
gaussian_interface__msg__GaussianArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gaussian_interface__msg__GaussianArray__Sequence * array = (gaussian_interface__msg__GaussianArray__Sequence *)allocator.allocate(sizeof(gaussian_interface__msg__GaussianArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gaussian_interface__msg__GaussianArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gaussian_interface__msg__GaussianArray__Sequence__destroy(gaussian_interface__msg__GaussianArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gaussian_interface__msg__GaussianArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gaussian_interface__msg__GaussianArray__Sequence__are_equal(const gaussian_interface__msg__GaussianArray__Sequence * lhs, const gaussian_interface__msg__GaussianArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gaussian_interface__msg__GaussianArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gaussian_interface__msg__GaussianArray__Sequence__copy(
  const gaussian_interface__msg__GaussianArray__Sequence * input,
  gaussian_interface__msg__GaussianArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gaussian_interface__msg__GaussianArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gaussian_interface__msg__GaussianArray * data =
      (gaussian_interface__msg__GaussianArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gaussian_interface__msg__GaussianArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gaussian_interface__msg__GaussianArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gaussian_interface__msg__GaussianArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
