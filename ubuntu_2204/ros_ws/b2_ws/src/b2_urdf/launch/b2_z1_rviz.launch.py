import launch
from launch.substitutions import Command, LaunchConfiguration
import launch_ros
import os

def generate_launch_description():

    pkgPath = launch_ros.substitutions.FindPackageShare(package='b2_urdf').find('b2_urdf')
    xacroFilePath = os.path.join(pkgPath, 'urdf/b2_with_z1.xacro')  # Arquivo Xacro
    rvizConfigPath = os.path.join(pkgPath, 'config/config.rviz')

    use_sim_time = LaunchConfiguration('use_sim_time', default='false')

    # Processa o arquivo Xacro para gerar o modelo URDF
    robot_desc = Command(['xacro ', xacroFilePath])

    params = {'robot_description': robot_desc}

    robot_state_publisher_node = launch_ros.actions.Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[{'use_sim_time': use_sim_time, 'robot_description': robot_desc}]
    )

    joint_state_publisher_node=launch_ros.actions.Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        name='joint_state_publisher',
        parameters=[params],
        #arguments=[urdfModelPath]
    )
    
    joint_state_publisher_gui_node=launch_ros.actions.Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='joint_state_publisher_gui',
        #arguments=[urdfModelPath],
        condition=launch.conditions.IfCondition(LaunchConfiguration('gui'))
    )

    rviz_node = launch_ros.actions.Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rvizConfigPath]
    )

    return launch.LaunchDescription([
        launch.actions.DeclareLaunchArgument(name='gui', default_value='True',
                                             description='Flag for joint_state_publisher_gui'),
        robot_state_publisher_node,
        joint_state_publisher_node,
        joint_state_publisher_gui_node,
        rviz_node,
    ])