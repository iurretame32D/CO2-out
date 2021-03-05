/*
 Programaren izena: ProgramaNagusiaJeysonetaMartinV2.ino
 Egilea: Jeyson Rueda eta Martin Malaxetxebarria    Data: 2021/02/24
 Zeregina: Lora bidezko komunikazioa
 Adibide hau domeinu publikokoa da.
 Programaren egoera: Egiaztatzeko/Egiaztatuta
 Egiaztatutako plakak: UNO ?? Nano Bai MEGA ???
 */
#include "LoraGatewayHeader.h"

void setup() {
  Serial.begin(115200);
  DTH11SentsoreaSetup ();
  OledPantailaSetup ();
  CCS881SentsoreaSetup ();
  TheThingsNetworkSetup ();
  NeoPixelSetup ();
}


void loop() {
  DTH11SentsoreaLoop ();
  OledPantailaLoop ();
  CCS881SentsoreaLoop ();
  TheThingsNetworkLoop ();
  NeoPixelLoop ();
}
