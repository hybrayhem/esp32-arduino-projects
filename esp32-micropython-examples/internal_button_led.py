
#hardware platform: FireBeetle-ESP32
#Result: Blink
#The information below shows blink is unavailble for the current version.
#IO0 IO4 IO10 IO12~19 IO21~23 IO25~27
#Except the connection between IO2 and onboard LED, other pins need to connect to external LEDs. 

import time
import machine 

button = machine.Pin(0, machine.Pin.IN, machine.Pin.PULL_UP)

led=machine.Pin(2,machine.Pin.OUT) #create LED object from pin2,Set Pin2 to output

led.value(1)            #Set led turn on
time.sleep(0.5)
led.value(0)            #Set led turn off
time.sleep(0.5)


while True:
  if(button.value()==0):
    led.value(1)  
  else:
    led.value(0)
  time.sleep(0.1)

