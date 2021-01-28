String SSID;
String PASSWORD;

int ledgreen=2, ledred=3;


String ID()
{
  Serial.print("Enter SSID: ");
  check1:
  char ch=Serial.read();
   if(ch=='*')
    {
     String str=Serial.read();
     Serial.print('\n');
     Serial.print("Entered ID is:");
     Serial.print(str);
     return str;
    }
  else if  
  {
    goto check1;
  }
  
String PD()
 {
  Serial.print("Enter Password:");
  delay(1000);
  check2:
  char ch=Serial.read();
  if(ch=='*')
  {
    String str=Serial.readString();
    Serial.print('\n');
    Serial.print("Entered password:");
    Serial.println(str);
    Serial.println("Enter ID For Varification:");
    return str;
  }
  else
  {
    goto check2;
  }
}

void setup()
{
  Serial.begin(9600);
  SSID=ID();
  PASSWORD=PD();
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop() 
{
  if(Serial.available())
  {
    Serial.println("Enter SSID: ");
    String ch=Serial.readString();
    Serial.print(ch);
    if(ch==SSID)
        {
         Serial.println("ID is CORRECT");
         digitalWrite(2,HIGH);
         digitalWrite(3,LOW);
         {
            Serial.println("Enter Password: ");
            String ps=Serial.readString();
            Serial.print("Entered password: ");
            Serial.print(ps);
               if(ps==PASSWORD)
               {
                Serial.println("Correct Password, Welcome!");
                Serial.println("SSID is CORRECT");
                digitalWrite(2,HIGH);
                digitalWrite(3,LOW);
                 }
           
              else
                {
                 digitalWrite(3,HIGH);
                 digitalWrite(2,LOW);
                 Serial.println("Password is INCORRECT");
                }
          }
         
   }
   
    else if(ch!=SSID)
     {
       digitalWrite(3,HIGH);
       digitalWrite(2,LOW);
       Serial.println("ID is INCORRECT");
       }
  }

}
