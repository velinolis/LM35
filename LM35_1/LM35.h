#ifndef LM35_H
#define LM35_H
#include <stdint.h>

class LM35
{
  public:

    LM35(uint8_t pinSensor);
    bool sensorLM35(bool SensorActive);
    bool ON_OFF();
    bool SENSOR_ACT;
    uint8_t FAN_ACT;
    uint8_t SetMaxTemp(uint8_t limitTemp);
    uint8_t MaxTemp();
    uint8_t ReadTemp();
    bool FanControl();

  private:

    uint8_t _pinSensor;

};

#endif
