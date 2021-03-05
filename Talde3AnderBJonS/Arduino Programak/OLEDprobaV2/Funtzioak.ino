void OledSetup() {

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

void OledLoop() {

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
