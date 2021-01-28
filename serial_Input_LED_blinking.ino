int led1=2, led2=3;


void setup()
{ Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  // put your setup code here, to run once:

}

void loop()
{ if(Serial.available())
  {
  char ch=Serial.read(), a,b;
  Serial.print(ch);
  // put your main code here, to run repeatedly:
  if (ch=='a')
  {digitalWrite(2,HIGH);}
   if(ch=='b')
  {digitalWrite(3,HIGH);}
   if (ch=='c')
  {digitalWrite(2,LOW);}
   if(ch=='d')
  {digitalWrite(3,LOW);}
}
}
