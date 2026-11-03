cmake_minimum_required(VERSION 3.8)
project(obstacle_example)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# MoveIt 2
find_package(moveit_core REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(moveit_msgs REQUIRED)

# Geometry / meshes
find_package(geometric_shapes REQUIRED)
find_package(shape_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

## INCLUDE(S)
include_directories(include)

# executables
add_executable(obstacle_example src/obstacle_example.cpp)

# dependencies
ament_target_dependencies(obstacle_example
  rclcpp
  moveit_core
  moveit_ros_planning_interface
  moveit_msgs
  geometric_shapes
  shape_msgs
  geometry_msgs
)

install(TARGETS obstacle_example
  DESTINATION lib/${PROJECT_NAME})

ament_package()
