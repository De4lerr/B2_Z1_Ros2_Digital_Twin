// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from z1_interfaces:srv/GripperCommand.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "z1_interfaces/srv/detail/gripper_command__struct.h"
#include "z1_interfaces/srv/detail/gripper_command__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool z1_interfaces__srv__gripper_command__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[58];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("z1_interfaces.srv._gripper_command.GripperCommand_Request", full_classname_dest, 57) == 0);
  }
  z1_interfaces__srv__GripperCommand_Request * ros_message = _ros_message;
  {  // gripper_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "gripper_pos");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gripper_pos = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gripper_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "gripper_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gripper_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gripper_tau
    PyObject * field = PyObject_GetAttrString(_pymsg, "gripper_tau");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gripper_tau = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * z1_interfaces__srv__gripper_command__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GripperCommand_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("z1_interfaces.srv._gripper_command");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GripperCommand_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  z1_interfaces__srv__GripperCommand_Request * ros_message = (z1_interfaces__srv__GripperCommand_Request *)raw_ros_message;
  {  // gripper_pos
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gripper_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gripper_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gripper_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gripper_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gripper_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gripper_tau
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gripper_tau);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gripper_tau", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "z1_interfaces/srv/detail/gripper_command__struct.h"
// already included above
// #include "z1_interfaces/srv/detail/gripper_command__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool z1_interfaces__srv__gripper_command__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[59];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("z1_interfaces.srv._gripper_command.GripperCommand_Response", full_classname_dest, 58) == 0);
  }
  z1_interfaces__srv__GripperCommand_Response * ros_message = _ros_message;
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }
  {  // message
    PyObject * field = PyObject_GetAttrString(_pymsg, "message");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->message, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * z1_interfaces__srv__gripper_command__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GripperCommand_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("z1_interfaces.srv._gripper_command");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GripperCommand_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  z1_interfaces__srv__GripperCommand_Response * ros_message = (z1_interfaces__srv__GripperCommand_Response *)raw_ros_message;
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // message
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->message.data,
      strlen(ros_message->message.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "message", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
