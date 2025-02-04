// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from z1_interfaces:srv/GripperCommand.idl
// generated code does not contain a copyright notice

#ifndef Z1_INTERFACES__SRV__DETAIL__GRIPPER_COMMAND__STRUCT_HPP_
#define Z1_INTERFACES__SRV__DETAIL__GRIPPER_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__z1_interfaces__srv__GripperCommand_Request __attribute__((deprecated))
#else
# define DEPRECATED__z1_interfaces__srv__GripperCommand_Request __declspec(deprecated)
#endif

namespace z1_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GripperCommand_Request_
{
  using Type = GripperCommand_Request_<ContainerAllocator>;

  explicit GripperCommand_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gripper_pos = 0.0;
      this->gripper_w = 0.0;
      this->gripper_tau = 0.0;
    }
  }

  explicit GripperCommand_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gripper_pos = 0.0;
      this->gripper_w = 0.0;
      this->gripper_tau = 0.0;
    }
  }

  // field types and members
  using _gripper_pos_type =
    double;
  _gripper_pos_type gripper_pos;
  using _gripper_w_type =
    double;
  _gripper_w_type gripper_w;
  using _gripper_tau_type =
    double;
  _gripper_tau_type gripper_tau;

  // setters for named parameter idiom
  Type & set__gripper_pos(
    const double & _arg)
  {
    this->gripper_pos = _arg;
    return *this;
  }
  Type & set__gripper_w(
    const double & _arg)
  {
    this->gripper_w = _arg;
    return *this;
  }
  Type & set__gripper_tau(
    const double & _arg)
  {
    this->gripper_tau = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    z1_interfaces::srv::GripperCommand_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const z1_interfaces::srv::GripperCommand_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<z1_interfaces::srv::GripperCommand_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<z1_interfaces::srv::GripperCommand_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      z1_interfaces::srv::GripperCommand_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<z1_interfaces::srv::GripperCommand_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      z1_interfaces::srv::GripperCommand_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<z1_interfaces::srv::GripperCommand_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<z1_interfaces::srv::GripperCommand_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<z1_interfaces::srv::GripperCommand_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__z1_interfaces__srv__GripperCommand_Request
    std::shared_ptr<z1_interfaces::srv::GripperCommand_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__z1_interfaces__srv__GripperCommand_Request
    std::shared_ptr<z1_interfaces::srv::GripperCommand_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GripperCommand_Request_ & other) const
  {
    if (this->gripper_pos != other.gripper_pos) {
      return false;
    }
    if (this->gripper_w != other.gripper_w) {
      return false;
    }
    if (this->gripper_tau != other.gripper_tau) {
      return false;
    }
    return true;
  }
  bool operator!=(const GripperCommand_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GripperCommand_Request_

// alias to use template instance with default allocator
using GripperCommand_Request =
  z1_interfaces::srv::GripperCommand_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace z1_interfaces


#ifndef _WIN32
# define DEPRECATED__z1_interfaces__srv__GripperCommand_Response __attribute__((deprecated))
#else
# define DEPRECATED__z1_interfaces__srv__GripperCommand_Response __declspec(deprecated)
#endif

namespace z1_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GripperCommand_Response_
{
  using Type = GripperCommand_Response_<ContainerAllocator>;

  explicit GripperCommand_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit GripperCommand_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    z1_interfaces::srv::GripperCommand_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const z1_interfaces::srv::GripperCommand_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<z1_interfaces::srv::GripperCommand_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<z1_interfaces::srv::GripperCommand_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      z1_interfaces::srv::GripperCommand_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<z1_interfaces::srv::GripperCommand_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      z1_interfaces::srv::GripperCommand_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<z1_interfaces::srv::GripperCommand_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<z1_interfaces::srv::GripperCommand_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<z1_interfaces::srv::GripperCommand_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__z1_interfaces__srv__GripperCommand_Response
    std::shared_ptr<z1_interfaces::srv::GripperCommand_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__z1_interfaces__srv__GripperCommand_Response
    std::shared_ptr<z1_interfaces::srv::GripperCommand_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GripperCommand_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const GripperCommand_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GripperCommand_Response_

// alias to use template instance with default allocator
using GripperCommand_Response =
  z1_interfaces::srv::GripperCommand_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace z1_interfaces

namespace z1_interfaces
{

namespace srv
{

struct GripperCommand
{
  using Request = z1_interfaces::srv::GripperCommand_Request;
  using Response = z1_interfaces::srv::GripperCommand_Response;
};

}  // namespace srv

}  // namespace z1_interfaces

#endif  // Z1_INTERFACES__SRV__DETAIL__GRIPPER_COMMAND__STRUCT_HPP_
