void setup() {
  // put your setup code here, to run once:
  String data_with_dot = "abc.";
  String data_without_dot = "abc";
  Serial.begin(115200);
  Serial.println(data_with_dot.lastIndexOf("."));
  Serial.println(data_without_dot.lastIndexOf("."));
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
