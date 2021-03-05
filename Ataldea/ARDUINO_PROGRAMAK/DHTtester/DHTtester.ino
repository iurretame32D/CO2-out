                                                    /*
 Programaren izena: DHTtester
 Egilea: MIKEL   Data: 22/02/2021
 Zeregina: DHT sentsorearekin tenperatura eta hezetazuna neurtzea.
 Adibide hau domeinu publikokoa da.
 Programaren egoera: Egiaztatzeko/Egiaztatuta
 Egiaztatutako plakak: hasiera batean Nano-arekin konprobatu dugu.
 */
 /*-----( LIBURUTEGIAK )----*/
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
//#include <DHT.h>
//#include <DHT_U.h>
#include "DHT.h"
#define DHTPIN 17     // DHT sentsoreari lotutako Digital pin

//Erabili pinak 3, 4, 5, 12, 13 edo 14.
//Pin 15ek funtziona dezake, baina DHT deskonektatu egin behar da programazioan.

/*-----( KONSTANTEAK )-----*/
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (ezkerrean) of the sensor to +5V
//3.3V logika duen taula bat Arduino Due batek pin 1 konektatzen badu
//5V ordez, 3.3V!
//Zure DHTPIN DOKTOREARI
//X/Connect pin 4 (eskuinaldean)
//Connect a 10K resistor from pin 2 (datuak) to pin 1 (boterea)

//DHT sentsorea.
//Liburutegi honen bertsio zaharragoek hirugarren parametro bat eraman zuten.
//Parametro hau ez da beharrezkoa prozesadore azkarragoentzat.
//DHT irakurgailuaren algoritmoa prozesu azkarragoetan lan egitera egokitzen da.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
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
