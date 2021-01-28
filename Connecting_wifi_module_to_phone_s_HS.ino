#include<SoftwareSerial.h>
#include<dht.h>
SoftwareSerial esp(2,3);
dht DHT;

#define DHT11_PIN 11


void setup() {
 
 esp.begin(9600);
 Serial.begin(9600);
 espinit();
 
 }
 void sendcmd(String cmd)
{
  esp.println(cmd);
  Serial.println("Sending:");
  Serial.println(cmd);
  String Reply=esp.readString();
  Serial.println(Reply);
  delay(100);
  
}

void espinit()
{
  Serial.println("Enter ssid:");
  delay(4000);
  String ssid=Serial.readString();
  Serial.println("Entered ssid is:");
  Serial.println(ssid);
  Serial.println("Enter password:");
  delay(5000);
  String pass=Serial.readString();
  Serial.println("Entered password is:");
  Serial.println(pass);
 
  int chk= DHT.read11(DHT11_PIN);
  check:
  sendcmd("AT");
  delay(1000);
  sendcmd("AT+CWMODE=1");
  delay(1000);
  
  String wifi="AT+CWJAP=\"";
  wifi+=ssid;
  wifi+="\",\"";
  wifi+=pass;
  wifi+="\"";
  
  sendcmd(wifi);
  delay(1000);
  
 if(esp.find("CONNECTED"))
  {
    sendcmd("AT+CIPMUX=0");
    delay(1000);
  }
  else
 {
 goto check;
    }
  }




void loop()
{
 
 if(esp.find("WIFI CONNECTED"))
 {
 Serial.println("Welcome!");
 }
 
}


