// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from z1_interfaces:srv/MoveJointPathCommand.idl
// generated code does not contain a copyright notice

#ifndef Z1_INTERFACES__SRV__DETAIL__MOVE_JOINT_PATH_COMMAND__FUNCTIONS_H_
#define Z1_INTERFACES__SRV__DETAIL__MOVE_JOINT_PATH_COMMAND__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "z1_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "z1_interfaces/srv/detail/move_joint_path_command__struct.h"

/// Initialize srv/MoveJointPathCommand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * z1_interfaces__srv__MoveJointPathCommand_Request
 * )) before or use
 * z1_interfaces__srv__MoveJointPathCommand_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
bool
z1_interfaces__srv__MoveJointPathCommand_Request__init(z1_interfaces__srv__MoveJointPathCommand_Request * msg);

/// Finalize srv/MoveJointPathCommand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
void
z1_interfaces__srv__MoveJointPathCommand_Request__fini(z1_interfaces__srv__MoveJointPathCommand_Request * msg);

/// Create srv/MoveJointPathCommand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * z1_interfaces__srv__MoveJointPathCommand_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
z1_interfaces__srv__MoveJointPathCommand_Request *
z1_interfaces__srv__MoveJointPathCommand_Request__create();

/// Destroy srv/MoveJointPathCommand message.
/**
 * It calls
 * z1_interfaces__srv__MoveJointPathCommand_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
void
z1_interfaces__srv__MoveJointPathCommand_Request__destroy(z1_interfaces__srv__MoveJointPathCommand_Request * msg);

/// Check for srv/MoveJointPathCommand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
bool
z1_interfaces__srv__MoveJointPathCommand_Request__are_equal(const z1_interfaces__srv__MoveJointPathCommand_Request * lhs, const z1_interfaces__srv__MoveJointPathCommand_Request * rhs);

/// Copy a srv/MoveJointPathCommand message.
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
z1_interfaces__srv__MoveJointPathCommand_Request__copy(
  const z1_interfaces__srv__MoveJointPathCommand_Request * input,
  z1_interfaces__srv__MoveJointPathCommand_Request * output);

/// Initialize array of srv/MoveJointPathCommand messages.
/**
 * It allocates the memory for the number of elements and calls
 * z1_interfaces__srv__MoveJointPathCommand_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
bool
z1_interfaces__srv__MoveJointPathCommand_Request__Sequence__init(z1_interfaces__srv__MoveJointPathCommand_Request__Sequence * array, size_t size);

/// Finalize array of srv/MoveJointPathCommand messages.
/**
 * It calls
 * z1_interfaces__srv__MoveJointPathCommand_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
void
z1_interfaces__srv__MoveJointPathCommand_Request__Sequence__fini(z1_interfaces__srv__MoveJointPathCommand_Request__Sequence * array);

/// Create array of srv/MoveJointPathCommand messages.
/**
 * It allocates the memory for the array and calls
 * z1_interfaces__srv__MoveJointPathCommand_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
z1_interfaces__srv__MoveJointPathCommand_Request__Sequence *
z1_interfaces__srv__MoveJointPathCommand_Request__Sequence__create(size_t size);

/// Destroy array of srv/MoveJointPathCommand messages.
/**
 * It calls
 * z1_interfaces__srv__MoveJointPathCommand_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
void
z1_interfaces__srv__MoveJointPathCommand_Request__Sequence__destroy(z1_interfaces__srv__MoveJointPathCommand_Request__Sequence * array);

/// Check for srv/MoveJointPathCommand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
bool
z1_interfaces__srv__MoveJointPathCommand_Request__Sequence__are_equal(const z1_interfaces__srv__MoveJointPathCommand_Request__Sequence * lhs, const z1_interfaces__srv__MoveJointPathCommand_Request__Sequence * rhs);

/// Copy an array of srv/MoveJointPathCommand messages.
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
z1_interfaces__srv__MoveJointPathCommand_Request__Sequence__copy(
  const z1_interfaces__srv__MoveJointPathCommand_Request__Sequence * input,
  z1_interfaces__srv__MoveJointPathCommand_Request__Sequence * output);

/// Initialize srv/MoveJointPathCommand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * z1_interfaces__srv__MoveJointPathCommand_Response
 * )) before or use
 * z1_interfaces__srv__MoveJointPathCommand_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
bool
z1_interfaces__srv__MoveJointPathCommand_Response__init(z1_interfaces__srv__MoveJointPathCommand_Response * msg);

/// Finalize srv/MoveJointPathCommand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
void
z1_interfaces__srv__MoveJointPathCommand_Response__fini(z1_interfaces__srv__MoveJointPathCommand_Response * msg);

/// Create srv/MoveJointPathCommand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * z1_interfaces__srv__MoveJointPathCommand_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
z1_interfaces__srv__MoveJointPathCommand_Response *
z1_interfaces__srv__MoveJointPathCommand_Response__create();

/// Destroy srv/MoveJointPathCommand message.
/**
 * It calls
 * z1_interfaces__srv__MoveJointPathCommand_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
void
z1_interfaces__srv__MoveJointPathCommand_Response__destroy(z1_interfaces__srv__MoveJointPathCommand_Response * msg);

/// Check for srv/MoveJointPathCommand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
bool
z1_interfaces__srv__MoveJointPathCommand_Response__are_equal(const z1_interfaces__srv__MoveJointPathCommand_Response * lhs, const z1_interfaces__srv__MoveJointPathCommand_Response * rhs);

/// Copy a srv/MoveJointPathCommand message.
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
z1_interfaces__srv__MoveJointPathCommand_Response__copy(
  const z1_interfaces__srv__MoveJointPathCommand_Response * input,
  z1_interfaces__srv__MoveJointPathCommand_Response * output);

/// Initialize array of srv/MoveJointPathCommand messages.
/**
 * It allocates the memory for the number of elements and calls
 * z1_interfaces__srv__MoveJointPathCommand_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
bool
z1_interfaces__srv__MoveJointPathCommand_Response__Sequence__init(z1_interfaces__srv__MoveJointPathCommand_Response__Sequence * array, size_t size);

/// Finalize array of srv/MoveJointPathCommand messages.
/**
 * It calls
 * z1_interfaces__srv__MoveJointPathCommand_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
void
z1_interfaces__srv__MoveJointPathCommand_Response__Sequence__fini(z1_interfaces__srv__MoveJointPathCommand_Response__Sequence * array);

/// Create array of srv/MoveJointPathCommand messages.
/**
 * It allocates the memory for the array and calls
 * z1_interfaces__srv__MoveJointPathCommand_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
z1_interfaces__srv__MoveJointPathCommand_Response__Sequence *
z1_interfaces__srv__MoveJointPathCommand_Response__Sequence__create(size_t size);

/// Destroy array of srv/MoveJointPathCommand messages.
/**
 * It calls
 * z1_interfaces__srv__MoveJointPathCommand_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
void
z1_interfaces__srv__MoveJointPathCommand_Response__Sequence__destroy(z1_interfaces__srv__MoveJointPathCommand_Response__Sequence * array);

/// Check for srv/MoveJointPathCommand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_z1_interfaces
bool
z1_interfaces__srv__MoveJointPathCommand_Response__Sequence__are_equal(const z1_interfaces__srv__MoveJointPathCommand_Response__Sequence * lhs, const z1_interfaces__srv__MoveJointPathCommand_Response__Sequence * rhs);

/// Copy an array of srv/MoveJointPathCommand messages.
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
z1_interfaces__srv__MoveJointPathCommand_Response__Sequence__copy(
  const z1_interfaces__srv__MoveJointPathCommand_Response__Sequence * input,
  z1_interfaces__srv__MoveJointPathCommand_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // Z1_INTERFACES__SRV__DETAIL__MOVE_JOINT_PATH_COMMAND__FUNCTIONS_H_
