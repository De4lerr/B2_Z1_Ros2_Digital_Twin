// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from z1_interfaces:srv/MoveJointPathCommand.idl
// generated code does not contain a copyright notice
#include "z1_interfaces/srv/detail/move_joint_path_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
z1_interfaces__srv__MoveJointPathCommand_Request__init(z1_interfaces__srv__MoveJointPathCommand_Request * msg)
{
  if (!msg) {
    return false;
  }
  // posture
  // gripper_pos
  // max_speed
  return true;
}

void
z1_interfaces__srv__MoveJointPathCommand_Request__fini(z1_interfaces__srv__MoveJointPathCommand_Request * msg)
{
  if (!msg) {
    return;
  }
  // posture
  // gripper_pos
  // max_speed
}

bool
z1_interfaces__srv__MoveJointPathCommand_Request__are_equal(const z1_interfaces__srv__MoveJointPathCommand_Request * lhs, const z1_interfaces__srv__MoveJointPathCommand_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // posture
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->posture[i] != rhs->posture[i]) {
      return false;
    }
  }
  // gripper_pos
  if (lhs->gripper_pos != rhs->gripper_pos) {
    return false;
  }
  // max_speed
  if (lhs->max_speed != rhs->max_speed) {
    return false;
  }
  return true;
}

bool
z1_interfaces__srv__MoveJointPathCommand_Request__copy(
  const z1_interfaces__srv__MoveJointPathCommand_Request * input,
  z1_interfaces__srv__MoveJointPathCommand_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // posture
  for (size_t i = 0; i < 6; ++i) {
    output->posture[i] = input->posture[i];
  }
  // gripper_pos
  output->gripper_pos = input->gripper_pos;
  // max_speed
  output->max_speed = input->max_speed;
  return true;
}

