#include<LiquidCrystal.h>

const int Pin_rs = 7;
const int Pin_en = 8;
const int Pin_d4 = 9;
const int Pin_d5 = 10;
const int Pin_d6 = 11;
const int Pin_d7 = 12;

LiquidCrystal lcd(Pin_rs, Pin_en, Pin_d4, Pin_d5, Pin_d6, Pin_d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 10; i++) {
    lcd.setCursor(0, 0);
    lcd.print("Hello World");
    lcd.setCursor(0, 1);
    lcd.print(i);
    delay(100);
    lcd.clear();
  }
  
}