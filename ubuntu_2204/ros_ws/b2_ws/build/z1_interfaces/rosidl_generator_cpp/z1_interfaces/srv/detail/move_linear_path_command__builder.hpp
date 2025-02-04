// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from z1_interfaces:srv/MoveLinearPathCommand.idl
// generated code does not contain a copyright notice

#ifndef Z1_INTERFACES__SRV__DETAIL__MOVE_LINEAR_PATH_COMMAND__BUILDER_HPP_
#define Z1_INTERFACES__SRV__DETAIL__MOVE_LINEAR_PATH_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "z1_interfaces/srv/detail/move_linear_path_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace z1_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoveLinearPathCommand_Request_max_speed
{
public:
  explicit Init_MoveLinearPathCommand_Request_max_speed(::z1_interfaces::srv::MoveLinearPathCommand_Request & msg)
  : msg_(msg)
  {}
  ::z1_interfaces::srv::MoveLinearPathCommand_Request max_speed(::z1_interfaces::srv::MoveLinearPathCommand_Request::_max_speed_type arg)
  {
    msg_.max_speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::z1_interfaces::srv::MoveLinearPathCommand_Request msg_;
};

class Init_MoveLinearPathCommand_Request_gripper_pos
{
public:
  explicit Init_MoveLinearPathCommand_Request_gripper_pos(::z1_interfaces::srv::MoveLinearPathCommand_Request & msg)
  : msg_(msg)
  {}
  Init_MoveLinearPathCommand_Request_max_speed gripper_pos(::z1_interfaces::srv::MoveLinearPathCommand_Request::_gripper_pos_type arg)
  {
    msg_.gripper_pos = std::move(arg);
    return Init_MoveLinearPathCommand_Request_max_speed(msg_);
  }

private:
  ::z1_interfaces::srv::MoveLinearPathCommand_Request msg_;
};

class Init_MoveLinearPathCommand_Request_posture
{
public:
  Init_MoveLinearPathCommand_Request_posture()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveLinearPathCommand_Request_gripper_pos posture(::z1_interfaces::srv::MoveLinearPathCommand_Request::_posture_type arg)
  {
    msg_.posture = std::move(arg);
    return Init_MoveLinearPathCommand_Request_gripper_pos(msg_);
  }

private:
  ::z1_interfaces::srv::MoveLinearPathCommand_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::z1_interfaces::srv::MoveLinearPathCommand_Request>()
{
  return z1_interfaces::srv::builder::Init_MoveLinearPathCommand_Request_posture();
}

}  // namespace z1_interfaces


namespace z1_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoveLinearPathCommand_Response_message
{
public:
  explicit Init_MoveLinearPathCommand_Response_message(::z1_interfaces::srv::MoveLinearPathCommand_Response & msg)
  : msg_(msg)
  {}
  ::z1_interfaces::srv::MoveLinearPathCommand_Response message(::z1_interfaces::srv::MoveLinearPathCommand_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::z1_interfaces::srv::MoveLinearPathCommand_Response msg_;
};

class Init_MoveLinearPathCommand_Response_success
{
public:
  Init_MoveLinearPathCommand_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveLinearPathCommand_Response_message success(::z1_interfaces::srv::MoveLinearPathCommand_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MoveLinearPathCommand_Response_message(msg_);
  }

private:
  ::z1_interfaces::srv::MoveLinearPathCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::z1_interfaces::srv::MoveLinearPathCommand_Response>()
{
  return z1_interfaces::srv::builder::Init_MoveLinearPathCommand_Response_success();
}

}  // namespace z1_interfaces

#endif  // Z1_INTERFACES__SRV__DETAIL__MOVE_LINEAR_PATH_COMMAND__BUILDER_HPP_
