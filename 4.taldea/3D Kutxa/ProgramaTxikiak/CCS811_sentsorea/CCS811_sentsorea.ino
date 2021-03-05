#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>.
#include "Adafruit_CCS811.h"

Adafruit_CCS811 ccs;

void CCS811sentsorealoop (void);
void CCS811sentsoreasetup (void);

void setup() {
  Serial.begin(9600);
  CCS811sentsoreasetup();
}

void loop() {
  CCS811sentsorealoop();
}
