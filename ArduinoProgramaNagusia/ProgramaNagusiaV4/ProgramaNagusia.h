// Liburutegi hauek behar ditu Arduinok:
// - DHT sentsoreen liburutegia: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified sensor Lib: https://github.com/adafruit/Adafruit sensor
/*LIBURUTEGIAK*/
//DHT11
#include "DHT.h"
//CCS811
#include "Adafruit_CCS811.h"
//TTN
#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>

//LORA
#include <SPI.h>
#include <LoRa.h>

//OLED Display Pantaila
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//NeoPixel LED
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

/*KONSTANTEAK*/
//DHT11 PIN
#define DHTPIN 17     // PIN digitala DHT sentsorera konektatuta
// DHT mota
#define DHTTYPE DHT11   // DHT 11

// LoRaWAN NwkSKey, network session key
// This is the default Semtech key, which is used by the early prototype TTN
// network.
static const PROGMEM u1_t NWKSKEY[16] = { 0x58, 0xF2, 0x01, 0xF7, 0xE5, 0xC1, 0x7F, 0x2E, 0x16, 0xB3, 0x04, 0x30, 0x99, 0x4D, 0xAB, 0x86 };

// LoRaWAN AppSKey, application session key
// This is the default Semtech key, which is used by the early prototype TTN
// network.
static const u1_t PROGMEM APPSKEY[16] = { 0x58, 0x9B, 0x5B, 0xDA, 0xDC, 0x3B, 0x20, 0xBC, 0x39, 0x8A, 0x48, 0xD5, 0xEE, 0x84, 0x99, 0x0A };

// LoRaWAN end-device address (DevAddr)
static const u4_t DEVADDR = 0x26013B1C ; // <-- Change this address for every node!

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

//Lora komunikazio pinak
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

//OLED pinak
#define OLED_SDA 4
#define OLED_SCL 15 
#define OLED_RST 16
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in 

//NeoPixelLed Pinak
#define PIN        13 

#define NUMPIXELS 8 // Zenbat NeoPixel

/*OBJETUAK*/
Adafruit_CCS811 ccs;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);

//abiarazi DHT sentsorea
DHT dht(DHTPIN, DHTTYPE);

//NeoPixel
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

/*ALDAGAIAK*/
//static uint8_t mydata[] = "Hello, world!";
static osjob_t sendjob;

/*FUNTZIOAK*/
//DHT
void DHT11sentsoreasetup (void);
void DHT11sentsorealoop (void);
//CCS811
void CCS811sentsoreasetup (void);
void CCS811sentsorealoop (void);
//TTN//
void os_getArtEui (u1_t* buf) { }
void os_getDevEui (u1_t* buf) { }
void os_getDevKey (u1_t* buf) { }
void ttnabpSetup(void);
void ttnabpLoop(void);
//PANTAILA
void PantailaSetup(void);
void PantailaLoop(void);
//NEOPIXEL
void NeoPixelSetup(void);
void NeoPixelLoop(void);
//BIDALKETA
void BidalketaLoop (void);
