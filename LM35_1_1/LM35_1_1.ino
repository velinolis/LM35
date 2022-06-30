#include "LM35.h"

LM35 TS(14);

void setup() {
  Serial.begin(9600);
}

void loop() {
  TS.sensorLM35(1);
  TS.setMaxTemp(28);
  Serial.print("CELSIUS: ");
  Serial.println(TS.readTemp());
  Serial.print("FAHRENHEIT: ");
  Serial.println(TS.readTemp(FAHRENHEIT));
  Serial.print("KELVIN: ");
  Serial.println(TS.readTemp(KELVIN));
  Serial.println(TS.fanControl());
  delay(1000);
}
