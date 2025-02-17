# generated from rosidl_generator_py/resource/_idl.py.em
# with input from z1_interfaces:msg/ArmControlCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'directions'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ArmControlCommand(type):
    """Metaclass of message 'ArmControlCommand'."""

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
                'z1_interfaces.msg.ArmControlCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__arm_control_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__arm_control_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__arm_control_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__arm_control_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__arm_control_command

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ArmControlCommand(metaclass=Metaclass_ArmControlCommand):
    """Message class 'ArmControlCommand'."""

    __slots__ = [
        '_directions',
        '_speed_1',
        '_speed_2',
        '_cartesian',
    ]

    _fields_and_field_types = {
        'directions': 'double[7]',
        'speed_1': 'double',
        'speed_2': 'double',
        'cartesian': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'directions' not in kwargs:
            self.directions = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.directions = numpy.array(kwargs.get('directions'), dtype=numpy.float64)
            assert self.directions.shape == (7, )
        self.speed_1 = kwargs.get('speed_1', float())
        self.speed_2 = kwargs.get('speed_2', float())
        self.cartesian = kwargs.get('cartesian', bool())

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
        if all(self.directions != other.directions):
            return False
        if self.speed_1 != other.speed_1:
            return False
        if self.speed_2 != other.speed_2:
            return False
        if self.cartesian != other.cartesian:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def directions(self):
        """Message field 'directions'."""
        return self._directions

    @directions.setter
    def directions(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'directions' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 7, \
                "The 'directions' numpy.ndarray() must have a size of 7"
            self._directions = value
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
                 len(value) == 7 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'directions' field must be a set or sequence with length 7 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._directions = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def speed_1(self):
        """Message field 'speed_1'."""
        return self._speed_1

    @speed_1.setter
    def speed_1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed_1' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'speed_1' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._speed_1 = value

    @builtins.property
    def speed_2(self):
        """Message field 'speed_2'."""
        return self._speed_2

    @speed_2.setter
    def speed_2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed_2' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'speed_2' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._speed_2 = value

    @builtins.property
    def cartesian(self):
        """Message field 'cartesian'."""
        return self._cartesian

    @cartesian.setter
    def cartesian(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'cartesian' field must be of type 'bool'"
        self._cartesian = value
