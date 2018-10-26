#include "PPMEncoder.h"

PPMEncoder::PPMEncoder(int inputPin, float maxValue, float minValue):
_input()
{
  _maxValue=0;
  _minValue=0;
}

float  PPMEncoder::getSignal(int micros){
  int valuesig=_pulse(micros);


}

int PPMEncoder::_pulse(int micros){

}
