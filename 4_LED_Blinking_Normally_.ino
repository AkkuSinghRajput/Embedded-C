int pin1=1;
int pin2=2;
int pin3=3;
int pin4=4;

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(pin1, HIGH);
  delay(500);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  delay(500);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  delay(500);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, HIGH);
  delay(500);
  digitalWrite(pin4, LOW);
  
  // put your main code here, to run repeatedly:

}
