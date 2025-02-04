// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from z1_interfaces:srv/MoveLinearPathCommand.idl
// generated code does not contain a copyright notice

#ifndef Z1_INTERFACES__SRV__DETAIL__MOVE_LINEAR_PATH_COMMAND__TRAITS_HPP_
#define Z1_INTERFACES__SRV__DETAIL__MOVE_LINEAR_PATH_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "z1_interfaces/srv/detail/move_linear_path_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace z1_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveLinearPathCommand_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: posture
  {
    if (msg.posture.size() == 0) {
      out << "posture: []";
    } else {
      out << "posture: [";
      size_t pending_items = msg.posture.size();
      for (auto item : msg.posture) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: gripper_pos
  {
    out << "gripper_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_pos, out);
    out << ", ";
  }

  // member: max_speed
  {
    out << "max_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.max_speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveLinearPathCommand_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: posture
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.posture.size() == 0) {
      out << "posture: []\n";
    } else {
      out << "posture:\n";
      for (auto item : msg.posture) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: gripper_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_pos, out);
    out << "\n";
  }

  // member: max_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.max_speed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveLinearPathCommand_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace z1_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use z1_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const z1_interfaces::srv::MoveLinearPathCommand_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  z1_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use z1_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const z1_interfaces::srv::MoveLinearPathCommand_Request & msg)
{
  return z1_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<z1_interfaces::srv::MoveLinearPathCommand_Request>()
{
  return "z1_interfaces::srv::MoveLinearPathCommand_Request";
}

template<>
inline const char * name<z1_interfaces::srv::MoveLinearPathCommand_Request>()
{
  return "z1_interfaces/srv/MoveLinearPathCommand_Request";
}

template<>
struct has_fixed_size<z1_interfaces::srv::MoveLinearPathCommand_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<z1_interfaces::srv::MoveLinearPathCommand_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<z1_interfaces::srv::MoveLinearPathCommand_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace z1_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveLinearPathCommand_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveLinearPathCommand_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveLinearPathCommand_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace z1_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use z1_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const z1_interfaces::srv::MoveLinearPathCommand_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  z1_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use z1_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const z1_interfaces::srv::MoveLinearPathCommand_Response & msg)
{
  return z1_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<z1_interfaces::srv::MoveLinearPathCommand_Response>()
{
  return "z1_interfaces::srv::MoveLinearPathCommand_Response";
}

template<>
inline const char * name<z1_interfaces::srv::MoveLinearPathCommand_Response>()
{
  return "z1_interfaces/srv/MoveLinearPathCommand_Response";
}

template<>
struct has_fixed_size<z1_interfaces::srv::MoveLinearPathCommand_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<z1_interfaces::srv::MoveLinearPathCommand_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<z1_interfaces::srv::MoveLinearPathCommand_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<z1_interfaces::srv::MoveLinearPathCommand>()
{
  return "z1_interfaces::srv::MoveLinearPathCommand";
}

template<>
inline const char * name<z1_interfaces::srv::MoveLinearPathCommand>()
{
  return "z1_interfaces/srv/MoveLinearPathCommand";
}

template<>
struct has_fixed_size<z1_interfaces::srv::MoveLinearPathCommand>
  : std::integral_constant<
    bool,
    has_fixed_size<z1_interfaces::srv::MoveLinearPathCommand_Request>::value &&
    has_fixed_size<z1_interfaces::srv::MoveLinearPathCommand_Response>::value
  >
{
};

template<>
struct has_bounded_size<z1_interfaces::srv::MoveLinearPathCommand>
  : std::integral_constant<
    bool,
    has_bounded_size<z1_interfaces::srv::MoveLinearPathCommand_Request>::value &&
    has_bounded_size<z1_interfaces::srv::MoveLinearPathCommand_Response>::value
  >
{
};

template<>
struct is_service<z1_interfaces::srv::MoveLinearPathCommand>
  : std::true_type
{
};

template<>
struct is_service_request<z1_interfaces::srv::MoveLinearPathCommand_Request>
  : std::true_type
{
};

template<>
struct is_service_response<z1_interfaces::srv::MoveLinearPathCommand_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // Z1_INTERFACES__SRV__DETAIL__MOVE_LINEAR_PATH_COMMAND__TRAITS_HPP_
