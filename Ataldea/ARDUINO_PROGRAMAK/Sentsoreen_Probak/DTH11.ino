/* Funtzioa:  int DTH11sentsorea (int zeinPin)
 * Zeregina: DTH11 sentsorean temperatura eeta hezetasuna naurtzen du.
 * Erabilitako liburutegiak: DTH11DHT Sensor Library eta Adafruit
 * Liburutegia nondik hartuta: https://github.com/adafruit/Adafruit_Sensor // https://github.com/adafruit/DHT-sensor-library
 * Bueltatzen duena: ezer
 * Sartutako parametroak: 
 *     int 
 *      
 *  */
void DTH11sentsoreaSETUP (void){
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

/* Funtzioa:  int DTH11sentsorea (int zeinPin)
 * Zeregina: DTH11 sentsorean temperatura eeta hezetasuna naurtzen du.
 * Erabilitako liburutegiak: DTH11DHT Sensor Library eta Adafruit
 * Liburutegia nondik hartuta: https://github.com/adafruit/Adafruit_Sensor // https://github.com/adafruit/DHT-sensor-library
 * Bueltatzen duena: ezer
 * Sartutako parametroak: 
 *     int 
 *      
 *  */
void DTH11sentsoreaLOOP (void){

  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("hezetasuna: "));
  Serial.print(h);
  Serial.print(F("%  Temperatura: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Bero-indizea: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
