import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/ros_ws/ros_ws/b2_ws/install/b2_nodes'
