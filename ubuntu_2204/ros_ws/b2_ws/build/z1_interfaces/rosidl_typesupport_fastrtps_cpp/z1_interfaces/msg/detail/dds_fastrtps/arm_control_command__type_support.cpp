// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from z1_interfaces:msg/ArmControlCommand.idl
// generated code does not contain a copyright notice
#include "z1_interfaces/msg/detail/arm_control_command__rosidl_typesupport_fastrtps_cpp.hpp"
#include "z1_interfaces/msg/detail/arm_control_command__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace z1_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_z1_interfaces
cdr_serialize(
  const z1_interfaces::msg::ArmControlCommand & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: directions
  {
    cdr << ros_message.directions;
  }
  // Member: speed_1
  cdr << ros_message.speed_1;
  // Member: speed_2
  cdr << ros_message.speed_2;
  // Member: cartesian
  cdr << (ros_message.cartesian ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_z1_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  z1_interfaces::msg::ArmControlCommand & ros_message)
{
  // Member: directions
  {
    cdr >> ros_message.directions;
  }

  // Member: speed_1
  cdr >> ros_message.speed_1;

  // Member: speed_2
  cdr >> ros_message.speed_2;

  // Member: cartesian
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.cartesian = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_z1_interfaces
get_serialized_size(
  const z1_interfaces::msg::ArmControlCommand & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: directions
  {
    size_t array_size = 7;
    size_t item_size = sizeof(ros_message.directions[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: speed_1
  {
    size_t item_size = sizeof(ros_message.speed_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: speed_2
  {
    size_t item_size = sizeof(ros_message.speed_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cartesian
  {
    size_t item_size = sizeof(ros_message.cartesian);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_z1_interfaces
max_serialized_size_ArmControlCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: directions
  {
    size_t array_size = 7;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: speed_1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: speed_2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: cartesian
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = z1_interfaces::msg::ArmControlCommand;
    is_plain =
      (
      offsetof(DataType, cartesian) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ArmControlCommand__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const z1_interfaces::msg::ArmControlCommand *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ArmControlCommand__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<z1_interfaces::msg::ArmControlCommand *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ArmControlCommand__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const z1_interfaces::msg::ArmControlCommand *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ArmControlCommand__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ArmControlCommand(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ArmControlCommand__callbacks = {
  "z1_interfaces::msg",
  "ArmControlCommand",
  _ArmControlCommand__cdr_serialize,
  _ArmControlCommand__cdr_deserialize,
  _ArmControlCommand__get_serialized_size,
  _ArmControlCommand__max_serialized_size
};

static rosidl_message_type_support_t _ArmControlCommand__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ArmControlCommand__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace z1_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_z1_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<z1_interfaces::msg::ArmControlCommand>()
{
  return &z1_interfaces::msg::typesupport_fastrtps_cpp::_ArmControlCommand__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, z1_interfaces, msg, ArmControlCommand)() {
  return &z1_interfaces::msg::typesupport_fastrtps_cpp::_ArmControlCommand__handle;
}

#ifdef __cplusplus
}
#endif
