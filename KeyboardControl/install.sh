#!/bin/bash

g++ -I /usr/local/robotino/api2/include/rec/robotino/api2/ -I /usr/local/robotino/api2/include -c src/KeyboardVelocityControl.cpp -o build/KeyboardVelocityControl.o
g++ build/KeyboardVelocityControl.o /usr/local/robotino/api2/lib/librec_robotino_api2.so -o build/KeyboardVelocityControl
rm -rf build/KeyboardVelocityControl.o