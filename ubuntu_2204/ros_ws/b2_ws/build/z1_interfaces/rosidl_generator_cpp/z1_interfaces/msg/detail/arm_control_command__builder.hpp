// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from z1_interfaces:msg/ArmControlCommand.idl
// generated code does not contain a copyright notice

#ifndef Z1_INTERFACES__MSG__DETAIL__ARM_CONTROL_COMMAND__BUILDER_HPP_
#define Z1_INTERFACES__MSG__DETAIL__ARM_CONTROL_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "z1_interfaces/msg/detail/arm_control_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace z1_interfaces
{

namespace msg
{

namespace builder
{

class Init_ArmControlCommand_cartesian
{
public:
  explicit Init_ArmControlCommand_cartesian(::z1_interfaces::msg::ArmControlCommand & msg)
  : msg_(msg)
  {}
  ::z1_interfaces::msg::ArmControlCommand cartesian(::z1_interfaces::msg::ArmControlCommand::_cartesian_type arg)
  {
    msg_.cartesian = std::move(arg);
    return std::move(msg_);
  }

private:
  ::z1_interfaces::msg::ArmControlCommand msg_;
};

class Init_ArmControlCommand_speed_2
{
public:
  explicit Init_ArmControlCommand_speed_2(::z1_interfaces::msg::ArmControlCommand & msg)
  : msg_(msg)
  {}
  Init_ArmControlCommand_cartesian speed_2(::z1_interfaces::msg::ArmControlCommand::_speed_2_type arg)
  {
    msg_.speed_2 = std::move(arg);
    return Init_ArmControlCommand_cartesian(msg_);
  }

private:
  ::z1_interfaces::msg::ArmControlCommand msg_;
};

class Init_ArmControlCommand_speed_1
{
public:
  explicit Init_ArmControlCommand_speed_1(::z1_interfaces::msg::ArmControlCommand & msg)
  : msg_(msg)
  {}
  Init_ArmControlCommand_speed_2 speed_1(::z1_interfaces::msg::ArmControlCommand::_speed_1_type arg)
  {
    msg_.speed_1 = std::move(arg);
    return Init_ArmControlCommand_speed_2(msg_);
  }

private:
  ::z1_interfaces::msg::ArmControlCommand msg_;
};

class Init_ArmControlCommand_directions
{
public:
  Init_ArmControlCommand_directions()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmControlCommand_speed_1 directions(::z1_interfaces::msg::ArmControlCommand::_directions_type arg)
  {
    msg_.directions = std::move(arg);
    return Init_ArmControlCommand_speed_1(msg_);
  }

private:
  ::z1_interfaces::msg::ArmControlCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::z1_interfaces::msg::ArmControlCommand>()
{
  return z1_interfaces::msg::builder::Init_ArmControlCommand_directions();
}

}  // namespace z1_interfaces

#endif  // Z1_INTERFACES__MSG__DETAIL__ARM_CONTROL_COMMAND__BUILDER_HPP_
