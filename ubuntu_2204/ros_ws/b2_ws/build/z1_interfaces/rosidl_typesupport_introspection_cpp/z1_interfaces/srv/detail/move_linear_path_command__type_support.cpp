// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from z1_interfaces:srv/MoveLinearPathCommand.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "z1_interfaces/srv/detail/move_linear_path_command__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace z1_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void MoveLinearPathCommand_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) z1_interfaces::srv::MoveLinearPathCommand_Request(_init);
}

void MoveLinearPathCommand_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<z1_interfaces::srv::MoveLinearPathCommand_Request *>(message_memory);
  typed_message->~MoveLinearPathCommand_Request();
}

size_t size_function__MoveLinearPathCommand_Request__posture(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__MoveLinearPathCommand_Request__posture(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__MoveLinearPathCommand_Request__posture(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__MoveLinearPathCommand_Request__posture(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__MoveLinearPathCommand_Request__posture(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__MoveLinearPathCommand_Request__posture(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__MoveLinearPathCommand_Request__posture(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveLinearPathCommand_Request_message_member_array[3] = {
  {
    "posture",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces::srv::MoveLinearPathCommand_Request, posture),  // bytes offset in struct
    nullptr,  // default value
    size_function__MoveLinearPathCommand_Request__posture,  // size() function pointer
    get_const_function__MoveLinearPathCommand_Request__posture,  // get_const(index) function pointer
    get_function__MoveLinearPathCommand_Request__posture,  // get(index) function pointer
    fetch_function__MoveLinearPathCommand_Request__posture,  // fetch(index, &value) function pointer
    assign_function__MoveLinearPathCommand_Request__posture,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "gripper_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces::srv::MoveLinearPathCommand_Request, gripper_pos),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "max_speed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces::srv::MoveLinearPathCommand_Request, max_speed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveLinearPathCommand_Request_message_members = {
  "z1_interfaces::srv",  // message namespace
  "MoveLinearPathCommand_Request",  // message name
  3,  // number of fields
  sizeof(z1_interfaces::srv::MoveLinearPathCommand_Request),
  MoveLinearPathCommand_Request_message_member_array,  // message members
  MoveLinearPathCommand_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveLinearPathCommand_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveLinearPathCommand_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveLinearPathCommand_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace z1_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<z1_interfaces::srv::MoveLinearPathCommand_Request>()
{
  return &::z1_interfaces::srv::rosidl_typesupport_introspection_cpp::MoveLinearPathCommand_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, z1_interfaces, srv, MoveLinearPathCommand_Request)() {
  return &::z1_interfaces::srv::rosidl_typesupport_introspection_cpp::MoveLinearPathCommand_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "z1_interfaces/srv/detail/move_linear_path_command__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace z1_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void MoveLinearPathCommand_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) z1_interfaces::srv::MoveLinearPathCommand_Response(_init);
}

void MoveLinearPathCommand_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<z1_interfaces::srv::MoveLinearPathCommand_Response *>(message_memory);
  typed_message->~MoveLinearPathCommand_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveLinearPathCommand_Response_message_member_array[2] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces::srv::MoveLinearPathCommand_Response, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "message",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces::srv::MoveLinearPathCommand_Response, message),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveLinearPathCommand_Response_message_members = {
  "z1_interfaces::srv",  // message namespace
  "MoveLinearPathCommand_Response",  // message name
  2,  // number of fields
  sizeof(z1_interfaces::srv::MoveLinearPathCommand_Response),
  MoveLinearPathCommand_Response_message_member_array,  // message members
  MoveLinearPathCommand_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveLinearPathCommand_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveLinearPathCommand_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveLinearPathCommand_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace z1_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<z1_interfaces::srv::MoveLinearPathCommand_Response>()
{
  return &::z1_interfaces::srv::rosidl_typesupport_introspection_cpp::MoveLinearPathCommand_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, z1_interfaces, srv, MoveLinearPathCommand_Response)() {
  return &::z1_interfaces::srv::rosidl_typesupport_introspection_cpp::MoveLinearPathCommand_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "z1_interfaces/srv/detail/move_linear_path_command__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace z1_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers MoveLinearPathCommand_service_members = {
  "z1_interfaces::srv",  // service namespace
  "MoveLinearPathCommand",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<z1_interfaces::srv::MoveLinearPathCommand>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t MoveLinearPathCommand_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveLinearPathCommand_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace z1_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<z1_interfaces::srv::MoveLinearPathCommand>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::z1_interfaces::srv::rosidl_typesupport_introspection_cpp::MoveLinearPathCommand_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::z1_interfaces::srv::MoveLinearPathCommand_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::z1_interfaces::srv::MoveLinearPathCommand_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, z1_interfaces, srv, MoveLinearPathCommand)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<z1_interfaces::srv::MoveLinearPathCommand>();
}

#ifdef __cplusplus
}
#endif
