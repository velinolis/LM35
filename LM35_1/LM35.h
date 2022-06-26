#ifndef LM35_H
#define LM35_H
#include <stdint.h>

class LM35
{
  public:

    LM35(uint8_t pinSensor);
    uint8_t FAN_ACT;
    uint8_t SetMaxTemp(uint8_t lTemp);
    uint8_t MaxTemp();
    uint8_t ReadTemp();
    bool FanControl();

  private:

    uint8_t _pinSensor;
   

};

#endif
