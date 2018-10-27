#include <rec/robotino/api2/Com.h>
#include "SerialControl/SERIALRead.h"
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace rec::robotino::api2;
Com com;

int main(int argc, char **argv){
  std::setlocale(LC_ALL, "C");
  cout<<"Inizialized"<<endl;
  string portname(argv[1]);
  SERIALReader reader(portname,9600);
  while(true){
    vector<float> speeds=reader.getSignalForInterval(1000, 1800);
    for(unsigned int i=0;i<speeds.size();i++){
      cout<<speeds[i]<<" ";
    }
    cout<<" "<<endl;
    usleep(1000);
  }
  // if(argc>1){
  //   com.setAddress(argv[1]);
  // }
  // else{
  //     com.setAddress("192.168.2.100");
  //     cout << "Trying to connect to 192.168.0.100..." << endl;
  // }
  // try{
  //     com.connectToServer(true);
  //     std::cout << "Successfully connected!" << std::endl;
  // }
  // catch(...){
  //     std::cout << "Unable to connect! Program stopped." << std::endl;
  //     return 0;
  // }



}
