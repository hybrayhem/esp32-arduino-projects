/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>
 modified on 30 Mar 2019
 by Halil ibrahim ilhan
*/

#include <Servo.h>


// robot geometry
 // (look at pics above for explanation)
 const float e = 45.0;     // end effector
 const float f = 152.0;     // base
 const float re = 552.0;
 const float rf = 165.0;

int position_status;
float alfa1;
float alfa2;
float alfa3;

float dc = 6.0; // divide constant

float x = 0;
float y = 0;
float z = 650.0;

float newX;
float newY;
float newZ;

 // trigonometric constants
 const float sqrt3 = sqrt(3.0);
 const float pi = 3.141592653;    // PI
 const float sin120 = sqrt3/2.0;   
 const float cos120 = -0.5;        
 const float tan60 = sqrt3;
 const float sin30 = 0.5;
 const float tan30 = 1/sqrt3;
// robot geometry

Servo myservo;  // create servo object to control a servo
Servo myservo1;
Servo myservo2;

int potpin = 0;  // analog pin used to connect the potentiometer
int potpin1 = 1;
int potpin2 = 2;
int butonpin = 2;
int val;    // variable to read the value from the analog pin
int val1;
int val2;
int butonState = 0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo1.attach(10);
  myservo2.attach(11);
  Serial.begin(9600);
  pinMode(butonpin, INPUT_PULLUP);
}

void loop() {
  butonState = digitalRead(butonpin);
//  Serial.println(butonState);
  
  val = analogRead(potpin) -512;            // reads the value of the potentiometer (value between 0 and 1023)
  newX = x + float(val) / dc;
//  Serial.println("x: "+String(x));
  //val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  //myservo.write(val);                  // sets the servo position according to the scaled value
  //delay(15);                           // waits for the servo to get there
  
  val1 = analogRead(potpin1) -512;            // reads the value of the potentiometer (value between 0 and 1023)
  newY = y + float(val1) / dc;
//  Serial.println("y: "+String(y));
  //val1 = map(val1, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  //myservo1.write(val1);                  // sets the servo position according to the scaled value
  //delay(15);                           // waits for the servo to get there
  
  val2 = analogRead(potpin2) -512;            // reads the value of the potentiometer (value between 0 and 1023)
  newZ = z + float(val2) / dc;
//  Serial.println("z: "+String(z));
  //val2 = map(val2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  //myservo2.write(val2);                  // sets the servo position according to the scaled value
  //delay(15);                           // waits for the servo to get there

  position_status = delta_calcInverse(x, y, z, alfa1, alfa2, alfa3);
  Serial.println(position_status);
  
  if(position_status == 0){
//    Serial.println("position changed");
    x = newX;
    y = newY;
    z = newZ;
  Serial.println("                                                                         ");
  Serial.println("alfa1: "+ String(alfa1)+" alfa2: "+ String(alfa2)+" alfa3: "+ String(alfa3));
  Serial.println("                                                                         ");

    }
//  Serial.println("                                                                         ");
//  Serial.println("alfa1: "+ String(alfa1)+" alfa2: "+ String(alfa2)+" alfa3: "+ String(alfa3));
//  Serial.println("                                                                         ");

  delay(250);
}


// forward kinematics: (theta1, theta2, theta3) -> (x0, y0, z0)
 // returned status: 0=OK, -1=non-existing position
 int delta_calcForward(float theta1, float theta2, float theta3, float &x0, float &y0, float &z0) {
     float t = (f-e)*tan30/2;
     float dtr = pi/(float)180.0;
 
     theta1 *= dtr;
     theta2 *= dtr;
     theta3 *= dtr;
 
     float y1 = -(t + rf*cos(theta1));
     float z1 = -rf*sin(theta1);
 
     float y2 = (t + rf*cos(theta2))*sin30;
     float x2 = y2*tan60;
     float z2 = -rf*sin(theta2);
 
     float y3 = (t + rf*cos(theta3))*sin30;
     float x3 = -y3*tan60;
     float z3 = -rf*sin(theta3);
 
     float dnm = (y2-y1)*x3-(y3-y1)*x2;
 
     float w1 = y1*y1 + z1*z1;
     float w2 = x2*x2 + y2*y2 + z2*z2;
     float w3 = x3*x3 + y3*y3 + z3*z3;
     
     // x = (a1*z + b1)/dnm
     float a1 = (z2-z1)*(y3-y1)-(z3-z1)*(y2-y1);
     float b1 = -((w2-w1)*(y3-y1)-(w3-w1)*(y2-y1))/2.0;
 
     // y = (a2*z + b2)/dnm;
     float a2 = -(z2-z1)*x3+(z3-z1)*x2;
     float b2 = ((w2-w1)*x3 - (w3-w1)*x2)/2.0;
 
     // a*z^2 + b*z + c = 0
     float a = a1*a1 + a2*a2 + dnm*dnm;
     float b = 2*(a1*b1 + a2*(b2-y1*dnm) - z1*dnm*dnm);
     float c = (b2-y1*dnm)*(b2-y1*dnm) + b1*b1 + dnm*dnm*(z1*z1 - re*re);
  
     // discriminant
     float d = b*b - (float)4.0*a*c;
     if (d < 0) return -1; // non-existing point
 
     z0 = -(float)0.5*(b+sqrt(d))/a;
     x0 = (a1*z0 + b1)/dnm;
     y0 = (a2*z0 + b2)/dnm;
     return 0;
 }
 
 // inverse kinematics
 // helper functions, calculates angle theta1 (for YZ-pane)
 int delta_calcAngleYZ(float x0, float y0, float z0, float &theta) {
     float y1 = -0.5 * 0.57735 * f; // f/2 * tg 30
     y0 -= 0.5 * 0.57735    * e;    // shift center to edge
     // z = a + b*y
     float a = (x0*x0 + y0*y0 + z0*z0 +rf*rf - re*re - y1*y1)/(2*z0);
     float b = (y1-y0)/z0;
     // discriminant
     float d = -(a+b*y1)*(a+b*y1)+rf*(b*b*rf+rf); 
     if (d < 0) return -1; // non-existing point
     float yj = (y1 - a*b - sqrt(d))/(b*b + 1); // choosing outer point
     float zj = a + b*yj;
     theta = 180.0*atan(-zj/(y1 - yj))/pi + ((yj>y1)?180.0:0.0);
     return 0;
 }
 
 // inverse kinematics: (x0, y0, z0) -> (theta1, theta2, theta3)
 // returned status: 0=OK, -1=non-existing position
 int delta_calcInverse(float x0, float y0, float z0, float &theta1, float &theta2, float &theta3) {
     theta1 = theta2 = theta3 = 0;
     int status = delta_calcAngleYZ(x0, y0, z0, theta1);
     if (status == 0) status = delta_calcAngleYZ(x0*cos120 + y0*sin120, y0*cos120-x0*sin120, z0, theta2);  // rotate coords to +120 deg
     if (status == 0) status = delta_calcAngleYZ(x0*cos120 - y0*sin120, y0*cos120+x0*sin120, z0, theta3);  // rotate coords to -120 deg
     return status;
 }
