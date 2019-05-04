#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "auth_token";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SSID";
char pass[] = "PASSWORD";

Servo servo0;
Servo servo1;
Servo servo2;
void setup() {  
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");  
  Blynk.begin(auth, ssid, pass);
  
  servo0.setPeriodHertz(50);
  servo0.attach(15);
  servo1.setPeriodHertz(50);
  servo1.attach(2);
  servo2.setPeriodHertz(50);
  servo2.attach(4);
}
BLYNK_WRITE(V15)
{
servo0.write(param.asInt());
Serial.println(param.asInt());
}
BLYNK_WRITE(V2)
{
servo1.write(param.asInt());
Serial.println(param.asInt());

}
BLYNK_WRITE(V4)
{
servo2.write(param.asInt());
Serial.println(param.asInt());
}

void loop(){
    Blynk.run();
}
