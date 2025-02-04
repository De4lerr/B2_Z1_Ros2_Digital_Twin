from setuptools import find_packages, setup

package_name = 'b2_nodes'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools',
                      'unitree_sdk2py'
                      'cyclonedds'
                      'sensor_msgs'
                      'unitree'],
    zip_safe=True,
    maintainer='ros_ws',
    maintainer_email='dilermandoa7@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'parse_odometry = b2_nodes.parse_odometry:main',
            'parse_joint_state = b2_nodes.parse_joint_state:main',
            'print_joint_state = b2_nodes.print_joint_state:main',
            'parse_joint_state_z1_b2 = b2_nodes.parse_joint_state_z1_b2:main',
            'keyboard_control = b2_nodes.keyboard_control:main'
        ],
    },
)