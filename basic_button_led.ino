// While button pressed led lights up

#define Buton 0
#define Led 2
void setup()
{
  pinMode(Buton, INPUT_PULLUP);
  pinMode(Led, OUTPUT);
}

void loop()
{
  if (digitalRead(Buton) == 0){
  digitalWrite(Led,HIGH);
    }
  else{
  digitalWrite(Led,LOW);}
}
