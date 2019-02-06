// Digital ruler with vl53l0x tof sensor 
// How to Use:
/* Put your sensor to a solid object and press to internal button. İf the distance between object and sensor bigger than 15cm internal led lights as warning. Else led light X time. X = value of the distance as cantimetres.*/

#include "Adafruit_VL53L0X.h"

void blink(int Led, int time,int wait){
  while (time > 0){
    digitalWrite(Led, HIGH);
    delay(wait);
    digitalWrite(Led, LOW);
    delay(wait);
    time--;
  }
}


Adafruit_VL53L0X lox = Adafruit_VL53L0X();

const int buton = 0;
const int Led = 2;
int LedStatus = 0;
int distance;
int cm;
 
void setup()
{

pinMode(buton, INPUT_PULLUP);
pinMode(Led, OUTPUT);

Serial.begin(115200);
 
// wait until serial port opens for native USB devices
while (! Serial)
{
delay(1);
}
 
Serial.println("Adafruit VL53L0X test");
if (!lox.begin())
{
Serial.println(F("Failed to boot VL53L0X"));
while(1);
}
// power
Serial.println(F("VL53L0X API Simple Ranging example\n\n"));
}
 
void loop()
{
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);
  if(digitalRead(buton)==LOW) 
  {
    //butona basıldı
    distance = (measure.RangeMilliMeter)-28;
    cm = (distance/10);
    Serial.println(distance);
    Serial.println(cm);
    if(cm <= 15){
    blink(Led,cm,200);
    }
    else{
      blink(Led,5,50);
    }
  }
}
/*VL53L0X_RangingMeasurementData_t measure;
 
Serial.print("Reading a measurement... ");
lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
 
if (measure.RangeStatus != 4)
{ // phase failures have incorrect data
Serial.print("Distance (mm): "); Serial.println((measure.RangeMilliMeter)-30);  // -30u ben ekledim
}
else
{
Serial.println(" out of range ");
}
 
delay(100);*/
