// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library




// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible value

void NeoPixelsetup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void NeoPixelLoop() {
  pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  //for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    if(ccs.geteCO2()>= 400 & ccs.geteCO2()< 500)
    {
    pixels.setPixelColor(0, pixels.Color(0, 50, 0));
    pixels.setPixelColor(1, pixels.Color(0, 50, 0));
    pixels.setPixelColor(2, pixels.Color(0, 50, 0));
    }
    else
    {
      if(ccs.geteCO2()>= 500 & ccs.geteCO2()< 700)
      {
    pixels.setPixelColor(0, pixels.Color(0, 50, 0));
    pixels.setPixelColor(1, pixels.Color(0, 50, 0));
    pixels.setPixelColor(2, pixels.Color(0, 50, 0));
    pixels.setPixelColor(3, pixels.Color(50, 50, 0));
    pixels.setPixelColor(4, pixels.Color(50, 50, 0));
    
      }
      else{
        if(ccs.geteCO2()>= 700 & ccs.geteCO2()< 1000)
        {
    pixels.setPixelColor(0, pixels.Color(0, 50, 0));
    pixels.setPixelColor(1, pixels.Color(0, 50, 0));
    pixels.setPixelColor(2, pixels.Color(0, 50, 0));
    pixels.setPixelColor(3, pixels.Color(50, 50, 0));
    pixels.setPixelColor(4, pixels.Color(50, 50, 0));
    pixels.setPixelColor(5, pixels.Color(100, 25, 0));
    pixels.setPixelColor(6, pixels.Color(100, 25, 0));
        }
    else
    { 
    pixels.setPixelColor(0, pixels.Color(0, 50, 0));
    pixels.setPixelColor(1, pixels.Color(0, 50, 0));
    pixels.setPixelColor(2, pixels.Color(0, 50, 0));
    pixels.setPixelColor(3, pixels.Color(50, 50, 0));
    pixels.setPixelColor(4, pixels.Color(50, 50, 0));
    pixels.setPixelColor(5, pixels.Color(100, 25, 0));
    pixels.setPixelColor(6, pixels.Color(100, 25
    , 0));
    pixels.setPixelColor(7, pixels.Color(50, 0, 0));
   
    
        
      }
    }
    }

    pixels.show();   // Send the updated pixel colors to the hardware.

    // Pause before next pass through loop
  }
