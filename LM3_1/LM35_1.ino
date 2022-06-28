#include "LM35.h"

LM35 TS(14);

void setup() {
  Serial.begin(9600);
}

void loop() {
  TS.sensorLM35(1);  
  TS.SetMaxTemp(28); 
  Serial.println(TS.ReadTemp());
  Serial.println(TS.FanControl());
  delay(1000);
}
