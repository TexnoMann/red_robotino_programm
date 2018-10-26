cmake_minimum_required (VERSION 3.10.2)
project (KeyboardControl)

add_compile_options(-std=c++11)

set(CMAKE_MODULE_PATH /usr/local/robotino/api2/cmake)

find_package(RobotinoAPI2)

set(CMAKE_INSTALL_PREFIX ./build/)

include_directories(
	include
)

add_executable(
	KeyboardControl
	src/KeyboardVelocityControl.cpp
)
target_link_libraries(
	KeyboardControl
    ${REC_ROBOTINO_API2_LIBRARY}
)