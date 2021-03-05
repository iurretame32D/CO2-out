/*
 Programaren izena: ProgramaNagusia.ino
 Egilea: Ander Urigoitia eta Xabier Intxausti    Data: 2021/02/24-2021/03/04
 Zeregina: Lora bidezko komunikazioa
 Adibide hau domeinu publikokoa da.
 Programaren egoera: Egiaztatuta
 Egiaztatutako plakak: ESP32
 */
#include "ProgramaNagusia.h"

void setup() {
  Serial.begin(115200);
  //DHT11sentsoreasetup();
  //PantailaSetup();
  CCS811sentsoreasetup();
  //ttnabpSetup();
  //NeoPixelSetup();
  
}
void loop() {
//DHT11sentsorealoop();
CCS811sentsorealoop();
//ttnabpLoop();
//PantailaLoop();
//NeoPixelLoop();
}
