/*Program to control LED (ON/OFF) from ESP32 using Serial Bluetooth
 * I am using Serial Bluetooth app from google play store for android side.
 */
#include "BluetoothSerial.h" //Header File for Serial Bluetooth, will be added by default into Arduino
#include <ESP32Servo.h>


BluetoothSerial ESP_BT; //Object for Bluetooth

long incoming;
int servo1 = 15;
int servo2 = 2;
int servo3 = 4;
String number_string;
int degree;

Servo servo_one;
Servo servo_two;
Servo servo_three;

void setup() {
  Serial.begin(115200); //Start Serial monitor in 9600
  ESP_BT.begin("ESP32"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");

  servo_one.setPeriodHertz(50);
  servo_one.attach(servo1, 1000, 2000); // attaches the servo on pin servoPin to the servo object  
  servo_two.setPeriodHertz(50);
  servo_two.attach(servo2, 1000, 2000); // attaches the servo on pin servoPin to the servo object
  servo_three.setPeriodHertz(50);
  servo_three.attach(servo3, 1000, 2000); // attaches the servo on pin servoPin to the servo object
}

void loop() {
  
  if (ESP_BT.available()) //Check if we receive anything from Bluetooth
  {
    incoming = ESP_BT.read(); //Read what we recevive 
    Serial.print("Received:"); Serial.println(incoming);
    if(incoming != 46 && incoming != 97 && incoming != 98 && incoming != 99){
      
      incoming = incoming - 48;
      number_string = number_string + String(incoming);
      Serial.println(number_string);
      }
    
    else {
        degree = number_string.toInt();
        Serial.println(degree);
        number_string = "";
        //////////////////////////
        servo_one.write(degree); 
        delay(20);
        
        servo_two.write(degree); 
        delay(20);
        
        servo_three.write(degree); 
        delay(20);
        
       
      }
      
    }
  delay(20); 
  }
  
