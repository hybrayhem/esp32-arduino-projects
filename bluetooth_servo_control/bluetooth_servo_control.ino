/*Program to control LED (ON/OFF) from ESP32 using Serial Bluetooth
 * I am using Serial Bluetooth app from google play store for android side.
 */

#include "BluetoothSerial.h" //Header File for Serial Bluetooth, will be added by default into Arduino
#include <ESP32Servo.h>


BluetoothSerial ESP_BT; //Object for Bluetooth

int incoming;
int servoPin = 15;

void setup() {
  Serial.begin(115200); //Start Serial monitor in 9600
  ESP_BT.begin("ESP32"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");

   myservo.setPeriodHertz(50);
  myservo.attach(servoPin, 1000, 2000); // attaches the servo on pin servoPin to the servo object
}

void loop() {
  
  if (ESP_BT.available()) //Check if we receive anything from Bluetooth
  {
    incoming = ESP_BT.read(); //Read what we recevive 
    Serial.print("Received:"); Serial.println(incoming);

    myservo.write(incoming.toInt()); 
  }
  delay(20);
}
