// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from z1_interfaces:msg/ArmControlCommand.idl
// generated code does not contain a copyright notice

#ifndef Z1_INTERFACES__MSG__DETAIL__ARM_CONTROL_COMMAND__STRUCT_H_
#define Z1_INTERFACES__MSG__DETAIL__ARM_CONTROL_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ArmControlCommand in the package z1_interfaces.
typedef struct z1_interfaces__msg__ArmControlCommand
{
  /// Vetor de direções: roll, pitch, yaw, x, y, z, gripper
  double directions[7];
  /// Velocidade de orientação (range: [0, 0.6])
  double speed_1;
  /// Velocidade de posição (range: [0, 0.3])
  double speed_2;
  /// Diz se quer movimento cartesiano ou nao
  bool cartesian;
} z1_interfaces__msg__ArmControlCommand;

// Struct for a sequence of z1_interfaces__msg__ArmControlCommand.
typedef struct z1_interfaces__msg__ArmControlCommand__Sequence
{
  z1_interfaces__msg__ArmControlCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} z1_interfaces__msg__ArmControlCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // Z1_INTERFACES__MSG__DETAIL__ARM_CONTROL_COMMAND__STRUCT_H_
