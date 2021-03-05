 /*-----( LIBURUTEGIAK )----*/
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
//#include <DHT.h>
//#include <DHT_U.h>
#include "DHT.h"
#define DHTPIN 17     // DHT sentsoreari lotutako Digital pin
#include "Adafruit_CCS811.h" //https://github.com/adafruit/Adafruit_CCS811

#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>
//Libraries for LoRa
#include <LoRa.h>
//Libraries for OLED Display
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

/*-----( KONSTANTEAK )-----*/
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
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
#define DELAYVAL 100 // Time (in milliseconds) to pause between pixels

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        13 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 8 // Popular NeoPixel ring size
/*-----( OBJETUAK )-----*/
DHT dht(DHTPIN, DHTTYPE);
Adafruit_CCS811 ccs;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);

String LoRaData;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);



// LoRaWAN NwkSKey, network session key
// This is the default Semtech key, which is used by the early prototype TTN
// network.
static const PROGMEM u1_t NWKSKEY[16] = { 0x0E, 0x47, 0xF6, 0x3E, 0xF4, 0x6E, 0x65, 0x07, 0x9B, 0x41, 0x20, 0x16, 0x69, 0x2C, 0x09, 0xBD };

// LoRaWAN AppSKey, application session key
// This is the default Semtech key, which is used by the early prototype TTN
// network.
static const u1_t PROGMEM APPSKEY[16] = { 0x1B, 0x54 , 0x8E, 0xAC, 0x66, 0x0F, 0x32, 0x0A, 0xAB, 0x21, 0x09, 0x04, 0x46, 0x1C, 0x08, 0x6A };

// LoRaWAN end-device address (DevAddr)
static const u4_t DEVADDR = 0x26011E4D  ; // <-- Change this address for every node!
/*-----( FUNTZIOAK )-----*/
void CO2sentsoreaSETUP (void);
void CO2sentsoreaLOOP (void);
void DTH11sentsoreaSETUP (void);
void DTH11sentsoreaLOOP (void);
void tntSETUP (void);
void tntLOOP (void);
void OledPantallaSETUP (void);
void OledPantallaLOOP (void);
void NeopixelSETUP (void);
void NeopixelLOOP (void);
//BIDALKETA
//void BidalketaLOOP (void);
// These callbacks are only used in over-the-air activation, so they are
// left empty here (we cannot leave them out completely unless
// DISABLE_JOIN is set in config.h, otherwise the linker will complain).
void os_getArtEui (u1_t* buf) { }
void os_getDevEui (u1_t* buf) { }
void os_getDevKey (u1_t* buf) { }

static uint8_t mydata[] = "Hello, world!";
static osjob_t sendjob;

// Schedule TX every this many seconds (might become longer due to duty
// cycle limitations).
const unsigned TX_INTERVAL = 1800000;

// Pin mapping
const lmic_pinmap lmic_pins = {
    .nss = 18,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = 14,
    .dio = {26, 33, 32},
};
