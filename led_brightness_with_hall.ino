// setting internal leds brightness with hall sensors value

int freq = 5000;
int ledChannel = 0;
int resolution = 8;
int val = 0;
 
void setup() {
 
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_BUILTIN, ledChannel);
  Serial.begin(9600);
}
 
void loop() {
 
  val = hallRead();
  ledcWrite(ledChannel, val);
  delay(7);
 
}