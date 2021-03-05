/*
 Programaren izena: DHTtester_JON_MIKEL
 Egilea: JON eta MIKEL   Data: 22/02/2021
 Zeregina: DHT sentsorearekin tenperatura eta hezetazuna neurtzea.
 Adibide hau domeinu publikokoa da.
 Programaren egoera: Egiaztatzeko/Egiaztatuta
 Egiaztatutako plakak: hasiera batean Nano-arekin konprobatu dugu.
 */

 #include "LoraGatewayHeader.h"
void setup() {
  Serial.begin(115200);
  DTH11sentsoreaSETUP (); 
  OledPantallaSETUP();
  CO2sentsoreaSETUP ();
  tntSETUP ();
  NeopixelSETUP();

}

void loop() {
 DTH11sentsoreaLOOP (); 
 OledPantallaLOOP ();
 CO2sentsoreaLOOP ();
 tntLOOP ();
 NeopixelLOOP ();
}
