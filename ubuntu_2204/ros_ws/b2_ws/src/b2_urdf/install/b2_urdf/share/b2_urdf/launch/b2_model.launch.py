import launch
import launch_ros
import os


def generate_launch_description():

    pkgPath = launch_ros.substitutions.FindPackageShare(package='b2_urdf').find('b2_urdf')
    urdfModelPath=os.path.join(pkgPath, 'urdf/b2_description.urdf')

    print(urdfModelPath)
    with open(urdfModelPath,'r') as infp:
        robot_desc=infp.read()

    params = {'b2_description':robot_desc}

    robot_state_publisher_node=launch_ros.actions.Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[params],
        arguments=[urdfModelPath]
    )

    joint_state_publisher_node=launch_ros.actions.Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        name='joint_state_publisher',
        parameters=[params],
        arguments=[urdfModelPath]
    )

    # Run the node
    return launch.LaunchDescription([
        robot_state_publisher_node,
        joint_state_publisher_node,
    ])