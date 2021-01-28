#include "DHT.h"

#define DHTPIN 12 
#define DHTTYPE DHT11 
DHT akanksha(DHTPIN,DHTTYPE);
 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Temperature is:");
  akanksha.begin();
  pinMode(3,OUTPUT);
  

}

void loop() 
{
  int i, t=akanksha.readTemperature();
  Serial.print("temperature:");
  Serial.print(t);
  Serial.println("*c");

 if(t==i)
{
  for(int i=0;i<=100;i+t)
  {
    analogWrite(3,i);
    delay(10);
  }
 }
 }
