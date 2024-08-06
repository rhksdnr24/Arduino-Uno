#include<LiquidCrystal.h>

int result;
int first;
int second;
String Operator;

const int Pin_rs = 7;
const int Pin_en = 8;
const int Pin_d4 = 9;
const int Pin_d5 = 10;
const int Pin_d6 = 11;
const int Pin_d7 = 12;
const int D_T_1 = 2500;
const int D_T_2 = 5000;

LiquidCrystal lcd(Pin_rs, Pin_en, Pin_d4, Pin_d5, Pin_d6, Pin_d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

float Cal(float f, float s, String O) {
  if(O == "+") {
    return f + s;
  }
  else if(O == "-") {
    return f - s;
  }
  else if(O == "*") {
    return f * s;
  }
  else if(O == "/") {
    return f / s;
  }
}

void I_func(int * Num) {

}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.setCursor(0, 0);
  lcd.print("Put 1st Number ");
  
  while (Serial.available() == 0) {

  }

  first = Serial.parseInt();
  Serial.read();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Your first");
  lcd.setCursor(0, 1);
  lcd.print("Number is :  ");
  lcd.print(first);
  delay(D_T_1);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("choose Operator (+ | - | * | /)");

  while (Serial.available() == 0) {

  }

  Operator = Serial.readString();
  Operator.trim();
  Serial.read();

  lcd.setCursor(0, 0);
  lcd.print("Your Operator");
  lcd.setCursor(0, 1);
  lcd.print("is : ");
  lcd.print(Operator);
  delay(D_T_1);
  lcd.clear();


  lcd.setCursor(0, 0);
  lcd.print("Put 2nd Number ");

  while (Serial.available() == 0) {

  }

  second = Serial.parseInt();
  Serial.read();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Your second");
  lcd.setCursor(0, 1);
  lcd.print("Number is : ");
  lcd.print(second);
  delay(D_T_1);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(first);
  lcd.print(" ");
  lcd.print(Operator);
  lcd.print(" ");
  lcd.print(second);
  lcd.print(" = ");
  lcd.print(Cal(first, second, Operator));
  
  lcd.setCursor(0, 1);
  lcd.print("Thank you");
  
  delay(D_T_2);
  lcd.clear();
}