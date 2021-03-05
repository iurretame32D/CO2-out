/* Funtzioa: void OledPantailaSetup (void)
 * Zeregina: 
 * Erabilitako liburutegiak:
 * Liburutegia nondik hartuta:
 * Bueltatzen duena: ezer
 * Sartutako parametroak: ezer
 *  */
void OledPantailaSetup (void) {
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
  display.print("Kargatzen... ");
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
  delay(2000);
}

/* Funtzioa: void OledPantailaLoop (void)
 * Zeregina: 
 * Erabilitako liburutegiak:
 * Liburutegia nondik hartuta:
 * Bueltatzen duena: ezer
 * Sartutako parametroak: ezer
 *  */
void OledPantailaLoop (void){
  float h = dht.readHumidity();
  float t = dht.readTemperature();  
  
  if(ccs.available()){
    if(!ccs.readData()){
     //Serial.print(ccs.calculateTemperature());
      Serial.print("CO2: ");
      Serial.print(ccs.geteCO2());
      Serial.println("ppm");
      Serial.print("TVOC: "); 
      Serial.println(ccs.getTVOC());
   }   
    else{
      Serial.println("ERROR!");
      while(1);
    }
  }
  
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Neurketak Jeyson eta Martin");
  display.setCursor(0,10);
  display.print("Tenperatura + hezetasuna");
  display.setCursor(0,20);
  display.print(t);
  display.setCursor(30,20);
  display.print(h);
  display.setCursor(0,40);
  display.print("CO2 + TVCO");
  display.setCursor(0,40); 
  display.print(ccs.geteCO2());
  display.setCursor(30,40);
  display.print(ccs.getTVOC());     
  display.display();
  
  delay(1000);
}
