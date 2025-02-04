// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from z1_interfaces:msg/ArmControlCommand.idl
// generated code does not contain a copyright notice

#ifndef Z1_INTERFACES__MSG__DETAIL__ARM_CONTROL_COMMAND__FUNCTIONS_H_
#define Z1_INTERFACES__MSG__DETAIL__ARM_CONTROL_COMMAND__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "z1_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "z1_interfaces/msg/detail/arm_control_command__struct.h"

/// Initialize msg/ArmControlCommand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * z1_interfaces__msg__ArmControlCommand
 * )) before or use
 * z1_interfaces__msg__ArmControlCommand__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
bool
z1_interfaces__msg__ArmControlCommand__init(z1_interfaces__msg__ArmControlCommand * msg);

/// Finalize msg/ArmControlCommand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
void
z1_interfaces__msg__ArmControlCommand__fini(z1_interfaces__msg__ArmControlCommand * msg);

/// Create msg/ArmControlCommand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * z1_interfaces__msg__ArmControlCommand__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
z1_interfaces__msg__ArmControlCommand *
z1_interfaces__msg__ArmControlCommand__create();

/// Destroy msg/ArmControlCommand message.
/**
 * It calls
 * z1_interfaces__msg__ArmControlCommand__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
void
z1_interfaces__msg__ArmControlCommand__destroy(z1_interfaces__msg__ArmControlCommand * msg);

/// Check for msg/ArmControlCommand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
bool
z1_interfaces__msg__ArmControlCommand__are_equal(const z1_interfaces__msg__ArmControlCommand * lhs, const z1_interfaces__msg__ArmControlCommand * rhs);

/// Copy a msg/ArmControlCommand message.
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
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
bool
z1_interfaces__msg__ArmControlCommand__copy(
  const z1_interfaces__msg__ArmControlCommand * input,
  z1_interfaces__msg__ArmControlCommand * output);

/// Initialize array of msg/ArmControlCommand messages.
/**
 * It allocates the memory for the number of elements and calls
 * z1_interfaces__msg__ArmControlCommand__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
bool
z1_interfaces__msg__ArmControlCommand__Sequence__init(z1_interfaces__msg__ArmControlCommand__Sequence * array, size_t size);

/// Finalize array of msg/ArmControlCommand messages.
/**
 * It calls
 * z1_interfaces__msg__ArmControlCommand__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
void
z1_interfaces__msg__ArmControlCommand__Sequence__fini(z1_interfaces__msg__ArmControlCommand__Sequence * array);

/// Create array of msg/ArmControlCommand messages.
/**
 * It allocates the memory for the array and calls
 * z1_interfaces__msg__ArmControlCommand__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
z1_interfaces__msg__ArmControlCommand__Sequence *
z1_interfaces__msg__ArmControlCommand__Sequence__create(size_t size);

/// Destroy array of msg/ArmControlCommand messages.
/**
 * It calls
 * z1_interfaces__msg__ArmControlCommand__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
void
z1_interfaces__msg__ArmControlCommand__Sequence__destroy(z1_interfaces__msg__ArmControlCommand__Sequence * array);

/// Check for msg/ArmControlCommand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
bool
z1_interfaces__msg__ArmControlCommand__Sequence__are_equal(const z1_interfaces__msg__ArmControlCommand__Sequence * lhs, const z1_interfaces__msg__ArmControlCommand__Sequence * rhs);

/// Copy an array of msg/ArmControlCommand messages.
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
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
bool
z1_interfaces__msg__ArmControlCommand__Sequence__copy(
  const z1_interfaces__msg__ArmControlCommand__Sequence * input,
  z1_interfaces__msg__ArmControlCommand__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // Z1_INTERFACES__MSG__DETAIL__ARM_CONTROL_COMMAND__FUNCTIONS_H_
