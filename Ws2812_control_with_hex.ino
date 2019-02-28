#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#include <stdlib.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            15

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      1

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 200; // delay for half a second
String hexString = "0,0,255"; 
int r;
int g;
int b;

void setup() {

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  //TODO stringi virgüllerden bölüp int yapacak
    r = hexToDec_R(hexString);
    g = hexToDec_G(hexString)
    b = hexToDec_B(hexString)
    //Color
    pixels.setPixelColor(NUMPIXELS, pixels.Color(r,g,b)); 
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).

  } 
  
  
int hexToDec_R(String hexstring) {
  
  long long number = strtol( &hexstring[1], NULL, 16);

  // Split them up into r, g, b values
  long long r = number >> 16;
  //long long g = number >> 8 & 0xFF;
  //long long b = number & 0xFF;
  
  return r;
}
int hexToDec_G(String hexstring) {
  
  long long number = strtol( &hexstring[1], NULL, 16);

  // Split them up into r, g, b values
//  long long r = number >> 16;
  long long g = number >> 8 & 0xFF;
//  long long b = number & 0xFF;
  
  return g;
}
int hexToDec_B(String hexstring) {
  
  long long number = strtol( &hexstring[1], NULL, 16);

  // Split them up into r, g, b values
//  long long r = number >> 16;
//  long long g = number >> 8 & 0xFF;
  long long b = number & 0xFF;

  return b;
}
