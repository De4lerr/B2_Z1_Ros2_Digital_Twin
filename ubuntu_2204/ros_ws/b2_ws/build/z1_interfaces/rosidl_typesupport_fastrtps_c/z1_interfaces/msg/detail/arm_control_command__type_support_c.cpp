// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from z1_interfaces:msg/ArmControlCommand.idl
// generated code does not contain a copyright notice
#include "z1_interfaces/msg/detail/arm_control_command__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "z1_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "z1_interfaces/msg/detail/arm_control_command__struct.h"
#include "z1_interfaces/msg/detail/arm_control_command__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _ArmControlCommand__ros_msg_type = z1_interfaces__msg__ArmControlCommand;

static bool _ArmControlCommand__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ArmControlCommand__ros_msg_type * ros_message = static_cast<const _ArmControlCommand__ros_msg_type *>(untyped_ros_message);
  // Field name: directions
  {
    size_t size = 7;
    auto array_ptr = ros_message->directions;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: speed_1
  {
    cdr << ros_message->speed_1;
  }

  // Field name: speed_2
  {
    cdr << ros_message->speed_2;
  }

  // Field name: cartesian
  {
    cdr << (ros_message->cartesian ? true : false);
  }

  return true;
}

static bool _ArmControlCommand__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ArmControlCommand__ros_msg_type * ros_message = static_cast<_ArmControlCommand__ros_msg_type *>(untyped_ros_message);
  // Field name: directions
  {
    size_t size = 7;
    auto array_ptr = ros_message->directions;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: speed_1
  {
    cdr >> ros_message->speed_1;
  }

  // Field name: speed_2
  {
    cdr >> ros_message->speed_2;
  }

  // Field name: cartesian
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->cartesian = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_z1_interfaces
size_t get_serialized_size_z1_interfaces__msg__ArmControlCommand(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ArmControlCommand__ros_msg_type * ros_message = static_cast<const _ArmControlCommand__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name directions
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->directions;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed_1
  {
    size_t item_size = sizeof(ros_message->speed_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed_2
  {
    size_t item_size = sizeof(ros_message->speed_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cartesian
  {
    size_t item_size = sizeof(ros_message->cartesian);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ArmControlCommand__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_z1_interfaces__msg__ArmControlCommand(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_z1_interfaces
size_t max_serialized_size_z1_interfaces__msg__ArmControlCommand(
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

  // member: directions
  {
    size_t array_size = 7;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: speed_1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: speed_2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: cartesian
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
    using DataType = z1_interfaces__msg__ArmControlCommand;
    is_plain =
      (
      offsetof(DataType, cartesian) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ArmControlCommand__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_z1_interfaces__msg__ArmControlCommand(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ArmControlCommand = {
  "z1_interfaces::msg",
  "ArmControlCommand",
  _ArmControlCommand__cdr_serialize,
  _ArmControlCommand__cdr_deserialize,
  _ArmControlCommand__get_serialized_size,
  _ArmControlCommand__max_serialized_size
};

static rosidl_message_type_support_t _ArmControlCommand__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ArmControlCommand,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, z1_interfaces, msg, ArmControlCommand)() {
  return &_ArmControlCommand__type_support;
}

#if defined(__cplusplus)
}
#endif
