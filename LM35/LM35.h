#ifndef LM35_H
#define LM35_H


class LM35
{
  public:

    LM35(int pinSensor);
    int readTemp();
    void hotTemp(int temp);

  private:

    int _pinSensor;


};

#endif
