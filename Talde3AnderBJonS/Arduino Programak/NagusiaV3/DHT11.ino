/* Funtzioa: DHT-11 sentsorea
 * Zeregina: Funtzio honek DHT-11 sentsoreak neurtutako balioak irakurtzeko 
 * Erabilitako liburutegiak: https://github.com/adafruit/DHT-sensor-library
 * Bueltatzen duena: Tenperatura eta hezetasun neurketa
 * Sartutako parametroak: ezer
 *  */
 void dhtSentsoreaSetup()
 {
  Serial.println("DHTxx test!");

  dht.begin();
 }
 
void dhtSentsoreaLoop(void) {
  
   // Wait a few seconds between measurements.
   delay(2000);
 
   // Reading temperature or humidity takes about 250 milliseconds!
   float h = dht.readHumidity();
   float t = dht.readTemperature();
 
   if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
   }
   Serial.print("Humidity: ");
   Serial.print(h);
   Serial.print(" %\t");
   Serial.print("Temperature: ");
   Serial.print(t);
   Serial.println(" *C ");
   
}
