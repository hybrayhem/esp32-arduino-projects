void setup() {
  // initialize serial:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    // look for the next valid integer in the incoming serial stream:
    int red = Serial.read();
    // print the three numbers in one string as hexadecimal:
    Serial.println(red);
    if(red == 48){digitalWrite(LED_BUILTIN, LOW);}
    if(red == 49){digitalWrite(LED_BUILTIN, HIGH);}
  }
}
