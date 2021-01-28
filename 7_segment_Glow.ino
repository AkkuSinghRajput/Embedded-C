int led1=2,  led2=3,  led3=4,  led4=5,  led5=6,  led6=7,  led7=8; 
int coma=9, comb=10;
int led[]={led1, led2, led3, led4, led5, led6, led7};

void segment(int x,int y)
{
  digitalWrite(9,x);
  digitalWrite(10,y);
  
}

void glow(int a,int b,int c,int d,int e,int f,int g)
{ for(int i=0;i<7;i++)
  {int x[]={a,b,c,d,e,f,g};
  digitalWrite(led[i],x[i]);
  }
}

void setup()
{
  for(int i=2;i<=10;i++)
  digitalWrite(i,OUTPUT);
}

void loop()
{
 segment(0,1);
 glow(1,1,1,1,1,1,1);
 delay(100);
 segment(1,0);
 glow(1,1,1,0,0,0,0);
 delay(100);
}
