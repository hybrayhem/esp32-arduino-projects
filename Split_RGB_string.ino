/*255,108,112.
  
*/

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  //String rgb = "255,108,112.";
}

// the loop function runs over and over again forever
void loop() {
  String rgb = "255,108,112.";
  // Get Red value from string
  Serial.println(rgb.substring(0,rgb.indexOf(",")));
  // Get Green value from string
  Serial.println(rgb.substring(rgb.indexOf(",")+1,rgb.lastIndexOf(",")));
  // Get Blue value from string
  Serial.println(rgb.substring(rgb.lastIndexOf(",")+1,rgb.length()-1));

  
  while(true){}
}
