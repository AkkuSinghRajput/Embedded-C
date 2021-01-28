#include<SoftwareSerial.h>
#include<dht.h>
SoftwareSerial esp(2,3);
dht DHT;

#define DHT11_PIN 11
#define baudrate 9600
#define IP "184.106.153.149"

String apiKey="M188DGYBNXO3W2SY";

String ssid="ASUS";
String pass="akanksha";

void setup() 
{
  esp.begin(baudrate);
  Serial.begin(baudrate);
  pinMode(11,INPUT);
  
  espinit();
}

void sendcmd(String cmd)
{
  Serial.print("Sending :");
  Serial.println(cmd);
  esp.println(cmd);
  String rep=esp.readString();
  Serial.print("Reply :");
  Serial.println(rep);
}

void espinit()
{
int chk= DHT.read11(DHT11_PIN);
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
  {
    sendcmd("AT+CIPMUX=0");
    delay(1000);
  }
}
  


void sendesp( String T,String H)
{
 
  String cmd = "AT+CIPSTART=\"TCP\",\"";                        // Setup TCP connection
  cmd += IP;
  cmd += "\",80";
  
  sendcmd(cmd);
  delay(1000);
  if(esp.find("Error" ))
  {
    Serial.print( "RECEIVED: Error\nExit1" );
   //goto check1;
  }
  String GET = "GET /update?key=";
  GET+=apiKey;
  cmd = GET + "&field1=" + T + "&field2=" + H +"\r\n";
  esp.print( "AT+CIPSEND=" );
  esp.println( cmd.length() );
  if(esp.find( ">" ) )
  {
    Serial.print(">");
    Serial.print(cmd);
    esp.print(cmd);
  }
  else
  {
    sendcmd( "AT+CIPCLOSE" );//close TCP connection
    //goto check1;
  }
  if( esp.find("OK") )
  {
    Serial.println( "RECEIVED: OK" );
  }
  else
  {
    Serial.println( "RECEIVED: Error\nExit2" );
    //goto check1;
  }
  sendcmd("AT+CIPCLOSE");
  delay(1000);
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  float t=DHT.temperature;
  float h=DHT.humidity;
  delay(1000);
  Serial.print("Temperature:");
  Serial.println(t);
  Serial.print("Humidity:");
  Serial.println(h);
  sendesp((String)t,(String)h);
 delay(100);
}
