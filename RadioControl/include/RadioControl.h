#include <ctime>
#include <iostream>
#include <stdio.h>

#include <rec/robotino/api2/Com.h>
#include <rec/robotino/api2/Bumper.h>
#include <rec/robotino/api2/OmniDrive.h>
#include <rec/robotino/api2/DistanceSensorArray.h>

using namespace rec::robotino::api2;

class MyDistanceSensorArray : public DistanceSensorArray {
public:
    bool detect_danger;
    MyDistanceSensorArray() { detect_danger = false; }
    void distancesChangedEvent( const float* distances, unsigned int size );
};

void MyDistanceSensorArray::distancesChangedEvent( const float* distances, unsigned int size ){
    //it there are some obstacles in front of robot, then danger_detected = true
    if( (distances[0] < 0.2) || (distances[1] < 0.3) || (distances[size-1] < 0.3) ){
        detect_danger = true;
    }
    else
        detect_danger = false;
}

void sleep(double secs){
    clock_t start_time = std::clock();
    float time = 0.0;
    while(time < secs){
        time = (std::clock() - (float)start_time) / CLOCKS_PER_SEC;
    }
}