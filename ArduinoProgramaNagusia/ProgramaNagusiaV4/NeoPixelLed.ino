void NeoPixelSetup (void){
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

/* Funtzioa: void NeoPixelLoop (void)
 * Zeregina: CO2 maila bakoitzean led bidez egoera adierazi
 * Erabilitako liburutegiak: <Wire.h>
                             <Adafruit_GFX.h>
                             <Adafruit_SSD1306.h>
 * Liburutegia nondik hartuta: GitHub
 * Bueltatzen duena: ezer
 * Sartutako parametroak: ezer
 *  */
void NeoPixelLoop (void){
CCS811sentsorealoop();
  pixels.clear(); // Set all pixel colors to 'off'

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:

    if ((ccs.geteCO2()>=400)&&(ccs.geteCO2()<700)){
      pixels.setPixelColor(0, pixels.Color(0, 20, 0));
      pixels.setPixelColor(1, pixels.Color(0, 20, 0));
      pixels.setPixelColor(2, pixels.Color(0, 20, 0));
      pixels.setPixelColor(3, pixels.Color(0, 20, 0));
      pixels.setPixelColor(4, pixels.Color(0, 20, 0));
      pixels.setPixelColor(5, pixels.Color(0, 20, 0));
      pixels.setPixelColor(6, pixels.Color(0, 20, 0));
      pixels.setPixelColor(7, pixels.Color(0, 20, 0));
    }
    else{
      if ((ccs.geteCO2()>=700)&&(ccs.geteCO2()<800)){
        pixels.setPixelColor(0, pixels.Color(20, 20, 0));
        pixels.setPixelColor(1, pixels.Color(20, 20, 0));
        pixels.setPixelColor(2, pixels.Color(20, 20, 0));
        pixels.setPixelColor(3, pixels.Color(0, 20, 0));
        pixels.setPixelColor(4, pixels.Color(0, 20, 0));
        pixels.setPixelColor(5, pixels.Color(0, 20, 0));
        pixels.setPixelColor(6, pixels.Color(0, 20, 0));
        pixels.setPixelColor(7, pixels.Color(0, 20, 0));
      }
      else{
        if ((ccs.geteCO2()>=800)&&(ccs.geteCO2()<900)){
        pixels.setPixelColor(0, pixels.Color(20, 20, 0));
        pixels.setPixelColor(1, pixels.Color(20, 20, 0));
        pixels.setPixelColor(2, pixels.Color(20, 20, 0));
        pixels.setPixelColor(3, pixels.Color(20, 20, 0));
        pixels.setPixelColor(4, pixels.Color(20, 20, 0));
        pixels.setPixelColor(5, pixels.Color(0, 20, 0));
        pixels.setPixelColor(6, pixels.Color(0, 20, 0));
        pixels.setPixelColor(7, pixels.Color(0, 20, 0));         
        }
        else{
          if((ccs.geteCO2()>=900)&&(ccs.geteCO2()<1000)){
        pixels.setPixelColor(0, pixels.Color(20, 20, 0));
        pixels.setPixelColor(1, pixels.Color(20, 20, 0));
        pixels.setPixelColor(2, pixels.Color(20, 20, 0));
        pixels.setPixelColor(3, pixels.Color(20, 20, 0));
        pixels.setPixelColor(4, pixels.Color(20, 20, 0));
        pixels.setPixelColor(5, pixels.Color(20, 20, 0));
        pixels.setPixelColor(6, pixels.Color(20, 20, 0));
        pixels.setPixelColor(7, pixels.Color(20, 20, 0));  
          }
          else{
            if((ccs.geteCO2()>=1000)&&(ccs.geteCO2()<1200)){
        pixels.setPixelColor(0, pixels.Color(20, 0, 0));
        pixels.setPixelColor(1, pixels.Color(20, 0, 0));
        pixels.setPixelColor(2, pixels.Color(20, 0, 0));
        pixels.setPixelColor(3, pixels.Color(20, 20, 0));
        pixels.setPixelColor(4, pixels.Color(20, 20, 0));
        pixels.setPixelColor(5, pixels.Color(20, 20, 0));
        pixels.setPixelColor(6, pixels.Color(20, 20, 0));
        pixels.setPixelColor(7, pixels.Color(20, 20, 0)); 
            }
            else{
              if((ccs.geteCO2()>=1200)&&(ccs.geteCO2()<1500)){
        pixels.setPixelColor(0, pixels.Color(20, 0, 0));
        pixels.setPixelColor(1, pixels.Color(20, 0, 0));
        pixels.setPixelColor(2, pixels.Color(20, 0, 0));
        pixels.setPixelColor(3, pixels.Color(20, 0, 0));
        pixels.setPixelColor(4, pixels.Color(20, 0, 0));
        pixels.setPixelColor(5, pixels.Color(20, 20, 0));
        pixels.setPixelColor(6, pixels.Color(20, 20, 0));
        pixels.setPixelColor(7, pixels.Color(20, 20, 0)); 
              }
              else{
        pixels.setPixelColor(0, pixels.Color(20, 0, 0));
        pixels.setPixelColor(1, pixels.Color(20, 0, 0));
        pixels.setPixelColor(2, pixels.Color(20, 0, 0));
        pixels.setPixelColor(3, pixels.Color(20, 0, 0));
        pixels.setPixelColor(4, pixels.Color(20, 0, 0));
        pixels.setPixelColor(5, pixels.Color(20, 0, 0));
        pixels.setPixelColor(6, pixels.Color(20, 0, 0));
        pixels.setPixelColor(7, pixels.Color(20, 0, 0)); 
              }
            }
          }
        }
      }
    }

    pixels.show();   // Send the updated pixel colors to the hardware.
}
