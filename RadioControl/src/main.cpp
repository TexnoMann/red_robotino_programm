#include <rec/robotino/api2/Com.h>
#include "GPIOControl/PPMEncoder.h"
#include <iostream>

using namespace std;
using namespace rec::robotino::api2;
Com com;


int main(int argc, char **argv){
  PPMEncoder(4,0,10);

  if(argc>1){
    com.setAddress(argv[1]);
  }
  else{
      com.setAddress("192.168.2.100");
      cout << "Trying to connect to 192.168.0.100..." << endl;
  }
  try{
      com.connectToServer(true);
      std::cout << "Successfully connected!" << std::endl;
  }
  catch(...){
      std::cout << "Unable to connect! Program stopped." << std::endl;
      return 0;
  }



}
