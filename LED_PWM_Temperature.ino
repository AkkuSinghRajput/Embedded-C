#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT anmol(DHTPIN, DHTTYPE);
int led=3;
void setup()
{pinMode(3,OUTPUT);
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  anmol.begin();
 
}
void loop()
{
  int i,t=anmol.readTemperature();
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println("*c");
 
  for(int i=t;i<=255;i++t
  {
   analogWrite(3,i);
   delay(10);
  } 
}
