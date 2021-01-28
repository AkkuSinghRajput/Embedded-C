#include "DHT.h"
#define DHTPIN 12
#define led 5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#include<SoftwareSerial.h>
SoftwareSerial akku(2,3);


void setup() {
 
 akku.begin(9600);
 Serial.begin(9600);
 pinMode(5,OUTPUT);
 fun();
  }

void fun()
{
  sendcmd("AT");
  delay(1000);
  sendcmd("AT+CWMODE=1");
  delay(1000);
  sendcmd("AT+CWJAP=\"ASUSAkku\",\"Akanksha06\"");
  delay(1000);
  sendcmd("AT+CIPMUX=0");
  delay(1000);
}

void sendcmd(String cmd)
{
  akku.println(cmd);
  Serial.print("Sending:");
  Serial.println(cmd);
  String Reply=akku.readString();
  Serial.println("Reply: ");
  Serial.print(Reply);
  
}

void loop()
{ sendcmd("\n");
  float temp=dht.readTemperature();
  sendcmd("AT+CIPSTART=\"TCP\",\"192.168.43.68\",50");
  delay(1000);
  if(akku.find("hello"))
  {
    digitalWrite(5,HIGH);
     delay(1000);
     digitalWrite(5,LOW);
  }
  sendcmd("AT+CIPSEND=20");
  delay(1000);
  sendcmd("Temperature: ");
  sendcmd(String (temp));
  sendcmd("\n");
  }
  
