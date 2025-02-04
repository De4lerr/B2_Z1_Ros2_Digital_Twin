// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from z1_interfaces:srv/MoveCircularPathCommand.idl
// generated code does not contain a copyright notice

#ifndef Z1_INTERFACES__SRV__DETAIL__MOVE_CIRCULAR_PATH_COMMAND__STRUCT_HPP_
#define Z1_INTERFACES__SRV__DETAIL__MOVE_CIRCULAR_PATH_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__z1_interfaces__srv__MoveCircularPathCommand_Request __attribute__((deprecated))
#else
# define DEPRECATED__z1_interfaces__srv__MoveCircularPathCommand_Request __declspec(deprecated)
#endif

namespace z1_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveCircularPathCommand_Request_
{
  using Type = MoveCircularPathCommand_Request_<ContainerAllocator>;

  explicit MoveCircularPathCommand_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 6>::iterator, double>(this->middle_posture.begin(), this->middle_posture.end(), 0.0);
      std::fill<typename std::array<double, 6>::iterator, double>(this->end_posture.begin(), this->end_posture.end(), 0.0);
      this->gripper_pos = 0.0;
      this->max_speed = 0.0;
    }
  }

  explicit MoveCircularPathCommand_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : middle_posture(_alloc),
    end_posture(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 6>::iterator, double>(this->middle_posture.begin(), this->middle_posture.end(), 0.0);
      std::fill<typename std::array<double, 6>::iterator, double>(this->end_posture.begin(), this->end_posture.end(), 0.0);
      this->gripper_pos = 0.0;
      this->max_speed = 0.0;
    }
  }

  // field types and members
  using _middle_posture_type =
    std::array<double, 6>;
  _middle_posture_type middle_posture;
  using _end_posture_type =
    std::array<double, 6>;
  _end_posture_type end_posture;
  using _gripper_pos_type =
    double;
  _gripper_pos_type gripper_pos;
  using _max_speed_type =
    double;
  _max_speed_type max_speed;

  // setters for named parameter idiom
  Type & set__middle_posture(
    const std::array<double, 6> & _arg)
  {
    this->middle_posture = _arg;
    return *this;
  }
  Type & set__end_posture(
    const std::array<double, 6> & _arg)
  {
    this->end_posture = _arg;
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
    z1_interfaces::srv::MoveCircularPathCommand_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const z1_interfaces::srv::MoveCircularPathCommand_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<z1_interfaces::srv::MoveCircularPathCommand_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<z1_interfaces::srv::MoveCircularPathCommand_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      z1_interfaces::srv::MoveCircularPathCommand_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<z1_interfaces::srv::MoveCircularPathCommand_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      z1_interfaces::srv::MoveCircularPathCommand_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<z1_interfaces::srv::MoveCircularPathCommand_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<z1_interfaces::srv::MoveCircularPathCommand_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<z1_interfaces::srv::MoveCircularPathCommand_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__z1_interfaces__srv__MoveCircularPathCommand_Request
    std::shared_ptr<z1_interfaces::srv::MoveCircularPathCommand_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__z1_interfaces__srv__MoveCircularPathCommand_Request
    std::shared_ptr<z1_interfaces::srv::MoveCircularPathCommand_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveCircularPathCommand_Request_ & other) const
  {
    if (this->middle_posture != other.middle_posture) {
      return false;
    }
    if (this->end_posture != other.end_posture) {
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
  bool operator!=(const MoveCircularPathCommand_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveCircularPathCommand_Request_

// alias to use template instance with default allocator
using MoveCircularPathCommand_Request =
  z1_interfaces::srv::MoveCircularPathCommand_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace z1_interfaces


#ifndef _WIN32
# define DEPRECATED__z1_interfaces__srv__MoveCircularPathCommand_Response __attribute__((deprecated))
#else
# define DEPRECATED__z1_interfaces__srv__MoveCircularPathCommand_Response __declspec(deprecated)
#endif

namespace z1_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveCircularPathCommand_Response_
{
  using Type = MoveCircularPathCommand_Response_<ContainerAllocator>;

  explicit MoveCircularPathCommand_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit MoveCircularPathCommand_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    z1_interfaces::srv::MoveCircularPathCommand_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const z1_interfaces::srv::MoveCircularPathCommand_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<z1_interfaces::srv::MoveCircularPathCommand_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<z1_interfaces::srv::MoveCircularPathCommand_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      z1_interfaces::srv::MoveCircularPathCommand_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<z1_interfaces::srv::MoveCircularPathCommand_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      z1_interfaces::srv::MoveCircularPathCommand_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<z1_interfaces::srv::MoveCircularPathCommand_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<z1_interfaces::srv::MoveCircularPathCommand_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<z1_interfaces::srv::MoveCircularPathCommand_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__z1_interfaces__srv__MoveCircularPathCommand_Response
    std::shared_ptr<z1_interfaces::srv::MoveCircularPathCommand_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__z1_interfaces__srv__MoveCircularPathCommand_Response
    std::shared_ptr<z1_interfaces::srv::MoveCircularPathCommand_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveCircularPathCommand_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveCircularPathCommand_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveCircularPathCommand_Response_

// alias to use template instance with default allocator
using MoveCircularPathCommand_Response =
  z1_interfaces::srv::MoveCircularPathCommand_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace z1_interfaces

namespace z1_interfaces
{

namespace srv
{

struct MoveCircularPathCommand
{
  using Request = z1_interfaces::srv::MoveCircularPathCommand_Request;
  using Response = z1_interfaces::srv::MoveCircularPathCommand_Response;
};

}  // namespace srv

}  // namespace z1_interfaces

#endif  // Z1_INTERFACES__SRV__DETAIL__MOVE_CIRCULAR_PATH_COMMAND__STRUCT_HPP_
