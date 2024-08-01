int light_Pin = A0;
int readVal;
int D_T = 250;
const int Pin_1 = 11;
const int Pin_2 = 12;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(light_Pin, INPUT);
  pinMode(Pin_1, OUTPUT);
  pinMode(Pin_2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(light_Pin);
  Serial.println(readVal);
  
  if (readVal > 400) { 
    digitalWrite(Pin_1, HIGH);
    digitalWrite(Pin_2, LOW);
  }
  else {
    digitalWrite(Pin_1, LOW);
    digitalWrite(Pin_2, HIGH);
  }
  delay(D_T);
}