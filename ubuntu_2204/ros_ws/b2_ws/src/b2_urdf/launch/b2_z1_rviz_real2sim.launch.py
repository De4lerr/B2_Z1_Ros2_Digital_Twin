import launch
from launch.substitutions import Command, LaunchConfiguration
import launch_ros
import os

def generate_launch_description():

    pkgPath = launch_ros.substitutions.FindPackageShare(package='b2_urdf').find('b2_urdf')
    xacroFilePath = os.path.join(pkgPath, 'urdf/b2_with_z1.xacro')  
    rvizConfigPath = os.path.join(pkgPath, 'config/config.rviz')

    use_sim_time = LaunchConfiguration('use_sim_time', default='false')

    robot_desc = Command(['xacro ', xacroFilePath])

    params = {'robot_description': robot_desc}

    robot_state_publisher_node = launch_ros.actions.Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[{'use_sim_time': use_sim_time, 'robot_description': robot_desc}]
    )

    get_joint_state_node=launch_ros.actions.Node(
        package='z1_nodes',
        executable='z1_manager',
        name='z1_manager',
        parameters=[params],
    )

    joint_state_publisher_node=launch_ros.actions.Node(
        package='b2_nodes',
        executable='parse_joint_state_z1_b2',
        name='parse_joint_state_z1_b2',
        parameters=[params],
    )

    odommetry_publisher_node=launch_ros.actions.Node(
        package='b2_nodes',
        executable='parse_odometry',
        name='parse_odometry',
        parameters=[params],
    )

    rviz_node=launch_ros.actions.Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d',rvizConfigPath]
    )

    return launch.LaunchDescription([
        launch.actions.DeclareLaunchArgument(name='gui',default_value='True',
                                            description='Flag for joint_state_publisher_gui'),
        robot_state_publisher_node,
        get_joint_state_node,
        joint_state_publisher_node,
        odommetry_publisher_node,
        rviz_node,
    ])