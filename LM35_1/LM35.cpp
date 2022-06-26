#include "LM35.h"
#include "Arduino.h"

LM35::LM35(uint8_t pinSensor) {
  pinMode(pinSensor, INPUT);
  _pinSensor = pinSensor;
}

uint8_t LM35::SetMaxTemp(uint8_t lTemp) {
  FAN_ACT = lTemp;
}

uint8_t LM35::MaxTemp() {
  return FAN_ACT;
}

uint8_t LM35::ReadTemp() {

  /*
    [(VCC*1000)/1024]/10 = 0.48828125
    VCC = 5V
    V to mV (*1000)
    10mV = 1ºC
  */

  uint8_t Celsius = analogRead(_pinSensor) * 0.48828125; //*500)>>10;
  return Celsius;
}

bool LM35::FanControl() {
  if (ReadTemp() >= MaxTemp()) {
    return true;
  } else {
    return false;
  }
}
