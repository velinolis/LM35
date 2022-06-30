#ifndef LM35_H
#define LM35_H
#include <stdint.h>

enum Unit {
  CELSIUS,
  KELVIN,
  FAHRENHEIT
};

class LM35
{
  public:

    LM35(uint8_t pinSensor);
    bool sensorLM35(bool SensorActive);
    bool ON_OFF();
    bool SENSOR_ACT;
    double FAN_ACT;
    double setMaxTemp(double limitTemp);
    double maxTemp();
    double readTemp();
    double readTempDefault();
    double readTemp(Unit unit);
    bool fanControl();

  private:

    uint8_t _pinSensor;

};

#endif
