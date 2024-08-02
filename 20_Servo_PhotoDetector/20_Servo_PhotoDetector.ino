#include <Servo.h>
const int Pin_Servo = 9;
const int Pin_Input = A0;
int ServoPos;
Servo myServo;
int readVal;

const String msg_1 = "Your Servo turned to ";
const int D_T = 2000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(Pin_Servo);
  pinMode(Pin_Input, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(Pin_Input);
  ServoPos = (readVal - 400) * (180. / 600.);
  myServo.write(ServoPos);  
  Serial.print(msg_1);
  Serial.println(ServoPos);
  delay(D_T);
}
