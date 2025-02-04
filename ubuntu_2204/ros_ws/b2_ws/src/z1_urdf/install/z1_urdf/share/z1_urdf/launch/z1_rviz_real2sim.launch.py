import launch
from launch.substitutions import Command, LaunchConfiguration
import launch_ros
import os


def generate_launch_description():

    pkgPath = launch_ros.substitutions.FindPackageShare(package='b2_urdf').find('b2_urdf')
    urdfModelPath=os.path.join(pkgPath, 'urdf/b2_description.urdf')
    rvizConfigPath=os.path.join(pkgPath, 'config/config.rviz')

    use_sim_time=LaunchConfiguration('use_sim_time',default='false')

    print(urdfModelPath)
    with open(urdfModelPath,'r') as infp:
        robot_desc=infp.read()

    params = {'b2_description':robot_desc}

    robot_state_publisher_node=launch_ros.actions.Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[{'use_sim_time':use_sim_time,'b2_description':robot_desc}],
        arguments=[urdfModelPath]
    )

    joint_state_publisher_node=launch_ros.actions.Node(
        package='b2_nodes',
        executable='parse_joint_state',
        name='parse_joint_state',
        parameters=[params],
        arguments=[urdfModelPath]
    )

    odommetry_publisher_node=launch_ros.actions.Node(
        package='b2_nodes',
        executable='parse_odometry',
        name='parse_odometry',
        parameters=[params],
        arguments=[urdfModelPath]
    )

    rviz_node=launch_ros.actions.Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d',rvizConfigPath]
    )

    # Run the node
    return launch.LaunchDescription([
        launch.actions.DeclareLaunchArgument(name='gui',default_value='True',
                                            description='Flag for joint_state_publisher_gui'),
        robot_state_publisher_node,
        joint_state_publisher_node,
        odommetry_publisher_node,
        rviz_node,
    ])