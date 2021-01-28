#include "DHT.h"

#define DHTPIN 2 
#define DHTTYPE DHT11 
DHT esp(DHTPIN,DHTTYPE);
 



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Temperature & Humidity");
  esp.begin();
  

}

void loop() {
  // put your main code here, to run repeatedly:
  float h=esp.readHumidity();
  float t=esp.readTemperature();
  Serial.print("Humidity:");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("temperature:");
  Serial.print(t);
  Serial.println("*c");
  

}
