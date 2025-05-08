# generated from rosidl_generator_py/resource/_idl.py.em
# with input from gaussian_interface:msg/SingleGaussian.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'spherical_harmonics'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SingleGaussian(type):
    """Metaclass of message 'SingleGaussian'."""

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
            module = import_type_support('gaussian_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'gaussian_interface.msg.SingleGaussian')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__single_gaussian
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__single_gaussian
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__single_gaussian
            cls._TYPE_SUPPORT = module.type_support_msg__msg__single_gaussian
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__single_gaussian

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from geometry_msgs.msg import Quaternion
            if Quaternion.__class__._TYPE_SUPPORT is None:
                Quaternion.__class__.__import_type_support__()

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SingleGaussian(metaclass=Metaclass_SingleGaussian):
    """Message class 'SingleGaussian'."""

    __slots__ = [
        '_xyz',
        '_rotation',
        '_scale',
        '_opacity',
        '_spherical_harmonics',
    ]

    _fields_and_field_types = {
        'xyz': 'geometry_msgs/Point',
        'rotation': 'geometry_msgs/Quaternion',
        'scale': 'geometry_msgs/Vector3',
        'opacity': 'float',
        'spherical_harmonics': 'sequence<float>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Quaternion'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Point
        self.xyz = kwargs.get('xyz', Point())
        from geometry_msgs.msg import Quaternion
        self.rotation = kwargs.get('rotation', Quaternion())
        from geometry_msgs.msg import Vector3
        self.scale = kwargs.get('scale', Vector3())
        self.opacity = kwargs.get('opacity', float())
        self.spherical_harmonics = array.array('f', kwargs.get('spherical_harmonics', []))

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
        if self.xyz != other.xyz:
            return False
        if self.rotation != other.rotation:
            return False
        if self.scale != other.scale:
            return False
        if self.opacity != other.opacity:
            return False
        if self.spherical_harmonics != other.spherical_harmonics:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def xyz(self):
        """Message field 'xyz'."""
        return self._xyz

    @xyz.setter
    def xyz(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'xyz' field must be a sub message of type 'Point'"
        self._xyz = value

    @builtins.property
    def rotation(self):
        """Message field 'rotation'."""
        return self._rotation

    @rotation.setter
    def rotation(self, value):
        if __debug__:
            from geometry_msgs.msg import Quaternion
            assert \
                isinstance(value, Quaternion), \
                "The 'rotation' field must be a sub message of type 'Quaternion'"
        self._rotation = value

    @builtins.property
    def scale(self):
        """Message field 'scale'."""
        return self._scale

    @scale.setter
    def scale(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'scale' field must be a sub message of type 'Vector3'"
        self._scale = value

    @builtins.property
    def opacity(self):
        """Message field 'opacity'."""
        return self._opacity

    @opacity.setter
    def opacity(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'opacity' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'opacity' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._opacity = value

    @builtins.property
    def spherical_harmonics(self):
        """Message field 'spherical_harmonics'."""
        return self._spherical_harmonics

    @spherical_harmonics.setter
    def spherical_harmonics(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'spherical_harmonics' array.array() must have the type code of 'f'"
            self._spherical_harmonics = value
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'spherical_harmonics' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._spherical_harmonics = array.array('f', value)
