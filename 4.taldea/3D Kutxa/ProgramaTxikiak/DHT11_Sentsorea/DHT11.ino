void DHT11sentsoreasetup (void){
    Serial.println(F("DHTxx test!"));

  dht.begin();
}
/* Funtzioa: void DHT11sentsorealoop (void)
 * Zeregina: funtzio honek tenperatura eta hezetasuna irakurtzen du
 * Erabilitako liburutegiak: - DHT sentsoreen liburutegia: https://github.com/adafruit/DHT-sensor-library
                             - Adafruit Unified sensor Lib: https://github.com/adafruit/Adafruit sensor
 * Liburutegia nondik hartuta: Arduino bertatik
 * Bueltatzen duena: ezer
 * Sartutako parametroak: ezer
 *  */
void DHT11sentsorealoop (void){
    // Itxaron neurketa egin baino lehen
  delay(2000);
  
  float h = dht.readHumidity();
  // Irakurri tenperatura Celsius
  float t = dht.readTemperature();
  // Irakurri tenperatura Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Egiaztatu irakurketaren batek huts egin duen eta goiz atera (berriro saiatzeko).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Ezin izan da DHT sentsoretik irakurri!"));
    return;
  }
  // Kalkulatu bero-indizea Fahrenheiten (balio lehenetsia)
  float hif = dht.computeHeatIndex(f, h);
  // Kalkulatu bero-indizea Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Hezetasuna: "));
  Serial.print(h);
  Serial.print(F("%  Tenperatura: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Sentzasio termikoa: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
