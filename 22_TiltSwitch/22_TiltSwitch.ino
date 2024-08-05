const int D_T = 250;
const int Pin_Tilt = 13;
const int Pin_Red = 5;
const int Pin_Green = 7;

int readVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Pin_Tilt, INPUT);
  digitalWrite(Pin_Tilt, HIGH);
  pinMode(Pin_Red, OUTPUT);
  pinMode(Pin_Green, OUTPUT);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  readVal = digitalRead(Pin_Tilt);
  Serial.print("Your Button is : ");
  Serial.println(readVal);

  digitalWrite(Pin_Red, LOW);
  digitalWrite(Pin_Green, LOW);
  
  if (readVal == 0) {
    digitalWrite(Pin_Red, HIGH);
  }
  else if (readVal == 1) {
    digitalWrite(Pin_Green, HIGH);
  }

  delay(D_T);
}
