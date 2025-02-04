// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from z1_interfaces:srv/MoveJointPathCommand.idl
// generated code does not contain a copyright notice

#ifndef Z1_INTERFACES__SRV__DETAIL__MOVE_JOINT_PATH_COMMAND__STRUCT_H_
#define Z1_INTERFACES__SRV__DETAIL__MOVE_JOINT_PATH_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/MoveJointPathCommand in the package z1_interfaces.
typedef struct z1_interfaces__srv__MoveJointPathCommand_Request
{
  double posture[6];
  double gripper_pos;
  double max_speed;
} z1_interfaces__srv__MoveJointPathCommand_Request;

// Struct for a sequence of z1_interfaces__srv__MoveJointPathCommand_Request.
typedef struct z1_interfaces__srv__MoveJointPathCommand_Request__Sequence
{
  z1_interfaces__srv__MoveJointPathCommand_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} z1_interfaces__srv__MoveJointPathCommand_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/MoveJointPathCommand in the package z1_interfaces.
typedef struct z1_interfaces__srv__MoveJointPathCommand_Response
{
  bool success;
  rosidl_runtime_c__String message;
} z1_interfaces__srv__MoveJointPathCommand_Response;

// Struct for a sequence of z1_interfaces__srv__MoveJointPathCommand_Response.
typedef struct z1_interfaces__srv__MoveJointPathCommand_Response__Sequence
{
  z1_interfaces__srv__MoveJointPathCommand_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} z1_interfaces__srv__MoveJointPathCommand_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // Z1_INTERFACES__SRV__DETAIL__MOVE_JOINT_PATH_COMMAND__STRUCT_H_
