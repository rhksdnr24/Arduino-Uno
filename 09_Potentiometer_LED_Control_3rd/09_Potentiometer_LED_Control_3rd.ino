const int Pin_1 = 2;
const int Pin_2 = 3;
const int Pin_3 = 4;
const int Pin_4 = 5;
const float eps = 0.000001;

const int Pin_Input = A0;

float V;
int readVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(Pin_1, OUTPUT);
  pinMode(Pin_2, OUTPUT);
  pinMode(Pin_3, OUTPUT);
  pinMode(Pin_4, OUTPUT);
  Serial.begin(9600);
  // pinMode(Pin_Input, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(Pin_Input);
  V = (5. / 1023.) * readVal;
  Serial.println(V);

  if (fabs(V) < eps || V < 1.25) {
    digitalWrite(Pin_1, HIGH);
    digitalWrite(Pin_2, LOW);
    digitalWrite(Pin_3, LOW);
    digitalWrite(Pin_4, LOW);
  }

  else if (V >= 1.25 && V < 2.5) {
    digitalWrite(Pin_1, LOW);
    digitalWrite(Pin_2, HIGH);
    digitalWrite(Pin_3, LOW);
    digitalWrite(Pin_4, LOW);
  }

  else if (V >= 2.5 && V < 3.75) {
    digitalWrite(Pin_1, LOW);
    digitalWrite(Pin_2, LOW);
    digitalWrite(Pin_3, HIGH);
    digitalWrite(Pin_4, LOW);
  }

  else {
    digitalWrite(Pin_1, LOW);
    digitalWrite(Pin_2, LOW);
    digitalWrite(Pin_3, LOW);
    digitalWrite(Pin_4, HIGH);
  }
  delay(250);
}
