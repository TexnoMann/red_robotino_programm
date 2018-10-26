cmake_minimum_required (VERSION 2.8.11)
project(RadioControl)
add_executable(RadioControl src/GPIOControl/PPMEncoder.cpp src/main.cpp)