z1_interfaces__srv__MoveJointPathCommand_Request *
z1_interfaces__srv__MoveJointPathCommand_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  z1_interfaces__srv__MoveJointPathCommand_Request * msg = (z1_interfaces__srv__MoveJointPathCommand_Request *)allocator.allocate(sizeof(z1_interfaces__srv__MoveJointPathCommand_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(z1_interfaces__srv__MoveJointPathCommand_Request));
  bool success = z1_interfaces__srv__MoveJointPathCommand_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
z1_interfaces__srv__MoveJointPathCommand_Request__destroy(z1_interfaces__srv__MoveJointPathCommand_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    z1_interfaces__srv__MoveJointPathCommand_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
z1_interfaces__srv__MoveJointPathCommand_Request__Sequence__init(z1_interfaces__srv__MoveJointPathCommand_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  z1_interfaces__srv__MoveJointPathCommand_Request * data = NULL;

  if (size) {
    data = (z1_interfaces__srv__MoveJointPathCommand_Request *)allocator.zero_allocate(size, sizeof(z1_interfaces__srv__MoveJointPathCommand_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = z1_interfaces__srv__MoveJointPathCommand_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        z1_interfaces__srv__MoveJointPathCommand_Request__fini(&data[i - 1]);
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
z1_interfaces__srv__MoveJointPathCommand_Request__Sequence__fini(z1_interfaces__srv__MoveJointPathCommand_Request__Sequence * array)
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
      z1_interfaces__srv__MoveJointPathCommand_Request__fini(&array->data[i]);
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

z1_interfaces__srv__MoveJointPathCommand_Request__Sequence *
z1_interfaces__srv__MoveJointPathCommand_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  z1_interfaces__srv__MoveJointPathCommand_Request__Sequence * array = (z1_interfaces__srv__MoveJointPathCommand_Request__Sequence *)allocator.allocate(sizeof(z1_interfaces__srv__MoveJointPathCommand_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = z1_interfaces__srv__MoveJointPathCommand_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
z1_interfaces__srv__MoveJointPathCommand_Request__Sequence__destroy(z1_interfaces__srv__MoveJointPathCommand_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    z1_interfaces__srv__MoveJointPathCommand_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
z1_interfaces__srv__MoveJointPathCommand_Request__Sequence__are_equal(const z1_interfaces__srv__MoveJointPathCommand_Request__Sequence * lhs, const z1_interfaces__srv__MoveJointPathCommand_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!z1_interfaces__srv__MoveJointPathCommand_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
z1_interfaces__srv__MoveJointPathCommand_Request__Sequence__copy(
  const z1_interfaces__srv__MoveJointPathCommand_Request__Sequence * input,
  z1_interfaces__srv__MoveJointPathCommand_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(z1_interfaces__srv__MoveJointPathCommand_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    z1_interfaces__srv__MoveJointPathCommand_Request * data =
      (z1_interfaces__srv__MoveJointPathCommand_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!z1_interfaces__srv__MoveJointPathCommand_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          z1_interfaces__srv__MoveJointPathCommand_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!z1_interfaces__srv__MoveJointPathCommand_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
z1_interfaces__srv__MoveJointPathCommand_Response__init(z1_interfaces__srv__MoveJointPathCommand_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    z1_interfaces__srv__MoveJointPathCommand_Response__fini(msg);
    return false;
  }
  return true;
}

void
z1_interfaces__srv__MoveJointPathCommand_Response__fini(z1_interfaces__srv__MoveJointPathCommand_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
z1_interfaces__srv__MoveJointPathCommand_Response__are_equal(const z1_interfaces__srv__MoveJointPathCommand_Response * lhs, const z1_interfaces__srv__MoveJointPathCommand_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
z1_interfaces__srv__MoveJointPathCommand_Response__copy(
  const z1_interfaces__srv__MoveJointPathCommand_Response * input,
  z1_interfaces__srv__MoveJointPathCommand_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

z1_interfaces__srv__MoveJointPathCommand_Response *
z1_interfaces__srv__MoveJointPathCommand_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  z1_interfaces__srv__MoveJointPathCommand_Response * msg = (z1_interfaces__srv__MoveJointPathCommand_Response *)allocator.allocate(sizeof(z1_interfaces__srv__MoveJointPathCommand_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(z1_interfaces__srv__MoveJointPathCommand_Response));
  bool success = z1_interfaces__srv__MoveJointPathCommand_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
z1_interfaces__srv__MoveJointPathCommand_Response__destroy(z1_interfaces__srv__MoveJointPathCommand_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    z1_interfaces__srv__MoveJointPathCommand_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
z1_interfaces__srv__MoveJointPathCommand_Response__Sequence__init(z1_interfaces__srv__MoveJointPathCommand_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  z1_interfaces__srv__MoveJointPathCommand_Response * data = NULL;

  if (size) {
    data = (z1_interfaces__srv__MoveJointPathCommand_Response *)allocator.zero_allocate(size, sizeof(z1_interfaces__srv__MoveJointPathCommand_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = z1_interfaces__srv__MoveJointPathCommand_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        z1_interfaces__srv__MoveJointPathCommand_Response__fini(&data[i - 1]);
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
z1_interfaces__srv__MoveJointPathCommand_Response__Sequence__fini(z1_interfaces__srv__MoveJointPathCommand_Response__Sequence * array)
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
      z1_interfaces__srv__MoveJointPathCommand_Response__fini(&array->data[i]);
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

z1_interfaces__srv__MoveJointPathCommand_Response__Sequence *
z1_interfaces__srv__MoveJointPathCommand_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  z1_interfaces__srv__MoveJointPathCommand_Response__Sequence * array = (z1_interfaces__srv__MoveJointPathCommand_Response__Sequence *)allocator.allocate(sizeof(z1_interfaces__srv__MoveJointPathCommand_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = z1_interfaces__srv__MoveJointPathCommand_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
z1_interfaces__srv__MoveJointPathCommand_Response__Sequence__destroy(z1_interfaces__srv__MoveJointPathCommand_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    z1_interfaces__srv__MoveJointPathCommand_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
z1_interfaces__srv__MoveJointPathCommand_Response__Sequence__are_equal(const z1_interfaces__srv__MoveJointPathCommand_Response__Sequence * lhs, const z1_interfaces__srv__MoveJointPathCommand_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!z1_interfaces__srv__MoveJointPathCommand_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
z1_interfaces__srv__MoveJointPathCommand_Response__Sequence__copy(
  const z1_interfaces__srv__MoveJointPathCommand_Response__Sequence * input,
  z1_interfaces__srv__MoveJointPathCommand_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(z1_interfaces__srv__MoveJointPathCommand_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    z1_interfaces__srv__MoveJointPathCommand_Response * data =
      (z1_interfaces__srv__MoveJointPathCommand_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!z1_interfaces__srv__MoveJointPathCommand_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          z1_interfaces__srv__MoveJointPathCommand_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!z1_interfaces__srv__MoveJointPathCommand_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
