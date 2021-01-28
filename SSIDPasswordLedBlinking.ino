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
    String str=Serial.readString();
    Serial.print('\n');
    Serial.print("Entered ID is:");
    Serial.print(str);
    return str;
  }
  else
  {
    goto check1;
  }
}

String PD()
{
  Serial.print("Enter Password:");
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
  Serial.print("Entered ID: ");
  String str=Serial.readString();
  Serial.println(str);
  if(str==SSID)
  {
    
   Serial.println("ID is Correct");
   {
    Serial.print("Enter Password for your verification: ");
    String a=Serial.readString();
    Serial.print('\n');
    Serial.print("Entered password for your verification: ");
    Serial.print(a);
    Serial.print('\n');
    if( a==PASSWORD  ) // loop to blink green led and buzzer if both id and password is correct
    {
   
     
     Serial.print("Password is Correct");
     digitalWrite(2,HIGH);
     digitalWrite(3,LOW);
    
    }
        else if(a!=PASSWORD) // loop to blink red led and buzzer if password is incorrect
  {
    
    digitalWrite(3,HIGH);
    digitalWrite(2,LOW);
    delay(1000);
    Serial.print('\n');
    Serial.println("Password is InCorrect");
    
  }
    
    }
     }     
     else if(str!=SSID) // loop to blink red led and buzzer if id is incorrect
  {
   
    digitalWrite(3,HIGH);
    digitalWrite(2,LOW);
    delay(1000);
    Serial.println("ID is InCorrect");
    
  }
  }
  }
