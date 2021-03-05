/* Funtzioa: void DTH11SentsoreaSetup (void)
 * Zeregina: DTH11 Sentsorea irakurri 
 * Erabilitako liburutegiak: DHT Sensor Library 
 *                           Adafruit Unified Sensor Lib
 * Liburutegia nondik hartuta:  https://github.com/adafruit/DHT-sensor-library  (DHT Sensor Library)
 *                              https://github.com/adafruit/Adafruit_Sensor     (Adafruit Unified Sensor Lib)
 * Bueltatzen duena: ezer
 * Sartutako parametroak: ezer
 *  */
void DTH11SentsoreaSetup (void){
  Serial.println(F("DHTxx test!"));
  dht.begin();
}

/* Funtzioa: void DTH11SentsoreaLoop (void)
 * Zeregina: DTH11 Sentsorea irakurri 
 * Erabilitako liburutegiak: DHT Sensor Library 
 *                           Adafruit Unified Sensor Lib
 * Liburutegia nondik hartuta:  https://github.com/adafruit/DHT-sensor-library  (DHT Sensor Library)
 *                              https://github.com/adafruit/Adafruit_Sensor     (Adafruit Unified Sensor Lib)
 * Bueltatzen duena: ezer
 * Sartutako parametroak: ezer
 *  */

void DTH11SentsoreaLoop (void){

 // Wait a few seconds between measurements.
  delay(1000);
   
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

  Serial.print(F("Hezetasuna: "));
  Serial.print(h);
  Serial.print(F("%  Tenperatura: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  
}
