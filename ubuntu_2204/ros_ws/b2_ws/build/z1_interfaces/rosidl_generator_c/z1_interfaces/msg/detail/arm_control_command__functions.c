// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from z1_interfaces:msg/ArmControlCommand.idl
// generated code does not contain a copyright notice
#include "z1_interfaces/msg/detail/arm_control_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
z1_interfaces__msg__ArmControlCommand__init(z1_interfaces__msg__ArmControlCommand * msg)
{
  if (!msg) {
    return false;
  }
  // directions
  // speed_1
  // speed_2
  // cartesian
  return true;
}

void
z1_interfaces__msg__ArmControlCommand__fini(z1_interfaces__msg__ArmControlCommand * msg)
{
  if (!msg) {
    return;
  }
  // directions
  // speed_1
  // speed_2
  // cartesian
}

bool
z1_interfaces__msg__ArmControlCommand__are_equal(const z1_interfaces__msg__ArmControlCommand * lhs, const z1_interfaces__msg__ArmControlCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // directions
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->directions[i] != rhs->directions[i]) {
      return false;
    }
  }
  // speed_1
  if (lhs->speed_1 != rhs->speed_1) {
    return false;
  }
  // speed_2
  if (lhs->speed_2 != rhs->speed_2) {
    return false;
  }
  // cartesian
  if (lhs->cartesian != rhs->cartesian) {
    return false;
  }
  return true;
}

bool
z1_interfaces__msg__ArmControlCommand__copy(
  const z1_interfaces__msg__ArmControlCommand * input,
  z1_interfaces__msg__ArmControlCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // directions
  for (size_t i = 0; i < 7; ++i) {
    output->directions[i] = input->directions[i];
  }
  // speed_1
  output->speed_1 = input->speed_1;
  // speed_2
  output->speed_2 = input->speed_2;
  // cartesian
  output->cartesian = input->cartesian;
  return true;
}

z1_interfaces__msg__ArmControlCommand *
z1_interfaces__msg__ArmControlCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  z1_interfaces__msg__ArmControlCommand * msg = (z1_interfaces__msg__ArmControlCommand *)allocator.allocate(sizeof(z1_interfaces__msg__ArmControlCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(z1_interfaces__msg__ArmControlCommand));
  bool success = z1_interfaces__msg__ArmControlCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
z1_interfaces__msg__ArmControlCommand__destroy(z1_interfaces__msg__ArmControlCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    z1_interfaces__msg__ArmControlCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
z1_interfaces__msg__ArmControlCommand__Sequence__init(z1_interfaces__msg__ArmControlCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  z1_interfaces__msg__ArmControlCommand * data = NULL;

  if (size) {
    data = (z1_interfaces__msg__ArmControlCommand *)allocator.zero_allocate(size, sizeof(z1_interfaces__msg__ArmControlCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = z1_interfaces__msg__ArmControlCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        z1_interfaces__msg__ArmControlCommand__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
z1_interfaces__msg__ArmControlCommand__Sequence__fini(z1_interfaces__msg__ArmControlCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      z1_interfaces__msg__ArmControlCommand__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

z1_interfaces__msg__ArmControlCommand__Sequence *
z1_interfaces__msg__ArmControlCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  z1_interfaces__msg__ArmControlCommand__Sequence * array = (z1_interfaces__msg__ArmControlCommand__Sequence *)allocator.allocate(sizeof(z1_interfaces__msg__ArmControlCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = z1_interfaces__msg__ArmControlCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
z1_interfaces__msg__ArmControlCommand__Sequence__destroy(z1_interfaces__msg__ArmControlCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    z1_interfaces__msg__ArmControlCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
z1_interfaces__msg__ArmControlCommand__Sequence__are_equal(const z1_interfaces__msg__ArmControlCommand__Sequence * lhs, const z1_interfaces__msg__ArmControlCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!z1_interfaces__msg__ArmControlCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
z1_interfaces__msg__ArmControlCommand__Sequence__copy(
  const z1_interfaces__msg__ArmControlCommand__Sequence * input,
  z1_interfaces__msg__ArmControlCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(z1_interfaces__msg__ArmControlCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    z1_interfaces__msg__ArmControlCommand * data =
      (z1_interfaces__msg__ArmControlCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!z1_interfaces__msg__ArmControlCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          z1_interfaces__msg__ArmControlCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!z1_interfaces__msg__ArmControlCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
