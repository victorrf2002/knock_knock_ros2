cmake_minimum_required(VERSION 3.8)
project(knock_knock)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# Include C++ "include" directory
include_directories(include)

# Create C++ executable
add_executable(publisher src/knock_cpp_pub.cpp)
ament_target_dependencies(publisher rclcpp)

# Install C++ executables
install(TARGETS
  publisher
  DESTINATION lib/${PROJECT_NAME}
)

# Install Python modules
ament_python_install_package(${PROJECT_NAME})

# Install Python executables
install(PROGRAMS
  scripts/py_node.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
