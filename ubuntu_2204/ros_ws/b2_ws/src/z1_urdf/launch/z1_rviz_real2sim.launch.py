import launch
from launch.substitutions import Command, LaunchConfiguration
import launch_ros
import os


def generate_launch_description():

    pkgPath = launch_ros.substitutions.FindPackageShare(package='z1_urdf').find('z1_urdf')
    urdfModelPath=os.path.join(pkgPath, 'urdf/z1_description.urdf')
    rvizConfigPath=os.path.join(pkgPath, 'config/config.rviz')

    use_sim_time=LaunchConfiguration('use_sim_time',default='false')

    print(urdfModelPath)
    with open(urdfModelPath,'r') as infp:
        robot_desc=infp.read()

    params = {'z1_description':robot_desc}

    robot_state_publisher_node=launch_ros.actions.Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[{'use_sim_time':use_sim_time,'z1_description':robot_desc}],
        arguments=[urdfModelPath]
    )

    get_joint_state_node=launch_ros.actions.Node(
        package='z1_nodes',
        executable='z1_manager',
        name='z1_manager',
        parameters=[params],
        arguments=[urdfModelPath]
    )

    joint_state_publisher_node=launch_ros.actions.Node(
        package='z1_nodes',
        executable='z1_parse_joint_state',
        name='z1_parse_joint_state',
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
        robot_state_publisher_node,
        get_joint_state_node,
        joint_state_publisher_node,
        rviz_node,
    ])