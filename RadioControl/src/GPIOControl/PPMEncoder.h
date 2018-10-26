#ifndef PPMENCODER_H
#define PPMENCODER_H

#include "rec/robotino/api2/AnalogInput.h"

using namespace rec::robotino::api2;

class PPMEncoder{
public:
  PPMEncoder(int inputPin, float minValue, float maxValue);
  float getSignal(int micros);
private:
  AnalogInput _input;
  float _maxValue;
  float _minValue;
  int _pulse(int micros);
};

#endif /*PPMENCODER_H_*/
