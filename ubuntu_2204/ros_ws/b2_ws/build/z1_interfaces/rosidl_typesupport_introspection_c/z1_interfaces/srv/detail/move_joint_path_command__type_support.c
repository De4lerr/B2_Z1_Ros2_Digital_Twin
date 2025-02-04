// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from z1_interfaces:srv/MoveJointPathCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "z1_interfaces/srv/detail/move_joint_path_command__rosidl_typesupport_introspection_c.h"
#include "z1_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "z1_interfaces/srv/detail/move_joint_path_command__functions.h"
#include "z1_interfaces/srv/detail/move_joint_path_command__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__MoveJointPathCommand_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  z1_interfaces__srv__MoveJointPathCommand_Request__init(message_memory);
}

void z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__MoveJointPathCommand_Request_fini_function(void * message_memory)
{
  z1_interfaces__srv__MoveJointPathCommand_Request__fini(message_memory);
}

size_t z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__size_function__MoveJointPathCommand_Request__posture(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__get_const_function__MoveJointPathCommand_Request__posture(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__get_function__MoveJointPathCommand_Request__posture(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__fetch_function__MoveJointPathCommand_Request__posture(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__get_const_function__MoveJointPathCommand_Request__posture(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__assign_function__MoveJointPathCommand_Request__posture(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__get_function__MoveJointPathCommand_Request__posture(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__MoveJointPathCommand_Request_message_member_array[3] = {
  {
    "posture",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces__srv__MoveJointPathCommand_Request, posture),  // bytes offset in struct
    NULL,  // default value
    z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__size_function__MoveJointPathCommand_Request__posture,  // size() function pointer
    z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__get_const_function__MoveJointPathCommand_Request__posture,  // get_const(index) function pointer
    z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__get_function__MoveJointPathCommand_Request__posture,  // get(index) function pointer
    z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__fetch_function__MoveJointPathCommand_Request__posture,  // fetch(index, &value) function pointer
    z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__assign_function__MoveJointPathCommand_Request__posture,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gripper_pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces__srv__MoveJointPathCommand_Request, gripper_pos),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces__srv__MoveJointPathCommand_Request, max_speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__MoveJointPathCommand_Request_message_members = {
  "z1_interfaces__srv",  // message namespace
  "MoveJointPathCommand_Request",  // message name
  3,  // number of fields
  sizeof(z1_interfaces__srv__MoveJointPathCommand_Request),
  z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__MoveJointPathCommand_Request_message_member_array,  // message members
  z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__MoveJointPathCommand_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__MoveJointPathCommand_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__MoveJointPathCommand_Request_message_type_support_handle = {
  0,
  &z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__MoveJointPathCommand_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_z1_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, z1_interfaces, srv, MoveJointPathCommand_Request)() {
  if (!z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__MoveJointPathCommand_Request_message_type_support_handle.typesupport_identifier) {
    z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__MoveJointPathCommand_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &z1_interfaces__srv__MoveJointPathCommand_Request__rosidl_typesupport_introspection_c__MoveJointPathCommand_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "z1_interfaces/srv/detail/move_joint_path_command__rosidl_typesupport_introspection_c.h"
// already included above
// #include "z1_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "z1_interfaces/srv/detail/move_joint_path_command__functions.h"
// already included above
// #include "z1_interfaces/srv/detail/move_joint_path_command__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void z1_interfaces__srv__MoveJointPathCommand_Response__rosidl_typesupport_introspection_c__MoveJointPathCommand_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  z1_interfaces__srv__MoveJointPathCommand_Response__init(message_memory);
}

void z1_interfaces__srv__MoveJointPathCommand_Response__rosidl_typesupport_introspection_c__MoveJointPathCommand_Response_fini_function(void * message_memory)
{
  z1_interfaces__srv__MoveJointPathCommand_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember z1_interfaces__srv__MoveJointPathCommand_Response__rosidl_typesupport_introspection_c__MoveJointPathCommand_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces__srv__MoveJointPathCommand_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces__srv__MoveJointPathCommand_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers z1_interfaces__srv__MoveJointPathCommand_Response__rosidl_typesupport_introspection_c__MoveJointPathCommand_Response_message_members = {
  "z1_interfaces__srv",  // message namespace
  "MoveJointPathCommand_Response",  // message name
  2,  // number of fields
  sizeof(z1_interfaces__srv__MoveJointPathCommand_Response),
  z1_interfaces__srv__MoveJointPathCommand_Response__rosidl_typesupport_introspection_c__MoveJointPathCommand_Response_message_member_array,  // message members
  z1_interfaces__srv__MoveJointPathCommand_Response__rosidl_typesupport_introspection_c__MoveJointPathCommand_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  z1_interfaces__srv__MoveJointPathCommand_Response__rosidl_typesupport_introspection_c__MoveJointPathCommand_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t z1_interfaces__srv__MoveJointPathCommand_Response__rosidl_typesupport_introspection_c__MoveJointPathCommand_Response_message_type_support_handle = {
  0,
  &z1_interfaces__srv__MoveJointPathCommand_Response__rosidl_typesupport_introspection_c__MoveJointPathCommand_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_z1_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, z1_interfaces, srv, MoveJointPathCommand_Response)() {
  if (!z1_interfaces__srv__MoveJointPathCommand_Response__rosidl_typesupport_introspection_c__MoveJointPathCommand_Response_message_type_support_handle.typesupport_identifier) {
    z1_interfaces__srv__MoveJointPathCommand_Response__rosidl_typesupport_introspection_c__MoveJointPathCommand_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &z1_interfaces__srv__MoveJointPathCommand_Response__rosidl_typesupport_introspection_c__MoveJointPathCommand_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "z1_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "z1_interfaces/srv/detail/move_joint_path_command__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers z1_interfaces__srv__detail__move_joint_path_command__rosidl_typesupport_introspection_c__MoveJointPathCommand_service_members = {
  "z1_interfaces__srv",  // service namespace
  "MoveJointPathCommand",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // z1_interfaces__srv__detail__move_joint_path_command__rosidl_typesupport_introspection_c__MoveJointPathCommand_Request_message_type_support_handle,
  NULL  // response message
  // z1_interfaces__srv__detail__move_joint_path_command__rosidl_typesupport_introspection_c__MoveJointPathCommand_Response_message_type_support_handle
};

static rosidl_service_type_support_t z1_interfaces__srv__detail__move_joint_path_command__rosidl_typesupport_introspection_c__MoveJointPathCommand_service_type_support_handle = {
  0,
  &z1_interfaces__srv__detail__move_joint_path_command__rosidl_typesupport_introspection_c__MoveJointPathCommand_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, z1_interfaces, srv, MoveJointPathCommand_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, z1_interfaces, srv, MoveJointPathCommand_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_z1_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, z1_interfaces, srv, MoveJointPathCommand)() {
  if (!z1_interfaces__srv__detail__move_joint_path_command__rosidl_typesupport_introspection_c__MoveJointPathCommand_service_type_support_handle.typesupport_identifier) {
    z1_interfaces__srv__detail__move_joint_path_command__rosidl_typesupport_introspection_c__MoveJointPathCommand_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)z1_interfaces__srv__detail__move_joint_path_command__rosidl_typesupport_introspection_c__MoveJointPathCommand_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, z1_interfaces, srv, MoveJointPathCommand_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, z1_interfaces, srv, MoveJointPathCommand_Response)()->data;
  }

  return &z1_interfaces__srv__detail__move_joint_path_command__rosidl_typesupport_introspection_c__MoveJointPathCommand_service_type_support_handle;
}
