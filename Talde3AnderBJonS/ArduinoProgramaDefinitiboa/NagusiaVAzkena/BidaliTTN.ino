void BidalketaLoop (void){

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
unsigned long balioa =((t*10000000)+(h*10000)+(ccs.geteCO2()));                                  //bidaliko dugun zenbakizko txurroaren simulazioa, balioa adibide bat da TTTHHCCCC
String payload = String(balioa);                                  //txurroa string batera pasatu
static uint8_t payloadChar[10];                                   //karaktereen arraya sortu
payload.toCharArray((char *)payloadChar, sizeof(payloadChar));    //stringa char array bihurtu


// Prepare upstream data transmission at the next possible time. Bidalketa egiteko lekua, payloadChar aldagaia bidaltzen du
LMIC_setTxData2(1, payloadChar, sizeof(payloadChar)-1, 0);
Serial.println(F("Packet queued"));
}
