// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from gaussian_interface:msg/GaussianArray.idl
// generated code does not contain a copyright notice

#ifndef GAUSSIAN_INTERFACE__MSG__DETAIL__GAUSSIAN_ARRAY__FUNCTIONS_H_
#define GAUSSIAN_INTERFACE__MSG__DETAIL__GAUSSIAN_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "gaussian_interface/msg/rosidl_generator_c__visibility_control.h"

#include "gaussian_interface/msg/detail/gaussian_array__struct.h"

/// Initialize msg/GaussianArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gaussian_interface__msg__GaussianArray
 * )) before or use
 * gaussian_interface__msg__GaussianArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gaussian_interface
bool
gaussian_interface__msg__GaussianArray__init(gaussian_interface__msg__GaussianArray * msg);

/// Finalize msg/GaussianArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gaussian_interface
void
gaussian_interface__msg__GaussianArray__fini(gaussian_interface__msg__GaussianArray * msg);

/// Create msg/GaussianArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gaussian_interface__msg__GaussianArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gaussian_interface
gaussian_interface__msg__GaussianArray *
gaussian_interface__msg__GaussianArray__create();

/// Destroy msg/GaussianArray message.
/**
 * It calls
 * gaussian_interface__msg__GaussianArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gaussian_interface
void
gaussian_interface__msg__GaussianArray__destroy(gaussian_interface__msg__GaussianArray * msg);

/// Check for msg/GaussianArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gaussian_interface
bool
gaussian_interface__msg__GaussianArray__are_equal(const gaussian_interface__msg__GaussianArray * lhs, const gaussian_interface__msg__GaussianArray * rhs);

/// Copy a msg/GaussianArray message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_gaussian_interface
bool
gaussian_interface__msg__GaussianArray__copy(
  const gaussian_interface__msg__GaussianArray * input,
  gaussian_interface__msg__GaussianArray * output);

/// Initialize array of msg/GaussianArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * gaussian_interface__msg__GaussianArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gaussian_interface
bool
gaussian_interface__msg__GaussianArray__Sequence__init(gaussian_interface__msg__GaussianArray__Sequence * array, size_t size);

/// Finalize array of msg/GaussianArray messages.
/**
 * It calls
 * gaussian_interface__msg__GaussianArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gaussian_interface
void
gaussian_interface__msg__GaussianArray__Sequence__fini(gaussian_interface__msg__GaussianArray__Sequence * array);

/// Create array of msg/GaussianArray messages.
/**
 * It allocates the memory for the array and calls
 * gaussian_interface__msg__GaussianArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gaussian_interface
gaussian_interface__msg__GaussianArray__Sequence *
gaussian_interface__msg__GaussianArray__Sequence__create(size_t size);

/// Destroy array of msg/GaussianArray messages.
/**
 * It calls
 * gaussian_interface__msg__GaussianArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gaussian_interface
void
gaussian_interface__msg__GaussianArray__Sequence__destroy(gaussian_interface__msg__GaussianArray__Sequence * array);

/// Check for msg/GaussianArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gaussian_interface
bool
gaussian_interface__msg__GaussianArray__Sequence__are_equal(const gaussian_interface__msg__GaussianArray__Sequence * lhs, const gaussian_interface__msg__GaussianArray__Sequence * rhs);

/// Copy an array of msg/GaussianArray messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_gaussian_interface
bool
gaussian_interface__msg__GaussianArray__Sequence__copy(
  const gaussian_interface__msg__GaussianArray__Sequence * input,
  gaussian_interface__msg__GaussianArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GAUSSIAN_INTERFACE__MSG__DETAIL__GAUSSIAN_ARRAY__FUNCTIONS_H_
