#include "../include/KeyboardVelocityControl.h"


#define SOME_TIME 0.05

    Com com;
    MyDistanceSensorArray dist_sens;
    Bumper bumper;
    OmniDrive omni;

void MovingTowards(double x_vel, double y_vel, double angle_vel, double time = 5){
    clock_t start_time = std::clock();
    //loop until bumper be pressed
    // while(!bumper.value() && std::clock() - start_time < time){
        com.processEvents();
        omni.setVelocity(x_vel, y_vel, angle_vel);
        sleep(SOME_TIME);
        // std::cout << - start_time + std::clock()<< "\n";
    }


int main(int argc, char **argv){
    struct termios oldt,
    newt;
    int ch1,ch2;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    double k = 0.1;
    /*connect to robot with IP which was specified as program's command line
    argument or to 192.168.2.100 if no argument was provided*/
    //setting IP
    if(argc > 1){
         com.setAddress(argv[1]);
         std::cout << "Trying to connect to " << argv[1] << "..." << std::endl;
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
    while(true)
{               ch1 = getchar();
                ch2 = getchar();
                forw = 0;
                turn = 0;
                ang = 0;
                std::cout <<ch1 << " " <<ch2;
                if (ch1 == 'w' || ch2 == 'w'){
                    forw=k;
                }
                if (ch1 == 'd' || ch2 == 'd'){
                    turn=-k;
                }
                if (ch1 == 's' || ch2 == 's'){
                    forw=-k;
                }
                if (ch1 == 'a' || ch2 == 'a'){
                    turn=k;
                }
                if (ch1 == 'e' || ch2 == 'e'){
                    ang=-k;
                }
                if (ch1 == 'q' || ch2 == 'q'){
                    ang=k;
                }
                if ((ch1 == 'r' || ch2 == 'r') && k < 1) {
                    k+=0.1;
                }
                if ((ch1 == 'f' || ch2 == 'f') && k > 0) {
                    k-=0.1;
                }
                MovingTowards(forw, turn, ang);
    
}
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    com.disconnectFromServer();
    return 0;
}