#include <Servo.h>
Servo servo1;
#define S0 2

void setup()
{
pinMode(S0,OUTPUT);

//servo1.attach(9);

servo1.write(90);
delay(800);
servo1.write(0);
delay(800);
servo1.write(90);
delay(800);
}

void loop()
{
digitalWrite(S0,HIGH);
}
