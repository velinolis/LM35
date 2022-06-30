#include "LM35.h"
#include "Arduino.h"
#include "Fast_DWR.h"

/*
   [(VCC*1000)/1024]/10 = 0.48828125
   VCC = 5V
   V to mV (*1000)
   10mV = 1ºC
   ______________________________________________________
   Conversion ºC to ºF      -> ((ºC * 1.8) + 32) [1.8 or 9/5]
              ºC to K       -> (ºC + 273.15)
              ºC to ºR/ºRa  -> ((ºC + 273.15) * 1.8)
              ºC to ºRe/ºRé -> (ºC * 0.8)
*/

#define CELSIUS_LM35 0.48828125
#define C_KELVIN 273.15

LM35::LM35(uint8_t pinSensor) {
  pinAsInput(pinSensor);
  _pinSensor = pinSensor;
}

bool LM35::sensorLM35(bool SensorActive) {
  SENSOR_ACT = SensorActive;
}

bool LM35::ON_OFF() {
  return SENSOR_ACT;
}
double LM35::setMaxTemp(double limitTemp) {
  FAN_ACT = limitTemp;
}
double LM35::maxTemp() {
  return FAN_ACT;
}

double LM35::readTempDefault() {
  double Celsius = analogRead(_pinSensor) * CELSIUS_LM35;
  return Celsius;
}
double LM35::readTemp() {
  return readTempDefault();
}

double LM35::readTemp(Unit unit) {
  if (unit == CELSIUS) {
    return readTempDefault();
  }
  if (unit == FAHRENHEIT) {
    return ((readTempDefault() * 9 / 5) + 32);
  }
  if (unit == KELVIN) {
    return (readTempDefault() + C_KELVIN);
  }
}

bool LM35::fanControl() {
  if (readTempDefault() >= maxTemp() && ON_OFF() == true) {
    return true;
  }
  return false;
}
