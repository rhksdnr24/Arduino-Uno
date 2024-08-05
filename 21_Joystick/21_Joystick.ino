const String msg_1 = "X value = ";
const String msg_2 = " Y value = ";
const String msg_3 = " Switch State is ";

const int D_T = 250;
const int Xpin = A0;
const int Ypin = A1;
const int Spin = 2;

int Xval;
int Yval;
int Sval;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Xpin, INPUT);
  pinMode(Ypin, INPUT);
  pinMode(Spin, INPUT);
  digitalWrite(Spin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Sval = digitalRead(Spin);

  Serial.print(msg_1);
  Serial.print(Xval);
  Serial.print(msg_2);
  Serial.print(Yval);
  Serial.print(msg_3);
  Serial.println(Sval);

  delay(D_T);
}
