#include <stdlib.h>   
/*
 Controlling keyes016 led module with Hex code using RGB Hex to Decimal conversation
 */
int groundpin = 8; // write 0 to get ground
int greenpin = 9; // select the pin for the green LED
int redpin = 10; // select the pin for the red LED
int bluepin = 11; // select the pin for the blue LED
String hexString = "7CFC00";

void setup () {
  pinMode (redpin, OUTPUT);
  pinMode (greenpin, OUTPUT);
  pinMode (bluepin, OUTPUT);
  pinMode (groundpin, OUTPUT);
  digitalWrite (groundpin, LOW);
//  Serial.begin(9600);
//  Serial.print(hexToDec_R(hexString));
}
 
void loop () {
  analogWrite (redpin,   hexToDec_R(hexString));
  analogWrite (greenpin, hexToDec_G(hexString));
  analogWrite (bluepin,  hexToDec_B(hexString));
  delay (100);
  
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
