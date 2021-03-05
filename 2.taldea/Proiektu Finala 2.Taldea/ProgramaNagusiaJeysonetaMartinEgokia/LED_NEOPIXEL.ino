/* Funtzioa: void LedNeoPixelSetup void()
 * Zeregina:  
 * Erabilitako liburutegiak: 
 * Liburutegia nondik hartuta: 
 * Bueltatzen duena: ezer
 * Sartutako parametroak: ezer
 *  */
void NeoPixelSetup (void)
{
    #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
    #endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

/* Funtzioa: void LedNeoPixelLoop void()
 * Zeregina: DTH11 Sentsorea irakurri 
 * Erabilitako liburutegiak: 
 * Liburutegia nondik hartuta: 
 * Bueltatzen duena: ezer
 * Sartutako parametroak: ezer
 *  */

void NeoPixelLoop (void)
{
  CCS881SentsoreaLoop ();
  pixels.clear(); // Set all pixel colors to 'off'
  //for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
  // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
  // Here we're using a moderately bright green color:
    /*pixels.setPixelColor(0, pixels.Color(125, 255, 0));
    pixels.setPixelColor(1, pixels.Color(255, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 255, 0));
    pixels.setPixelColor(3, pixels.Color(0, 0, 255));
    pixels.setPixelColor(4, pixels.Color(255, 125, 0));
    pixels.setPixelColor(5, pixels.Color(0, 255, 125));
    pixels.setPixelColor(6, pixels.Color(125, 0, 255));
    pixels.setPixelColor(7, pixels.Color(255, 0, 125));*/
     
    if (ccs.geteCO2()> 400 && ccs.geteCO2()< 750){
      pixels.setPixelColor(0, pixels.Color(0, 255, 0));
      pixels.setPixelColor(1, pixels.Color(0, 255, 0));
      pixels.setPixelColor(2, pixels.Color(0, 255, 0));
    }
    else
    {
      if (ccs.geteCO2()>= 750 && ccs.geteCO2()< 1200){
      pixels.setPixelColor(0, pixels.Color(0, 255, 0));
      pixels.setPixelColor(1, pixels.Color(0, 255, 0));
      pixels.setPixelColor(2, pixels.Color(0, 255, 0));
      pixels.setPixelColor(3, pixels.Color(255, 255, 0));
      pixels.setPixelColor(4, pixels.Color(255, 255, 0));
      pixels.setPixelColor(5, pixels.Color(255, 255, 0));
    }
    else
    {
      pixels.setPixelColor(0, pixels.Color(0, 255, 0));
      pixels.setPixelColor(1, pixels.Color(0, 255, 0));
      pixels.setPixelColor(2, pixels.Color(0, 255, 0));
      pixels.setPixelColor(3, pixels.Color(255, 255, 0));
      pixels.setPixelColor(4, pixels.Color(255, 255, 0));
      pixels.setPixelColor(5, pixels.Color(255, 255, 0));
      pixels.setPixelColor(6, pixels.Color(255, 0, 0));
      pixels.setPixelColor(7, pixels.Color(255, 0, 0)); 
    }
   }

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(100); // Pause before next pass through loop
}
