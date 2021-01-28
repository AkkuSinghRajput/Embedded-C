int seg1=9,seg2=10;
int led1=2,led2=3,led3=4,led4=5,led5=6,led6=7,led7=8;
int led[]={led1,led2,led3,led4,led5,led6,led7};


void glow(int a,int b,int c,int d,int e,int f,int g)
{
 int  x[]={a,b,c,d,e,f,g};
  for(int i=0;i<7;i++)
  {
    digitalWrite(led[i],x[i]);
  }
}

void seg(int x,int y)
{
  digitalWrite(2,x);
  digitalWrite(3,y);
 }

void num(int x)
{
  if(x==0)
     glow(1,1,1,1,1,1,0);
  if(x==1)
     glow(0,1,1,0,0,0,0);
  if(x==2)
     glow(1,1,0,1,1,0,1);
  if(x==3)
     glow(1,1,1,1,0,0,1);
  if(x==4)
     glow(0,1,1,0,0,1,1);
  if(x==5)
     glow(1,0,1,1,0,1,1);
  if(x==6)
     glow(1,0,1,1,1,1,1);
  if(x==7)
     glow(1,1,1,0,0,0,0);
  if(x==8)
     glow(1,1,1,1,1,1,1);
  if(x==9)
     glow(1,1,1,0,0,1,1);
     
}


void setup() 
{
  pinMode(A0,INPUT);
  Serial.begin(9600);
  for(int i=2;i<10;i++)
  {
    pinMode(led[i],OUTPUT);
   }

}

void loop()
{
  int a=analogRead(A0);
  int b=a/10;
  Serial.println(b);
  delay(10);
  for(int i=0; i<=99; i++)
  {
    if(b==i)
    {
    for(int j=0;j<=60;j++)
     {
      int rem=i%10;
      int divi=i/10;
      seg(1,0);
      num(divi);
      delay(10);
      seg(0,1);
      num(rem);
      delay(10);
  // put your main code here, to run repeatedly:

     }
  }
 }
}
