// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from z1_interfaces:msg/ArmControlCommand.idl
// generated code does not contain a copyright notice

#ifndef Z1_INTERFACES__MSG__DETAIL__ARM_CONTROL_COMMAND__STRUCT_HPP_
#define Z1_INTERFACES__MSG__DETAIL__ARM_CONTROL_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__z1_interfaces__msg__ArmControlCommand __attribute__((deprecated))
#else
# define DEPRECATED__z1_interfaces__msg__ArmControlCommand __declspec(deprecated)
#endif

namespace z1_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ArmControlCommand_
{
  using Type = ArmControlCommand_<ContainerAllocator>;

  explicit ArmControlCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 7>::iterator, double>(this->directions.begin(), this->directions.end(), 0.0);
      this->speed_1 = 0.0;
      this->speed_2 = 0.0;
      this->cartesian = false;
    }
  }

  explicit ArmControlCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : directions(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 7>::iterator, double>(this->directions.begin(), this->directions.end(), 0.0);
      this->speed_1 = 0.0;
      this->speed_2 = 0.0;
      this->cartesian = false;
    }
  }

  // field types and members
  using _directions_type =
    std::array<double, 7>;
  _directions_type directions;
  using _speed_1_type =
    double;
  _speed_1_type speed_1;
  using _speed_2_type =
    double;
  _speed_2_type speed_2;
  using _cartesian_type =
    bool;
  _cartesian_type cartesian;

  // setters for named parameter idiom
  Type & set__directions(
    const std::array<double, 7> & _arg)
  {
    this->directions = _arg;
    return *this;
  }
  Type & set__speed_1(
    const double & _arg)
  {
    this->speed_1 = _arg;
    return *this;
  }
  Type & set__speed_2(
    const double & _arg)
  {
    this->speed_2 = _arg;
    return *this;
  }
  Type & set__cartesian(
    const bool & _arg)
  {
    this->cartesian = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    z1_interfaces::msg::ArmControlCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const z1_interfaces::msg::ArmControlCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<z1_interfaces::msg::ArmControlCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<z1_interfaces::msg::ArmControlCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      z1_interfaces::msg::ArmControlCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<z1_interfaces::msg::ArmControlCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      z1_interfaces::msg::ArmControlCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<z1_interfaces::msg::ArmControlCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<z1_interfaces::msg::ArmControlCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<z1_interfaces::msg::ArmControlCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__z1_interfaces__msg__ArmControlCommand
    std::shared_ptr<z1_interfaces::msg::ArmControlCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__z1_interfaces__msg__ArmControlCommand
    std::shared_ptr<z1_interfaces::msg::ArmControlCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmControlCommand_ & other) const
  {
    if (this->directions != other.directions) {
      return false;
    }
    if (this->speed_1 != other.speed_1) {
      return false;
    }
    if (this->speed_2 != other.speed_2) {
      return false;
    }
    if (this->cartesian != other.cartesian) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmControlCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmControlCommand_

// alias to use template instance with default allocator
using ArmControlCommand =
  z1_interfaces::msg::ArmControlCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace z1_interfaces

#endif  // Z1_INTERFACES__MSG__DETAIL__ARM_CONTROL_COMMAND__STRUCT_HPP_
