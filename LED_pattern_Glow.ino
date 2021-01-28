
int led1=2, led2=3, led3=4, led4=5;
int led[]={led1,led2,led3,led4};
  
void setup() 
{
  for(int i=0;i<4;i++)
  pinMode(led[i],OUTPUT);
  
  // put your setup code here, to run once:

}

void glow(int a, int b, int c, int d)
{
  int x[]={a,b,c,d};
  for(int i=0;i<4;i++)
  {
    digitalWrite(led[i],x[i]);
    }
}

void loop() 
{
  glow(0,0,0,1);
  delay(1000);
   glow(0,0,1,0);
  delay(1000);
   glow(0,1,0,0);
  delay(1000);
   glow(1,0,0,0);
  delay(1000);
   glow(1,0,0,1);
  delay(1000);
   glow(1,0,1,0);
  delay(1000);
   glow(1,1,0,0);
  delay(1000);
   glow(1,1,0,1);
  delay(1000);
   glow(1,1,1,0);
  delay(1000);
   glow(1,1,1,1);
  delay(1000);  // put your main code here, to run repeatedly:

}
