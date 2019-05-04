#include <WiFi.h>
 
const char* ssid = "SSID";
const char* password =  "PASSWORD";
 
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
      String data = "";
      while (client.available()>0) {
        char c = client.read();
        data = data + c;
//        client.write(c);

        if(data.lastIndexOf(".") < 0) {
//          Serial.println("appending data pieces:"+data);
          continue;
          }
        else{
          data = data.substring(0, data.length()-1);
          Serial.println("final data: " + data); 
//          break;
        }
      delay(10);
    }
 
    client.stop();
    Serial.println("Client disconnected");
 
  }
  }
  }
