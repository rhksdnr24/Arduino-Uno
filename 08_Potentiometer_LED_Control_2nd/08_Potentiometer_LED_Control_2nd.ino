const int Pin_1 = A0;
const int Pin_2 = 9;
const float epsilon = 0.00000001;
int readVal;
float V;

void setup() {
  // put your setup code here, to run once:
  pinMode(Pin_2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(Pin_1);
  V = (5. / 1023.) * readVal;

  if (V < epsilon) {
    analogWrite(Pin_2, 0);
  }
  // analogWrite(Pin_2, 0);
  else if (V > epsilon && V < 1.25) {
    analogWrite(Pin_2, 63);
  }

  else if (V > 1.25 && V < 2.5) {
    analogWrite(Pin_2, 127);
  }

  else if (V > 2.5 && V < 3.75) {
    analogWrite(Pin_2, 191);
  }

  else if (V > 3.75 && V <= 5.00 + epsilon) {
    analogWrite(Pin_2, 255);
  }
}