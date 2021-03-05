/* Funtzioa: void CO2sentsorea (void)
 * Zeregina:CO2 sentsorean naurtzea du.
 * Erabilitako liburutegiak: DTH11DHT Sensor Library eta Adafruit
 * Liburutegia nondik hartuta://https://github.com/adafruit/Adafruit_CCS811
 * Bueltatzen duena: ezer
 * Sartutako parametroak: 
 *     int 
 *      
 *  */
void CO2sentsoreaSETUP (void){


  Serial.println("CCS811 test");
 
  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }

 
  // Wait for the sensor to be ready
  while(!ccs.available());
}

/* Funtzioa: void CO2sentsorea (void)
 * Zeregina:CO2 sentsorean naurtzea du.
 * Erabilitako liburutegiak: DTH11DHT Sensor Library eta Adafruit
 * Liburutegia nondik hartuta://https://github.com/adafruit/Adafruit_CCS811
 * Bueltatzen duena: ezer
 * Sartutako parametroak: 
 *     int 
 *      
 *  */
void CO2sentsoreaLOOP (void){ 
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
