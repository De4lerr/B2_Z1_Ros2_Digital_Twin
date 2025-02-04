// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from z1_interfaces:msg/ArmControlCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "z1_interfaces/msg/detail/arm_control_command__rosidl_typesupport_introspection_c.h"
#include "z1_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "z1_interfaces/msg/detail/arm_control_command__functions.h"
#include "z1_interfaces/msg/detail/arm_control_command__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__ArmControlCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  z1_interfaces__msg__ArmControlCommand__init(message_memory);
}

void z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__ArmControlCommand_fini_function(void * message_memory)
{
  z1_interfaces__msg__ArmControlCommand__fini(message_memory);
}

size_t z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__size_function__ArmControlCommand__directions(
  const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__get_const_function__ArmControlCommand__directions(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__get_function__ArmControlCommand__directions(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__fetch_function__ArmControlCommand__directions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__get_const_function__ArmControlCommand__directions(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__assign_function__ArmControlCommand__directions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__get_function__ArmControlCommand__directions(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__ArmControlCommand_message_member_array[4] = {
  {
    "directions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces__msg__ArmControlCommand, directions),  // bytes offset in struct
    NULL,  // default value
    z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__size_function__ArmControlCommand__directions,  // size() function pointer
    z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__get_const_function__ArmControlCommand__directions,  // get_const(index) function pointer
    z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__get_function__ArmControlCommand__directions,  // get(index) function pointer
    z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__fetch_function__ArmControlCommand__directions,  // fetch(index, &value) function pointer
    z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__assign_function__ArmControlCommand__directions,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed_1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces__msg__ArmControlCommand, speed_1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed_2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces__msg__ArmControlCommand, speed_2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cartesian",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces__msg__ArmControlCommand, cartesian),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__ArmControlCommand_message_members = {
  "z1_interfaces__msg",  // message namespace
  "ArmControlCommand",  // message name
  4,  // number of fields
  sizeof(z1_interfaces__msg__ArmControlCommand),
  z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__ArmControlCommand_message_member_array,  // message members
  z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__ArmControlCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__ArmControlCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__ArmControlCommand_message_type_support_handle = {
  0,
  &z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__ArmControlCommand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_z1_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, z1_interfaces, msg, ArmControlCommand)() {
  if (!z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__ArmControlCommand_message_type_support_handle.typesupport_identifier) {
    z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__ArmControlCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &z1_interfaces__msg__ArmControlCommand__rosidl_typesupport_introspection_c__ArmControlCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
