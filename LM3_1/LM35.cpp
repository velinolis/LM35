#include "LM35.h"
#include "Arduino.h"
#include "COMMON/Fast_Digital.h"

#define CONST_LM35 0.48828125

/*
   [(VCC*1000)/1024]/10 = 0.48828125
   VCC = 5V
   V to mV (*1000)
   10mV = 1ºC
*/

LM35::LM35(uint8_t pinSensor) {
  //pinMode(pinSensor, INPUT);
  pinAsInput(pinSensor);
  _pinSensor = pinSensor;
}

bool LM35::sensorLM35(bool SensorActive) {
  SENSOR_ACT = SensorActive;
}

bool LM35::ON_OFF() {
  return SENSOR_ACT;
}

uint8_t LM35::SetMaxTemp(uint8_t limitTemp) {
  FAN_ACT = limitTemp;
}

uint8_t LM35::MaxTemp() {
  return FAN_ACT;
}

uint8_t LM35::ReadTemp() {
  uint8_t Celsius = analogRead(_pinSensor) * CONST_LM35;
  return Celsius;
}

bool LM35::FanControl() {
  if (ReadTemp() >= MaxTemp() && ON_OFF() == true) {
    return true;
  } else {
    return false;
  }
}
