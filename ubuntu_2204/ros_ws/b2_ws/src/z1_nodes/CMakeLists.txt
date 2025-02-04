cmake_minimum_required(VERSION 3.8)
project(z1_nodes)

# Encontrar dependências do ROS 2
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(z1_interfaces REQUIRED)

# Configurações de compilação
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Diretórios com bibliotecas compartilhadas (caminho absoluto corrigido)
link_directories(/z1_sdk/lib /z1_controller/lib)

# Encontrar dependências do Boost e Eigen
find_package(Boost REQUIRED)
find_package(Eigen3 REQUIRED)

# Diretórios de includes
include_directories(
    ${Boost_INCLUDE_DIRS}
    ${Eigen3_INCLUDE_DIRS}
    msg
    include  
    /z1_sdk/include   
    /z1_controller/include  
)

# Adicionar executáveis CPPs
add_executable(z1_manager src/z1_manager.cpp)
target_link_libraries(z1_manager
  /z1_sdk/lib/libZ1_SDK_x86_64.so
  /z1_controller/lib/libZ1_x86_64.so)
ament_target_dependencies(z1_manager rclcpp sensor_msgs std_msgs z1_interfaces)

add_executable(z1_parse_joint_state src/z1_parse_joint_state.cpp)
ament_target_dependencies(z1_parse_joint_state rclcpp sensor_msgs)

# Instalar executáveis
install(
  TARGETS 
  z1_manager
  z1_parse_joint_state
  DESTINATION lib/${PROJECT_NAME}
)

# Instalar scripts Python
install(PROGRAMS
  scripts/z1_motor_state_publisher.py
  DESTINATION lib/${PROJECT_NAME}
)

# Instalar bibliotecas e fontes
install(
  DIRECTORY lib
  DESTINATION lib
)

install(
  DIRECTORY src
  DESTINATION share/${PROJECT_NAME}
)

install(
  DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

# Configuração de testes (caso aplicável)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# Finalizar configuração do pacote
ament_package()