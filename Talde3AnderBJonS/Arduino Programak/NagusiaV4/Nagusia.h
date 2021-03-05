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

//Libraries for LoRa
#include <SPI.h>
#include <LoRa.h>

//Libraries for OLED Display
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/*-----( KONSTANTEAK )-----*/

//DHT-11
#define DHTTYPE DHT11   // DHT 11
const int DHTPin = 17;     // what digital pin we're connected to

//TTN
static const PROGMEM u1_t NWKSKEY[16] = { 0xCF,0x18,0xAA,0xE4,0xCA,0x60,0xFA,0x73,0x36,0x54,0x3B,0xD3,0x32,0x23,0x91,0x5A };//Network session key
static const u1_t PROGMEM APPSKEY[16] = { 0xD4,0x58,0x30,0x4E,0x51,0xD5,0x29,0x58,0x8B,0xD5,0x82,0x76,0xB2,0x80,0x0B,0xD7 };//APP session key
static const u4_t DEVADDR = 0x26013458 ; // <-- Change this address for every node!DEVICE ADDRESS
// These callbacks are only used in over-the-air activation, so they are
// left empty here (we cannot leave them out completely unless
// DISABLE_JOIN is set in config.h, otherwise the linker will complain).
void os_getArtEui (u1_t* buf) { }
void os_getDevEui (u1_t* buf) { }
void os_getDevKey (u1_t* buf) { }


// Schedule TX every this many seconds (might become longer due to duty
// cycle limitations).
const unsigned TX_INTERVAL = 60;

// Pin mapping
const lmic_pinmap lmic_pins = {
    .nss = 18,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = 14,
    .dio = {26, 33, 32},
};

//OLED

//define the pins used by the LoRa transceiver module
#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26

//433E6 for Asia
//866E6 for Europe
//915E6 for North America
#define BAND 866E6

//OLED pins
#define OLED_SDA 4
#define OLED_SCL 15 
#define OLED_RST 16
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

int counter = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);

/*-----( OBJETUAK )-----*/

//DHT-11
DHT dht(DHTPin, DHTTYPE);

/*-----( ALDAGAIAK )----*/
//Programa osoan zehar erabiliko diren aldagai orokorrak

static uint8_t mydata[] = "Hello, world!";
static osjob_t sendjob;

//Komunikazio serierako aldagaiak

/*-----( FUNTZIOAK )----*/
void dhtSentsoreaLoop(void);
void CO2SentsoreaLoop();
void C02SentsoreaSetup();
void dhtSentsoreaSetup();
void TTNsetup();
void TTNloop();
void OledSetup();
void OledLoop();
