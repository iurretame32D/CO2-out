/* Funtzioa: void CCS881SentsoreaSetup (void)
 * Zeregina: DTH11 Sentsorea irakurri 
 * Erabilitako liburutegiak: CCS881 Sensor LibrarY
 * Liburutegia nondik hartuta: https://github.com/adafruit/Adafruit_CCS811 (CCS881 Sensor LibrarY)
 * Bueltatzen duena: ezer
 * Sartutako parametroak: ezer
 *  */
void CCS881SentsoreaSetup (void){
 
  Serial.println("CCS811 test");
 
  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }
 
  // Wait for the sensor to be ready
  while(!ccs.available());
}

/* Funtzioa: void CCS881SentsoreaLoop (void)
 * Zeregina: DTH11 Sentsorea irakurri 
 * Erabilitako liburutegiak: CCS881 Sensor LibrarY
 * Liburutegia nondik hartuta: https://github.com/adafruit/Adafruit_CCS811 (CCS881 Sensor LibrarY)
 * Bueltatzen duena: ezer
 * Sartutako parametroak: ezer
 *  */

void CCS881SentsoreaLoop (void){
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
  delay(1000);
}
