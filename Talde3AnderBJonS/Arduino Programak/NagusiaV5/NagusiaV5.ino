#include "Nagusia.h"

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
dhtSentsoreaSetup();
OledSetup();
C02SentsoreaSetup();
TTNsetup();
NeoPixelsetup();
}

void loop() {
  
  dhtSentsoreaLoop();

  OledLoop();

  CO2SentsoreaLoop();

  TTNloop();

  NeoPixelLoop();
  
}
  // put your main code here, to run repeatedly:
