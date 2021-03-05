/*
 Programaren izena: DHTtesterJeysonetaMartin.ino
 Egilea: Elektronika    Data: 2021/02/22
 Zeregina: Dth sentsorea balioak irakurri eta portu seriean erakutsi
 Adibide hau domeinu publikokoa da.
 Programaren egoera: Egiaztatzeko/Egiaztatuta
 Egiaztatutako plakak: UNO ?? Nano Bai MEGA ???
 */

// Connect pin 1 (ezkerrean) of the sensor to +5V
//3.3V logika duen taula bat Arduino Due batek pin 1 konektatzen badu
//5V ordez, 3.3V!
//Zure DHTPIN DOKTOREARI
//X/Connect pin 4 (eskuinaldean)
///Connect a 10K resistor from pin 2 (datuak) to pin 1 (boterea)

//DHT sentsorea.
//Liburutegi honen bertsio zaharragoek hirugarren parametro bat eraman zuten.
//Parametro hau ez da beharrezkoa prozesadore azkarragoentzat.
//DHT irakurgailuaren algoritmoa prozesu azkarragoetan lan egitera egokitzen da.


 /*-----( LIBURUTEGIAK )----*/
#include "DHT.h"
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

/*-----( KONSTANTEAK )-----*/
#define DHTPIN 17     // Pin digitala DTH Kkonektatua
#define DHTTYPE DHT11   // DHT 11
#define BAUDRATE 9600 //Komunikaziorako datuen abiadura
#define ITXARON 2000 //Itxaroteko denbora

/*-----( OBJETUAK )-----*/
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(BAUDRATE);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(ITXARON);

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

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
