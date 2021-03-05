/*
 Programaren izena: DHTtester_JON_MIKEL
 Egilea: JON eta MIKEL   Data: 22/02/2021
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
#include "Adafruit_CCS811.h" //https://github.com/adafruit/Adafruit_CCS811


/*-----( KONSTANTEAK )-----*/
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

/*-----( OBJETUAK )-----*/
DHT dht(DHTPIN, DHTTYPE);
Adafruit_CCS811 ccs;
/*-----( FUNTZIOAK )-----*/
void CO2sentsoreaSETUP (void);
void CO2sentsoreaLOOP (void);
void DTH11sentsoreaSETUP (void);
void DTH11sentsoreaLOOP (void);
 
void setup() {
  Serial.begin(9600);
 DTH11sentsoreaSETUP (); 
 CO2sentsoreaSETUP ();
}

void loop() {
 DTH11sentsoreaLOOP (); 
 CO2sentsoreaLOOP ();
}
