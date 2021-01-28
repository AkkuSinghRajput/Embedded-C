#include "DHT.h"
#define DHTPIN 12
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#include<SoftwareSerial.h>
SoftwareSerial akku(2,3);


void setup() {
 
 akku.begin(9600);
 Serial.begin(9600);
 fun();
  }

void fun()
{
  sendcmd("AT");
  delay(1000);
  sendcmd("AT+CWMODE=1");
  delay(1000);
  sendcmd("AT+CWJAP=\"Let's Work\",\"Letsinternet@121\"");
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
  Serial.print(Reply);
  
}

void loop()
{ 
  float temp=dht.readTemperature();
  sendcmd("AT+CIPSTART=\"TCP\",\"10.5.51.6\",50");
  delay(1000);
  sendcmd("AT+CIPSEND=20");
  delay(1000);
  sendcmd("Temperature: ");
  sendcmd((String)temp);
  sendcmd("\r\n");
  delay(1000);
  
}


