// This program setting pwm on pin 2. Pin 2 is internal leds pin, also there is another pin 2 on header. You can set servos angle and led brightness with same code. Because they are connected to same pin.

 #define COUNT_LOW 0
 #define COUNT_HIGH 8888

 #define TIMER_WIDTH 16

#include "esp32-hal-ledc.h"

void setup() {
   ledcSetup(1, 50, TIMER_WIDTH); // channel 1, 50 Hz, 16-bit width
   ledcAttachPin(2, 1);   // GPIO 13 assigned to channel 1
}

void loop() {
   for (int i=COUNT_LOW ; i < COUNT_HIGH ; i=i+100)
   {
      ledcWrite(1, i);       // sweep servo 1
      delay(50);
   }
}
