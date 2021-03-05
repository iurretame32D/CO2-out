/*
 Programaren izena: CCS881SentsoreaJeysonetaMartin.ino
 Egilea: Elektronika    Data: 2021/02/22
 Zeregina: CCS881 sentsorea balioak irakurri eta portu seriean erakutsi
 Adibide hau domeinu publikokoa da.
 Programaren egoera: Egiaztatzeko/Egiaztatuta
 Egiaztatutako plakak: UNO ?? Nano Bai MEGA ???
 */
 
 /*-----( LIBURUTEGIAK )----*/
 #include "Adafruit_CCS811.h"
// - CCS881 Sensor Library: https://github.com/adafruit/Adafruit_CCS811


/*-----( KONSTANTEAK )-----*/
#define BAUDRATE 9600 //Komunikaziorako datuen abiadura
#define ITXARON 500 //Itxaroteko denbora

/*-----( OBJETUAK )-----*/
Adafruit_CCS811 ccs;

void setup() {
   Serial.begin(BAUDRATE);
 
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
     //Serial.print(ccs.calculateTemperature());
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
  delay(ITXARON);
}
