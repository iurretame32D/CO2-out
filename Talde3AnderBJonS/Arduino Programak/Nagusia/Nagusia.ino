/*-----( LIBURUTEGIAK )----*/
//CO2
#include "Adafruit_CCS811.h"
Adafruit_CCS811 ccs;
//DHT11
#include "DHT.h"

/*-----( KONSTANTEAK )-----*/
#define DHTTYPE DHT11   // DHT 11
const int DHTPin = 17;     // what digital pin we're connected to


/*-----( OBJETUAK )-----*/

//DHT-11
DHT dht(DHTPin, DHTTYPE);

/*-----( ALDAGAIAK )----*/
//Programa osoan zehar erabiliko diren aldagai orokorrak

//Komunikazio serierako aldagaiak


/*-----( FUNTZIOAK )----*/
void dhtSentsoreaLoop(void);
void CO2SentsoreaLoop();
void C02SentsoreaSetup();
void dhtSentsoreaSetup();


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
dhtSentsoreaSetup();
C02SentsoreaSetup();

}

void loop() {
  
  dhtSentsoreaLoop();

  CO2SentsoreaLoop();
  
}
  // put your main code here, to run repeatedly:
