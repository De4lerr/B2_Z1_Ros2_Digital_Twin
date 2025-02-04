// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from z1_interfaces:msg/ArmControlCommand.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "z1_interfaces/msg/detail/arm_control_command__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace z1_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ArmControlCommand_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) z1_interfaces::msg::ArmControlCommand(_init);
}

void ArmControlCommand_fini_function(void * message_memory)
{
  auto typed_message = static_cast<z1_interfaces::msg::ArmControlCommand *>(message_memory);
  typed_message->~ArmControlCommand();
}

size_t size_function__ArmControlCommand__directions(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__ArmControlCommand__directions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__ArmControlCommand__directions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void fetch_function__ArmControlCommand__directions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__ArmControlCommand__directions(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__ArmControlCommand__directions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__ArmControlCommand__directions(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ArmControlCommand_message_member_array[4] = {
  {
    "directions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces::msg::ArmControlCommand, directions),  // bytes offset in struct
    nullptr,  // default value
    size_function__ArmControlCommand__directions,  // size() function pointer
    get_const_function__ArmControlCommand__directions,  // get_const(index) function pointer
    get_function__ArmControlCommand__directions,  // get(index) function pointer
    fetch_function__ArmControlCommand__directions,  // fetch(index, &value) function pointer
    assign_function__ArmControlCommand__directions,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "speed_1",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces::msg::ArmControlCommand, speed_1),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "speed_2",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces::msg::ArmControlCommand, speed_2),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "cartesian",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(z1_interfaces::msg::ArmControlCommand, cartesian),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ArmControlCommand_message_members = {
  "z1_interfaces::msg",  // message namespace
  "ArmControlCommand",  // message name
  4,  // number of fields
  sizeof(z1_interfaces::msg::ArmControlCommand),
  ArmControlCommand_message_member_array,  // message members
  ArmControlCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  ArmControlCommand_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ArmControlCommand_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ArmControlCommand_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace z1_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<z1_interfaces::msg::ArmControlCommand>()
{
  return &::z1_interfaces::msg::rosidl_typesupport_introspection_cpp::ArmControlCommand_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, z1_interfaces, msg, ArmControlCommand)() {
  return &::z1_interfaces::msg::rosidl_typesupport_introspection_cpp::ArmControlCommand_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
