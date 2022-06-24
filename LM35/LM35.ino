#include "LM35.h"
LM35 TS(A0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(TS.readTemp());
  delay(1000);
  TS.hotTemp(29);
  delay(1000);
}
