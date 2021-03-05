//Libraries for LoRa
#include <SPI.h>
#include <LoRa.h>

//Libraries for OLED Display
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "DHT.h"
#include <lmic.h>
#include <hal/hal.h>
#include "Adafruit_CCS811.h"

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

#define DHTPIN 17     // PIN digitala DHT sentsorera konektatuta

// DHT mota
#define DHTTYPE DHT11   // DHT 11

//packet counter
int counter = 0;

DHT dht(DHTPIN, DHTTYPE);

Adafruit_CCS811 ccs;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);

//funtzioak

void OledSetup();
void OledLoop();

void setup() {

  OledSetup();
  
}

void loop() {

  OledLoop();

}
