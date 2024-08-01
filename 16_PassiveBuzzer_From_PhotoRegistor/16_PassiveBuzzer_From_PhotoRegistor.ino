const int Pin_Input = A0;
const int Pin_Output = 8;
int readVal;
int D_T;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Pin_Input, INPUT);
  pinMode(Pin_Output, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(Pin_Input); // 160 ~ 630
  D_T = (9. / 470.) * readVal - (9. * 160. / 470.) + 1.;
  Serial.println(D_T);
  digitalWrite(Pin_Output, HIGH);
  delay(D_T);
  digitalWrite(Pin_Output, LOW);
  delay(D_T);
}