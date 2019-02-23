#include <WiFi.h>
 
const char* ssid = "GL62M";
const char* password =  "MagPiMagPi";
 
WiFiServer wifiServer(21567);
 
void setup() {
 
  Serial.begin(115200);
 
  delay(1000);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());
 
  wifiServer.begin();
}
 
void loop() {
 
  WiFiClient client = wifiServer.available();
 
  if (client) {
 
    while (client.connected()) {
 
      while (client.available()>0) {
        char c = client.read();
        String data = "";
        data += c; 
//        client.write(c);
        if(data.lastIndexOf(".") < 0) {
          Serial.println("there isnt dot in last index");
          continue;
          }
        Serial.println(data);
      
      delay(10);
    }
 
    client.stop();
    Serial.println("Client disconnected");
 
  }
  }
  }
