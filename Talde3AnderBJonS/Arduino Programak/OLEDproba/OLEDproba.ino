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

void setup() {

  //reset OLED display via software
  pinMode(OLED_RST, OUTPUT);
  digitalWrite(OLED_RST, LOW);
  delay(20);
  digitalWrite(OLED_RST, HIGH);

  //initialize OLED
  Wire.begin(OLED_SDA, OLED_SCL);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("LORA SENDER ");
  display.display();
  
  //initialize Serial Monitor
  Serial.begin(115200);
  
  Serial.println("LoRa Sender Test");

  //SPI LoRa pins
  SPI.begin(SCK, MISO, MOSI, SS);
  //setup LoRa transceiver module
  LoRa.setPins(SS, RST, DIO0);
  
  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println("LoRa Initializing OK!");
  display.setCursor(0,10);
  display.print("LoRa Initializing OK!");
  display.display();
  delay(2000);
//DHT11
      Serial.println(F("DHTxx test!"));

  dht.begin();

  //CCS811
      Serial.println("CCS811 test");

  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }

  // Wait for the sensor to be ready
  while(!ccs.available());
}

void loop() {

    // Itxaron neurketa egin baino lehen
  delay(2000);
  
  float h = dht.readHumidity();
  // Irakurri tenperatura Celsius
  float t = dht.readTemperature();

  if(ccs.available()){
    if(!ccs.readData()){
      Serial.print("CO2: ");
      Serial.print(ccs.geteCO2());
      Serial.print("ppm, TVOC: ");
      Serial.println(ccs.getTVOC());
    }
    else{
      Serial.println("ERROR!");
      while(1);
    }
  }
  delay(500);
  
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("AnderB JonS");
  display.setCursor(0,10); 
  display.setTextSize(1);
  display.print("Neurketak:"); 
    display.setCursor(0,30);
  display.print("Hezetasuna: ");
  //display.setCursor(50,30);
  display.print(h);      
  display.print("% "); 
  display.setCursor(0,40);
  display.print("Tenperatura: ");
  display.print(t);  
  display.print("°C "); 
  display.setCursor(0,50);
  display.print("CO2: ");
  display.print(ccs.geteCO2());      
  display.print("ppm, TVOC: "); 
  display.print(ccs.getTVOC());
  
  display.display();

  // Egiaztatu irakurketaren batek huts egin duen eta goiz atera (berriro saiatzeko).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Ezin izan da DHT sentsoretik irakurri!"));
    return;
  }

  Serial.print(F("Hezetasuna: "));
  Serial.print(h);
  Serial.print(F("%  Tenperatura: "));
  Serial.print(t);
  Serial.print(F("°C "));

}
