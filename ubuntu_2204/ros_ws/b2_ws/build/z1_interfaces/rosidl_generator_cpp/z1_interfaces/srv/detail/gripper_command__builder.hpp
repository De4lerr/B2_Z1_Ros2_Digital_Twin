// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from z1_interfaces:srv/GripperCommand.idl
// generated code does not contain a copyright notice

#ifndef Z1_INTERFACES__SRV__DETAIL__GRIPPER_COMMAND__BUILDER_HPP_
#define Z1_INTERFACES__SRV__DETAIL__GRIPPER_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "z1_interfaces/srv/detail/gripper_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace z1_interfaces
{

namespace srv
{

namespace builder
{

class Init_GripperCommand_Request_gripper_tau
{
public:
  explicit Init_GripperCommand_Request_gripper_tau(::z1_interfaces::srv::GripperCommand_Request & msg)
  : msg_(msg)
  {}
  ::z1_interfaces::srv::GripperCommand_Request gripper_tau(::z1_interfaces::srv::GripperCommand_Request::_gripper_tau_type arg)
  {
    msg_.gripper_tau = std::move(arg);
    return std::move(msg_);
  }

private:
  ::z1_interfaces::srv::GripperCommand_Request msg_;
};

class Init_GripperCommand_Request_gripper_w
{
public:
  explicit Init_GripperCommand_Request_gripper_w(::z1_interfaces::srv::GripperCommand_Request & msg)
  : msg_(msg)
  {}
  Init_GripperCommand_Request_gripper_tau gripper_w(::z1_interfaces::srv::GripperCommand_Request::_gripper_w_type arg)
  {
    msg_.gripper_w = std::move(arg);
    return Init_GripperCommand_Request_gripper_tau(msg_);
  }

private:
  ::z1_interfaces::srv::GripperCommand_Request msg_;
};

class Init_GripperCommand_Request_gripper_pos
{
public:
  Init_GripperCommand_Request_gripper_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GripperCommand_Request_gripper_w gripper_pos(::z1_interfaces::srv::GripperCommand_Request::_gripper_pos_type arg)
  {
    msg_.gripper_pos = std::move(arg);
    return Init_GripperCommand_Request_gripper_w(msg_);
  }

private:
  ::z1_interfaces::srv::GripperCommand_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::z1_interfaces::srv::GripperCommand_Request>()
{
  return z1_interfaces::srv::builder::Init_GripperCommand_Request_gripper_pos();
}

}  // namespace z1_interfaces


namespace z1_interfaces
{

namespace srv
{

namespace builder
{

class Init_GripperCommand_Response_message
{
public:
  explicit Init_GripperCommand_Response_message(::z1_interfaces::srv::GripperCommand_Response & msg)
  : msg_(msg)
  {}
  ::z1_interfaces::srv::GripperCommand_Response message(::z1_interfaces::srv::GripperCommand_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::z1_interfaces::srv::GripperCommand_Response msg_;
};

class Init_GripperCommand_Response_success
{
public:
  Init_GripperCommand_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GripperCommand_Response_message success(::z1_interfaces::srv::GripperCommand_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GripperCommand_Response_message(msg_);
  }

private:
  ::z1_interfaces::srv::GripperCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::z1_interfaces::srv::GripperCommand_Response>()
{
  return z1_interfaces::srv::builder::Init_GripperCommand_Response_success();
}

}  // namespace z1_interfaces

#endif  // Z1_INTERFACES__SRV__DETAIL__GRIPPER_COMMAND__BUILDER_HPP_
