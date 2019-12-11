void blink(int Led, int time,int wait){
  while (time > 0){
    digitalWrite(Led, HIGH);
    delay(wait);
    digitalWrite(Led, LOW);
    delay(wait);
    time--;
  }
}
int Led = 2;
int buton = 0;
void setup()
{
  pinMode(buton, INPUT_PULLUP);
  pinMode(Led, OUTPUT);
}

void loop()
{
  if(digitalRead(buton)==LOW) 
  {
    blink(Led,2,250);
    
    /*while(1) 
    {
      if(digitalRead(buton)==LOW){
        
        break ;  
    }*/
  }
}
