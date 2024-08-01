const int Pin_Input = 12;
const int Pin_Output = 8;
const int D_T = 250;
int readVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Pin_Input, INPUT);
  pinMode(Pin_Output, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = digitalRead(Pin_Input);
  Serial.println(readVal);

  if (readVal == 0) {
    digitalWrite(Pin_Output, HIGH);
  }
  else if (readVal == 1) {
    digitalWrite(Pin_Output, LOW);
  }
  delay(D_T);
}