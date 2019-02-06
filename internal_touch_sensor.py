import machine
from time import sleep

touch_pin = 32

adc = machine.ADC(machine.Pin(touch_pin))
#touch sensor pins gpio 32, 33, 27, 14, 12, 13, 15, 4, 0, 2
while True:
  print(adc.read())
  sleep(0.1)
