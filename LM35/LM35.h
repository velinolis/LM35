#ifndef LM35_H
#define LM35_H

class LM35
{
  public:

    LM35(int pinSensor, int pinNPN);
    int readTemp();
    void Thermostate(int temp);

  private:

    int _pinSensor;
    int _pinNPN;
};

#endif
