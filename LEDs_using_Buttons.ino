int led1=2,led2=3,led3=4,led4=5;
int led[]={led1,led2,led3,led4};
int button1=6,button2=7,button3=8,button4=9;

void setup()
{
  pinMode(6,INPUT);
  pinMode(2,OUTPUT);
  pinMode(7,INPUT);
  pinMode(3,OUTPUT);
  pinMode(8,INPUT);
  pinMode(4,OUTPUT); 
  pinMode(9,INPUT);
  pinMode(5,OUTPUT);
  // put your setup code here, to run once:

}

void loop()
{
  int a=digitalRead(6);
  int b=digitalRead(7);
  int c=digitalRead(8);
  int d=digitalRead(9);
  if(a==1)
  {
    digitalWrite(2,HIGH);
    }
   if(a==0)
   {
    digitalWrite(2,LOW);
    }
   if(b==1)
   {
    digitalWrite(3,HIGH);
   }
   if(b==0)
   {
    digitalWrite(3,LOW);
   }
    if(c==1)
  {
    digitalWrite(4,HIGH);
    }
   if(c==0)
   {
    digitalWrite(4,LOW);
     if(d==1)
  {
    digitalWrite(5,HIGH);
    }
   if(d==0)
   {
    digitalWrite(5,LOW);
   }
  // put your main code here, to run repeatedly:

}
}
