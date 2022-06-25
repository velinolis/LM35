#include "LM35.h"
#include "Arduino.h"
#include "pin.h"

LM35::LM35(int pinSensor, int pinNPN) {
  _pinSensor = pinSensor;
  _pinNPN = pinNPN;
}

int LM35::readTemp() {

  /*
    [(VCC*1000)/1024]/10 = 0.48828125
    VCC = 5V
    V to mV (*1000)
    10mV = 1ºC
  */

  int Celsius = analogRead(_pinSensor) * 0.48828125; //*500)>>10;
  return Celsius;
}

void LM35::Thermostate(int temp) {
  if (readTemp() >= temp) {
    digitalHigh(_pinNPN);
  } else {
    digitalLow(_pinNPN);
  }
}
