cmake_minimum_required(VERSION 3.8)
project(z1_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(sensor_msgs REQUIRED)

# Gerar as mensagens
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/ArmControlCommand.msg"
  "srv/GripperCommand.srv"
  "srv/MoveCircularPathCommand.srv"
  "srv/MoveLinearPathCommand.srv"
  "srv/MoveJointPathCommand.srv"
  "srv/NoInputCommand.srv"
  DEPENDENCIES std_msgs
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# Finalizar configuração do pacote

ament_export_dependencies(rosidl_default_runtime)
ament_package()