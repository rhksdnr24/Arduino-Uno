const String msg_1 = "What key do you want to generate?";
const int Pin_1 = 3;
String Key;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Pin_1, OUTPUT);  // 'pinMOde'의 오타 수정
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg_1);  // 'Serial.println(msg_1)l'의 오타 수정

  while (Serial.available() == 0) {
    // 대기 중
  }

  Key = Serial.readString();
  Key.trim();
  if (Key == "Ra") {
    Ra();
  } else if (Key == "Si") {
    Si();
  } else if (Key == "Do") {
    Do();
  }
}

void Ra() {
  while (Serial.available() == 0) {
    analogWrite(Pin_1, 64);
    delayMicroseconds(1136);
    analogWrite(Pin_1, 0);
    delayMicroseconds(1136);
  }
}

void Si() {
  while (Serial.available() == 0) {
    analogWrite(Pin_1, 64);
    delayMicroseconds(1012);
    analogWrite(Pin_1, 0);
    delayMicroseconds(1012);
  }
}

void Do() {
  while (Serial.available() == 0) {
    analogWrite(Pin_1, 64);
    delayMicroseconds(955);
    analogWrite(Pin_1, 0);
    delayMicroseconds(955);
  }
}
