/*-----( LIBURUTEGIAK )----*/
//CO2Sentsorea
#include "Adafruit_CCS811.h"
Adafruit_CCS811 ccs;

//DHT11
#include "DHT.h"

//TTN
#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>

/*-----( KONSTANTEAK )-----*/

//DHT-11
#define DHTTYPE DHT11   // DHT 11
const int DHTPin = 17;     // what digital pin we're connected to

//TTN
static const PROGMEM u1_t NWKSKEY[16] = { 0xCF,0x18,0xAA,0xE4,0xCA,0x60,0xFA,0x73,0x36,0x54,0x3B,0xD3,0x32,0x23,0x91,0x5A };//Network session key
static const u1_t PROGMEM APPSKEY[16] = { 0xD4,0x58,0x30,0x4E,0x51,0xD5,0x29,0x58,0x8B,0xD5,0x82,0x76,0xB2,0x80,0x0B,0xD7 };//APP session key
static const u4_t DEVADDR = 0x26013458 ; // <-- Change this address for every node!DEVICE ADDRESS

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
void TTNsetup();
void TTNloop();
