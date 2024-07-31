const int Pin_Input = A0;
const int Pin_1 = 9;
float V;
int readVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Pin_Input, INPUT);
  pinMode(Pin_1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(Pin_Input);
  V = (5. / 1023.) * readVal;
  Serial.println(V);
  
  analogWrite(Pin_1, readVal / 4);
  
  delay(500);


}