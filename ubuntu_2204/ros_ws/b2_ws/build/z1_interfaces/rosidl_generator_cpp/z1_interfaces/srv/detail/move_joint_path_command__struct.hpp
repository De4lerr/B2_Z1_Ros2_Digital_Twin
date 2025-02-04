// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from z1_interfaces:srv/MoveJointPathCommand.idl
// generated code does not contain a copyright notice

#ifndef Z1_INTERFACES__SRV__DETAIL__MOVE_JOINT_PATH_COMMAND__STRUCT_HPP_
#define Z1_INTERFACES__SRV__DETAIL__MOVE_JOINT_PATH_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__z1_interfaces__srv__MoveJointPathCommand_Request __attribute__((deprecated))
#else
# define DEPRECATED__z1_interfaces__srv__MoveJointPathCommand_Request __declspec(deprecated)
#endif

namespace z1_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveJointPathCommand_Request_
{
  using Type = MoveJointPathCommand_Request_<ContainerAllocator>;

  explicit MoveJointPathCommand_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 6>::iterator, double>(this->posture.begin(), this->posture.end(), 0.0);
      this->gripper_pos = 0.0;
      this->max_speed = 0.0;
    }
  }

  explicit MoveJointPathCommand_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : posture(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 6>::iterator, double>(this->posture.begin(), this->posture.end(), 0.0);
      this->gripper_pos = 0.0;
      this->max_speed = 0.0;
    }
  }

  // field types and members
  using _posture_type =
    std::array<double, 6>;
  _posture_type posture;
  using _gripper_pos_type =
    double;
  _gripper_pos_type gripper_pos;
  using _max_speed_type =
    double;
  _max_speed_type max_speed;

  // setters for named parameter idiom
  Type & set__posture(
    const std::array<double, 6> & _arg)
  {
    this->posture = _arg;
    return *this;
  }
  Type & set__gripper_pos(
    const double & _arg)
  {
    this->gripper_pos = _arg;
    return *this;
  }
  Type & set__max_speed(
    const double & _arg)
  {
    this->max_speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    z1_interfaces::srv::MoveJointPathCommand_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const z1_interfaces::srv::MoveJointPathCommand_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<z1_interfaces::srv::MoveJointPathCommand_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<z1_interfaces::srv::MoveJointPathCommand_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      z1_interfaces::srv::MoveJointPathCommand_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<z1_interfaces::srv::MoveJointPathCommand_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      z1_interfaces::srv::MoveJointPathCommand_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<z1_interfaces::srv::MoveJointPathCommand_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<z1_interfaces::srv::MoveJointPathCommand_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<z1_interfaces::srv::MoveJointPathCommand_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__z1_interfaces__srv__MoveJointPathCommand_Request
    std::shared_ptr<z1_interfaces::srv::MoveJointPathCommand_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__z1_interfaces__srv__MoveJointPathCommand_Request
    std::shared_ptr<z1_interfaces::srv::MoveJointPathCommand_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveJointPathCommand_Request_ & other) const
  {
    if (this->posture != other.posture) {
      return false;
    }
    if (this->gripper_pos != other.gripper_pos) {
      return false;
    }
    if (this->max_speed != other.max_speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveJointPathCommand_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveJointPathCommand_Request_

// alias to use template instance with default allocator
using MoveJointPathCommand_Request =
  z1_interfaces::srv::MoveJointPathCommand_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace z1_interfaces


#ifndef _WIN32
# define DEPRECATED__z1_interfaces__srv__MoveJointPathCommand_Response __attribute__((deprecated))
#else
# define DEPRECATED__z1_interfaces__srv__MoveJointPathCommand_Response __declspec(deprecated)
#endif

namespace z1_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveJointPathCommand_Response_
{
  using Type = MoveJointPathCommand_Response_<ContainerAllocator>;

  explicit MoveJointPathCommand_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit MoveJointPathCommand_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    z1_interfaces::srv::MoveJointPathCommand_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const z1_interfaces::srv::MoveJointPathCommand_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<z1_interfaces::srv::MoveJointPathCommand_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<z1_interfaces::srv::MoveJointPathCommand_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      z1_interfaces::srv::MoveJointPathCommand_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<z1_interfaces::srv::MoveJointPathCommand_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      z1_interfaces::srv::MoveJointPathCommand_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<z1_interfaces::srv::MoveJointPathCommand_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<z1_interfaces::srv::MoveJointPathCommand_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<z1_interfaces::srv::MoveJointPathCommand_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__z1_interfaces__srv__MoveJointPathCommand_Response
    std::shared_ptr<z1_interfaces::srv::MoveJointPathCommand_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__z1_interfaces__srv__MoveJointPathCommand_Response
    std::shared_ptr<z1_interfaces::srv::MoveJointPathCommand_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveJointPathCommand_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveJointPathCommand_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveJointPathCommand_Response_

// alias to use template instance with default allocator
using MoveJointPathCommand_Response =
  z1_interfaces::srv::MoveJointPathCommand_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace z1_interfaces

namespace z1_interfaces
{

namespace srv
{

struct MoveJointPathCommand
{
  using Request = z1_interfaces::srv::MoveJointPathCommand_Request;
  using Response = z1_interfaces::srv::MoveJointPathCommand_Response;
};

}  // namespace srv

}  // namespace z1_interfaces

#endif  // Z1_INTERFACES__SRV__DETAIL__MOVE_JOINT_PATH_COMMAND__STRUCT_HPP_
