#include "DHT.h"
#define Type DHT11
#include<LiquidCrystal.h>

const int Pin_Sense = 2;
DHT HT(Pin_Sense, Type);
float humidity;
float tempC;
float tempF;

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
  HT.begin();
  Serial.begin(9600);
  delay(D_T_2);
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);
  

  lcd.setCursor(0, 0);
  lcd.print("Here, humidity : ");
  lcd.setCursor(0, 1);
  lcd.print(humidity);
  delay(D_T_1);  
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Here, TempC : ");
  lcd.setCursor(0, 1);
  lcd.print(tempC);
  delay(D_T_1);  
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Here, TempF : ");
  lcd.setCursor(0, 1);
  lcd.print(tempF);
  delay(D_T_1);  
  lcd.clear();

}