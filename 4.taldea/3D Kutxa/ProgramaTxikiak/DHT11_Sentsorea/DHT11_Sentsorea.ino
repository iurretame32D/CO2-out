// Liburutegi hauek behar ditu Arduinok:
// - DHT sentsoreen liburutegia: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified sensor Lib: https://github.com/adafruit/Adafruit sensor

#include "DHT.h"


#define DHTPIN 17     // PIN digitala DHT sentsorera konektatuta

// DHT mota
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void DHT11sentsorealoop (void);
void DHT11sentsoreasetup (void);

//abiarazi DHT sentsorea


void setup() {
  Serial.begin(9600);
  DHT11sentsoreasetup();
}
void loop() {
DHT11sentsorealoop();
}
