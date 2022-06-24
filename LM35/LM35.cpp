#include "LM35.h"
#include "Arduino.h"

LM35::LM35(int pinSensor) {
  _pinSensor = pinSensor;
}

int LM35::readTemp() {
  
  /*
  [(VCC*1000)/1024]/10 = 0.48828125
  VCC = 5V
  V to mV (*1000)
  10mV = 1ºC
*/

  int Celsius = analogRead(_pinSensor) * 0.48828125;
  //float Celsius = (analogRead(_pinSensor)*500)>>10;
  return Celsius;
}

void LM35::hotTemp(int temp) {
  if (readTemp() >= temp) {
    Serial.println("HT");
  } else {
    Serial.println(readTemp());
  }
}











