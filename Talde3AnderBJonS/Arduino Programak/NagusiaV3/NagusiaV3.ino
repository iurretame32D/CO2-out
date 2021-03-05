#include "Nagusia.h"

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
dhtSentsoreaSetup();
C02SentsoreaSetup();
TTNsetup();

}

void loop() {
  
  dhtSentsoreaLoop();

  CO2SentsoreaLoop();

  TTNloop();
  
}
  // put your main code here, to run repeatedly:
