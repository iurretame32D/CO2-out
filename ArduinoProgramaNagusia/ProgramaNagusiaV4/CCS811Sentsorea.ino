void CCS811sentsoreasetup (void){
    Serial.println("CCS811 test");

  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }

  // Wait for the sensor to be ready
  while(!ccs.available());
}//void CCS811sentsoreasetup (void) AMAIERA

/* Funtzioa: void CCS811sentsorealoop (void)
 * Zeregina: funtzio honek CO2 maila irakurtzen du
 * Erabilitako liburutegiak: "Adafruit_CCS811.h"
 * Liburutegia nondik hartuta: Arduino bertatik
 * Bueltatzen duena: ezer
 * Sartutako parametroak: ezer
 *  */
 void CCS811sentsorealoop (void){
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
 }//void CCS811sentsorealoop (void) AMAIERA
