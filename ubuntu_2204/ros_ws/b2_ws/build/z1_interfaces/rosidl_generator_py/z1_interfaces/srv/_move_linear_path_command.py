# generated from rosidl_generator_py/resource/_idl.py.em
# with input from z1_interfaces:srv/MoveLinearPathCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'posture'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MoveLinearPathCommand_Request(type):
    """Metaclass of message 'MoveLinearPathCommand_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('z1_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'z1_interfaces.srv.MoveLinearPathCommand_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__move_linear_path_command__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__move_linear_path_command__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__move_linear_path_command__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__move_linear_path_command__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__move_linear_path_command__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveLinearPathCommand_Request(metaclass=Metaclass_MoveLinearPathCommand_Request):
    """Message class 'MoveLinearPathCommand_Request'."""

    __slots__ = [
        '_posture',
        '_gripper_pos',
        '_max_speed',
    ]

    _fields_and_field_types = {
        'posture': 'double[6]',
        'gripper_pos': 'double',
        'max_speed': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 6),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'posture' not in kwargs:
            self.posture = numpy.zeros(6, dtype=numpy.float64)
        else:
            self.posture = numpy.array(kwargs.get('posture'), dtype=numpy.float64)
            assert self.posture.shape == (6, )
        self.gripper_pos = kwargs.get('gripper_pos', float())
        self.max_speed = kwargs.get('max_speed', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if all(self.posture != other.posture):
            return False
        if self.gripper_pos != other.gripper_pos:
            return False
        if self.max_speed != other.max_speed:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def posture(self):
        """Message field 'posture'."""
        return self._posture

    @posture.setter
    def posture(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'posture' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 6, \
                "The 'posture' numpy.ndarray() must have a size of 6"
            self._posture = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 6 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'posture' field must be a set or sequence with length 6 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._posture = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def gripper_pos(self):
        """Message field 'gripper_pos'."""
        return self._gripper_pos

    @gripper_pos.setter
    def gripper_pos(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gripper_pos' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gripper_pos' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gripper_pos = value

    @builtins.property
    def max_speed(self):
        """Message field 'max_speed'."""
        return self._max_speed

    @max_speed.setter
    def max_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_speed' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_speed' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_speed = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveLinearPathCommand_Response(type):
    """Metaclass of message 'MoveLinearPathCommand_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('z1_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'z1_interfaces.srv.MoveLinearPathCommand_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__move_linear_path_command__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__move_linear_path_command__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__move_linear_path_command__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__move_linear_path_command__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__move_linear_path_command__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveLinearPathCommand_Response(metaclass=Metaclass_MoveLinearPathCommand_Response):
    """Message class 'MoveLinearPathCommand_Response'."""

    __slots__ = [
        '_success',
        '_message',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_MoveLinearPathCommand(type):
    """Metaclass of service 'MoveLinearPathCommand'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('z1_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'z1_interfaces.srv.MoveLinearPathCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__move_linear_path_command

            from z1_interfaces.srv import _move_linear_path_command
            if _move_linear_path_command.Metaclass_MoveLinearPathCommand_Request._TYPE_SUPPORT is None:
                _move_linear_path_command.Metaclass_MoveLinearPathCommand_Request.__import_type_support__()
            if _move_linear_path_command.Metaclass_MoveLinearPathCommand_Response._TYPE_SUPPORT is None:
                _move_linear_path_command.Metaclass_MoveLinearPathCommand_Response.__import_type_support__()


class MoveLinearPathCommand(metaclass=Metaclass_MoveLinearPathCommand):
    from z1_interfaces.srv._move_linear_path_command import MoveLinearPathCommand_Request as Request
    from z1_interfaces.srv._move_linear_path_command import MoveLinearPathCommand_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
