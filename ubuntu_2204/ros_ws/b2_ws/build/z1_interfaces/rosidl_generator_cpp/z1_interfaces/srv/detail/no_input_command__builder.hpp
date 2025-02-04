// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from z1_interfaces:srv/NoInputCommand.idl
// generated code does not contain a copyright notice

#ifndef Z1_INTERFACES__SRV__DETAIL__NO_INPUT_COMMAND__BUILDER_HPP_
#define Z1_INTERFACES__SRV__DETAIL__NO_INPUT_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "z1_interfaces/srv/detail/no_input_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace z1_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::z1_interfaces::srv::NoInputCommand_Request>()
{
  return ::z1_interfaces::srv::NoInputCommand_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace z1_interfaces


namespace z1_interfaces
{

namespace srv
{

namespace builder
{

class Init_NoInputCommand_Response_message
{
public:
  explicit Init_NoInputCommand_Response_message(::z1_interfaces::srv::NoInputCommand_Response & msg)
  : msg_(msg)
  {}
  ::z1_interfaces::srv::NoInputCommand_Response message(::z1_interfaces::srv::NoInputCommand_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::z1_interfaces::srv::NoInputCommand_Response msg_;
};

class Init_NoInputCommand_Response_success
{
public:
  Init_NoInputCommand_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NoInputCommand_Response_message success(::z1_interfaces::srv::NoInputCommand_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_NoInputCommand_Response_message(msg_);
  }

private:
  ::z1_interfaces::srv::NoInputCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::z1_interfaces::srv::NoInputCommand_Response>()
{
  return z1_interfaces::srv::builder::Init_NoInputCommand_Response_success();
}

}  // namespace z1_interfaces

#endif  // Z1_INTERFACES__SRV__DETAIL__NO_INPUT_COMMAND__BUILDER_HPP_
