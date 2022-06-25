#include "LM35.h"

LM35 TS(A0,5);

void setup() {
  Serial.begin(9600);
}

void loop() {
  TS.Thermostate(29);
  Serial.println(TS.readTemp());
  delay(1000);
}
