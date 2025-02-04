// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from z1_interfaces:msg/ArmControlCommand.idl
// generated code does not contain a copyright notice

#ifndef Z1_INTERFACES__MSG__DETAIL__ARM_CONTROL_COMMAND__TRAITS_HPP_
#define Z1_INTERFACES__MSG__DETAIL__ARM_CONTROL_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "z1_interfaces/msg/detail/arm_control_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace z1_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ArmControlCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: directions
  {
    if (msg.directions.size() == 0) {
      out << "directions: []";
    } else {
      out << "directions: [";
      size_t pending_items = msg.directions.size();
      for (auto item : msg.directions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: speed_1
  {
    out << "speed_1: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_1, out);
    out << ", ";
  }

  // member: speed_2
  {
    out << "speed_2: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_2, out);
    out << ", ";
  }

  // member: cartesian
  {
    out << "cartesian: ";
    rosidl_generator_traits::value_to_yaml(msg.cartesian, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArmControlCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: directions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.directions.size() == 0) {
      out << "directions: []\n";
    } else {
      out << "directions:\n";
      for (auto item : msg.directions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: speed_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_1: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_1, out);
    out << "\n";
  }

  // member: speed_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_2: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_2, out);
    out << "\n";
  }

  // member: cartesian
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cartesian: ";
    rosidl_generator_traits::value_to_yaml(msg.cartesian, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArmControlCommand & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace z1_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use z1_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const z1_interfaces::msg::ArmControlCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  z1_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use z1_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const z1_interfaces::msg::ArmControlCommand & msg)
{
  return z1_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<z1_interfaces::msg::ArmControlCommand>()
{
  return "z1_interfaces::msg::ArmControlCommand";
}

template<>
inline const char * name<z1_interfaces::msg::ArmControlCommand>()
{
  return "z1_interfaces/msg/ArmControlCommand";
}

template<>
struct has_fixed_size<z1_interfaces::msg::ArmControlCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<z1_interfaces::msg::ArmControlCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<z1_interfaces::msg::ArmControlCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // Z1_INTERFACES__MSG__DETAIL__ARM_CONTROL_COMMAND__TRAITS_HPP_
