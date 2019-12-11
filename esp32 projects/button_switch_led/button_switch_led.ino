/*bool push_wait(int time, int btnPin){
  
  if (digitalRead(Buton) == 0){
    delay(1000);
    if (digitalRead(Buton) == 0){
      bool button_waited = True;
    }
    else{
      digitalWrite(Led,HIGH);
    }
  
}*/
const int buton = 0;
const int Led = 2;
int LedStatus = 0;


void setup()
{
  pinMode(buton, INPUT_PULLUP);
  pinMode(Led, OUTPUT);
}

void loop()
{
  if(digitalRead(buton)==HIGH) 
  {
    if(LedStatus == 0){
      digitalWrite(Led, HIGH);
      LedStatus = 1;
      }
    else{
      digitalWrite(Led, LOW);
      LedStatus = 0;
    }
    
    while(1) 
    {
      if(digitalRead(buton)==LOW){
        break ;  
    }
  }
  }
}
