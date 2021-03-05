/* Funtzioa: void NeopixelSETUP (void) 
 * Zeregina: Neopixela eta bere argiak zehaztea.
 * Erabilitako liburutegiak:
 * Liburutegia nondik hartuta:
 * Bueltatzen duena: ezer
 * Sartutako parametroak: 
 *    
 *      
 *  */

void NeopixelSETUP (void) 
{
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}
/* Funtzioa: void NeopixelLOOP(void) 
 * Zeregina:
 * Erabilitako liburutegiak:
 * Liburutegia nondik hartuta: pin zehaztu
 * Bueltatzen duena: ezer
 * Sartutako parametroak: 
 *     
 *      
 *  */
void NeopixelLOOP(void) 
{
  pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  //for(int i=0; i<8; i++) { // For each pixel...

    //pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    // pixels.setPixelColor(0, pixels.Color(50, 80, 0));
   // pixels.setPixelColor(1, pixels.Color(50, 0, 0));
   // pixels.setPixelColor(2, pixels.Color(0, 50, 0));
   // pixels.setPixelColor(3, pixels.Color(0, 0, 50));
   // pixels.setPixelColor(4, pixels.Color(50, 50, 0));
   // pixels.setPixelColor(5, pixels.Color(50, 0, 50));
   // pixels.setPixelColor(6, pixels.Color(0, 50, 50));
    //pixels.setPixelColor(7, pixels.Color(50, 50, 0));
  
    if(!ccs.readData()){
     //Serial.println(ccs.calculateTemperature());
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
  
  if (ccs.geteCO2()>=400 & ccs.geteCO2()<750){
    pixels.setPixelColor(0, pixels.Color(0, 50, 0));
    pixels.setPixelColor(1, pixels.Color(0, 50, 0));
    pixels.setPixelColor(2, pixels.Color(0, 50, 0));
  }
  else {
    if (ccs.geteCO2()>=750 & ccs.geteCO2()<1100){
      pixels.setPixelColor(0, pixels.Color(0, 50, 0));
      pixels.setPixelColor(1, pixels.Color(0, 50, 0));
      pixels.setPixelColor(2, pixels.Color(0, 50, 0));
      pixels.setPixelColor(3, pixels.Color(50, 50, 0));
      pixels.setPixelColor(4, pixels.Color(50, 50, 0));
      pixels.setPixelColor(5, pixels.Color(50, 50, 0));   
  }
  else {
    pixels.setPixelColor(0, pixels.Color(0, 50, 0));
    pixels.setPixelColor(1, pixels.Color(0, 50, 0));
    pixels.setPixelColor(2, pixels.Color(0, 50, 0));
    pixels.setPixelColor(3, pixels.Color(50, 50, 0));
    pixels.setPixelColor(4, pixels.Color(50, 50, 0));
    pixels.setPixelColor(5, pixels.Color(50, 50, 0)); 
    pixels.setPixelColor(6, pixels.Color(50, 0, 0));
    pixels.setPixelColor(7, pixels.Color(50, 0, 0));
  }
  }
  
    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }
