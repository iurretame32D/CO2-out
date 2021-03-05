/* Funtzioa: CO2 sentsorea
 * Zeregina: Funtzio honek C02 sentsoreak neurtutako balioak irakurtzeko 
 * Erabilitako liburutegiak: https://github.com/adafruit/Adafruit_CCS811
 * Bueltatzen duena: C02 eta TVOC neurketa
 * Sartutako parametroak: ezer
 *  */

void C02SentsoreaSetup()
{
   Serial.println("CCS811 test");

  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
}
while(!ccs.available());
  
}
 
void CO2SentsoreaLoop() {
  if(ccs.available()){
    if(!ccs.readData()){
      Serial.print("CO2: ");
      Serial.print(ccs.geteCO2());
      Serial.print("ppm, TVOC: ");
      Serial.println(ccs.getTVOC());
    }
    else{
      Serial.println("ERROR!");
      while(1);
    }
  }
  delay(500);
}
