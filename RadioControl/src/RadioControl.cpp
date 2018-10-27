#include "../include/RadioControl.h"



#define SOME_TIME 0.05

    Com com;
    MyDistanceSensorArray dist_sens;
    Bumper bumper;
    OmniDrive omni;


void MovingTowards(double x_vel, double y_vel, double angle_vel, double time = 5){
    clock_t start_time = std::clock();
    //loop until bumper be pressed
    if(!bumper.value()){
        com.processEvents();
        omni.setVelocity(x_vel, y_vel, angle_vel);
        sleep(SOME_TIME);
    }
}


int main(int argc, char **argv){
    std::setlocale(LC_ALL, "C");
    SERIALReader reader(argv[1],9600);
    float kp = 0.1;
    /*connect to robot with IP which was specified as program's command line
    argument or to 192.168.2.100 if no argument was provided*/
    //setting IP
    if(argc > 1){
         com.setAddress(argv[2]);
         std::cout << "Trying to connect to " << argv[2] << "..." << std::endl;
    }
    else{
        com.setAddress("192.168.2.100");
        std::cout << "Trying to connect to 192.168.2.100..." << std::endl;
    }
    //try to connect
    try{
        com.connectToServer(true);
        std::cout << "Successfully connected!" << std::endl;
    }
    catch(...){
        std::cout << "Unable to connect! Program stopped." << std::endl;
        return 0;
    }

    //connect devices with their handles
    omni.setComId(com.id());
    bumper.setComId(com.id());
    dist_sens.setComId(com.id());
    double forw, turn, ang;
    while(true){
      vector<float> speeds=reader.getSignalForInterval(1000, 1800);
      kp=abs(speeds[3]);
      for(int i=0;i<4;i++){
        cout<<speeds[i]<<" ";
        cout<<" "<<endl;
      }
      MovingTowards(speeds[0]*kp,speeds[1]*kp,speeds[2]*kp);
    }
    com.disconnectFromServer();
    return 0;
}
