const int D_T = 500;
const int Pin_Latch = 11;
const int Pin_Clock = 9;
const int Pin_Data = 12;
long Number;
const String msg_1 = "Choose the number You want to sift right ";
const String msg_2 = "Choose the number You want to sift left ";
byte LEDs = 0x00;
String input;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Pin_Latch, OUTPUT);
  pinMode(Pin_Clock, OUTPUT);
  pinMode(Pin_Data, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(msg_1);
  while(Serial.available() == 0) {

  }
  input = Serial.readStringUntil('\n'); // 사용자 입력 받기
  input.trim(); // 공백 제거
  Number = strtol(input.c_str(), NULL, 2); // 이진수 문자열을 숫자로 변환
  Serial.println(Number);
  Serial.read();
  LEDs = Number;
  for(int i = 0; i < 8; i++) {
    digitalWrite(Pin_Latch, LOW);
    shiftOut(Pin_Data, Pin_Clock, LSBFIRST, LEDs);
    digitalWrite(Pin_Latch, HIGH);
    LEDs = LEDs >> 1;
    delay(D_T);
  }
  Serial.print(msg_2);
  while(Serial.available() == 0) {

  }
  input = Serial.readStringUntil('\n'); // 사용자 입력 받기
  input.trim(); // 공백 제거
  Number = strtol(input.c_str(), NULL, 2); // 이진수 문자열을 숫자로 변환
  Serial.read();
  LEDs = Number;
  for(int i = 0; i < 8; i++) {
    digitalWrite(Pin_Latch, LOW);
    shiftOut(Pin_Data, Pin_Clock, LSBFIRST, LEDs);
    digitalWrite(Pin_Latch, HIGH);
    LEDs = LEDs << 1;
    Serial.println(LEDs);
    delay(D_T);
  }
}