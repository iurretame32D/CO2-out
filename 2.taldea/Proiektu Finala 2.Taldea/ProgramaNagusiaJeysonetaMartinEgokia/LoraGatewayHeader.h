 /*-----( LIBURUTEGIAK )----*/
//DHT11
#include "DHT.h"
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

//CCS811
 #include "Adafruit_CCS811.h"
// - CCS881 Sensor Library: https://github.com/adafruit/Adafruit_CCS811

//The Things Network
#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>

//Oled Pantaila
#include <LoRa.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//LED NEOPIXEL
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

/*-----( KONSTANTEAK )-----*/
//DHT11
#define DHTPIN 17     // Pin digitala DTH Kkonektatua
#define DHTTYPE DHT11   // DHT 11

//Oled Pantaila
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

//LED NEOPIXEL
#define PIN 13 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 8 // Popular NeoPixel ring size

//The Things Network
// LoRaWAN NwkSKey, network session key
// This is the default Semtech key, which is used by the early prototype TTN
// network.
static const PROGMEM u1_t NWKSKEY[16] = { 0x4A, 0xB1, 0x45, 0x4A, 0xD2, 0x33, 0x7F, 0xB3, 0x93, 0xA2, 0xC9, 0x48, 0xAA, 0x79, 0xC7, 0x74 };

// LoRaWAN AppSKey, application session key
// This is the default Semtech key, which is used by the early prototype TTN
// network.
static const u1_t PROGMEM APPSKEY[16] = { 0x6D, 0x23, 0xF9, 0xF3, 0xE1, 0xDD, 0xF0, 0x37, 0x59, 0x91, 0xA7, 0xA8, 0xC8, 0xE4, 0x9D, 0x68 };

// LoRaWAN end-device address (DevAddr)
static const u4_t DEVADDR = 0x26031284 ; // <-- Change this address for every node!

const unsigned TX_INTERVAL = 180000;

// Pin mapping
const lmic_pinmap lmic_pins = {
    .nss = 18,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = 14,
    .dio = {26, 33, 32},
};

#define BAUDRATE 115200 //Komunikaziorako datuen abiadura


/*-----( OBJETUAK )-----*/
//DHT11
DHT dht(DHTPIN, DHTTYPE);

//CCS811
Adafruit_CCS811 ccs;

//Oled Pantaila
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);

//LED NEOPIXEL
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

/*-----( ALDAGAIAK )-----*/
//The Things Network
static uint8_t mydata[] = "Hello, world!";
static osjob_t sendjob;

/*-----( FUNTZIOAK )-----*/
//DHT11
void DTH11SentsoreaLoop (void);
void DTH11SentsoreaSetup (void);

//CCS811
void CCS881SentsoreaLoop (void);
void CCS881SentsoreaSetup (void);

//The Things Network
void os_getArtEui (u1_t* buf) { }
void os_getDevEui (u1_t* buf) { }
void os_getDevKey (u1_t* buf) { }
void TheThingsNetworkSetup (void);
void TheThingsNetworkLoop (void);

//Oled Pantaila
void OledPantailaSetup (void);
void OledPantailaLoop (void);

//LED NEOPIXEL
void NeoPixelLoop (void);
void NeoPixelSetup (void);

//Komunikazioa TTN
void komunikazioaTTNLoop (void)
