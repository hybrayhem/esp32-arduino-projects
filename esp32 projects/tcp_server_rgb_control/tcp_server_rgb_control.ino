#include <Adafruit_NeoPixel.h>
 
#define PIN 25

#include <WiFi.h>
 
const char* ssid = "SSID";
const char* password =  "PASSWORD";

int r;
int g;
int b;

String r_string;
String g_string;
String b_string;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);
 
WiFiServer wifiServer(21567);
 
void setup() {

  pixels.begin(); // This initializes the NeoPixel library.
 
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

          // Get Red value from string
          Serial.println(data.substring(0,data.indexOf(",")));
          // Get Green value from string
          Serial.println(data.substring(data.indexOf(",")+1,data.lastIndexOf(",")));
          // Get Blue value from string
          Serial.println(data.substring(data.lastIndexOf(",")+1,data.length()));

          r_string = data.substring(0,data.indexOf(","));
          g_string = data.substring(data.indexOf(",")+1,data.lastIndexOf(","));
          b_string = data.substring(data.lastIndexOf(",")+1,data.length());

          r = r_string.toInt();
          g = g_string.toInt();
          b = b_string.toInt();
          Serial.println(r);
          Serial.println(g);
          Serial.println(b);

          pixels.setPixelColor(0, pixels.Color(r,g,b)); // Moderately bright green color.
          pixels.show(); // This sends the updated pixel color to the hardware.
         
        }
      delay(10);
    }
 
    client.stop();
    Serial.println("Client disconnected");   
  }
  }
  }
