#include "LM35.h"

LM35 TS(A0,5);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(TS.readTemp());
  delay(1000);
  TS.Thermostate(29);
  delay(1000);
}
