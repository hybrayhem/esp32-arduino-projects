const int potpin = A0;  

const int escpin = 9;
int val;   

void setup(){ 
  pinMode(potpin, INPUT);//Potansiyometre pinimizi input olarak tanımladık.
  pinMode(escpin, OUTPUT);//ESC pinimizi output olarak tanımlandık.
  Serial.begin(9600);
} 

void loop(){ 
  val = analogRead(potpin); //İnputumuzun Analog input         
  val = map(val, 0, 1023, 0, 179); 
  Serial.println(val);    
  analogWrite(escpin,val);
  delay(15);                          
} 
