int led1=2, led2=3;


void setup()
{ Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);

}

void loop()
{ if(Serial.available())
  {
  String ch=Serial.readString();
  Serial.print(ch);
  
  if (Serial.readString()=="Akanksha")
  {digitalWrite(2,HIGH);}
  else 
  {digitalWrite(2,LOW);}
  if (Serial.readString()=="Romy")
   {digitalWrite(3,HIGH);}
  else
   {digitalWrite(3,LOW);}
}
}
