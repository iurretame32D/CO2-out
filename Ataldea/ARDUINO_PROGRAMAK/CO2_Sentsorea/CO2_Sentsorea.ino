/*
 Programaren izena: CO2_SENTSOREA
 Egilea:  MIKEL   Data: 22/02/2021
 Zeregina: CO2 sentsorearekin neurtu aire kalitate maila
 Adibide hau domeinu publikokoa da.
 Programaren egoera: Egiaztatzeko/Egiaztatuta
 Egiaztatutako plakak: hasiera batean Nano-arekin konprobatu dugu.
 */
 /*-----( LIBURUTEGIAK )----*/
#include "Adafruit_CCS811.h" //https://github.com/adafruit/Adafruit_CCS811

Adafruit_CCS811 ccs;
 
void setup() {
  Serial.begin(9600);
 
  Serial.println("CCS811 test");
 
  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }
 
  // Wait for the sensor to be ready
  while(!ccs.available());
}
 
void loop() {
  if(ccs.available()){
    if(!ccs.readData()){
     //Serial.println(ccs.calculateTemperature());
     Serial.print("CO2: ");
      Serial.print(ccs.geteCO2());
      Serial.println("ppm");
      Serial.print("TVOC: ");
      Serial.println(ccs.getTVOC());
   }   
    else{
      Serial.println("ERROR!");
      while(1);
    }
  }
  delay(500);
}
