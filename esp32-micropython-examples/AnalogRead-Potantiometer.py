import machine
from time import sleep
adc = machine.ADC(machine.Pin(36))
while True:
  print(adc.read())
  sleep(0.1)
