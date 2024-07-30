const int Pin_1 = 3;
const int Pin_2 = 5;
const int Pin_3 = 6;
const int Pin_4 = 9;


void setup() {
  // put your setup code here, to run once:
pinMode(Pin_1, OUTPUT);
pinMode(Pin_2, OUTPUT);
pinMode(Pin_3, OUTPUT);
pinMode(Pin_4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i = 0; i < 256; i++) {
  analogWrite(Pin_1, i);
  analogWrite(Pin_2, (i + 64) % 255);
  analogWrite(Pin_3, (i + 128) % 255);
  analogWrite(Pin_4, (i + 192) % 255);

  delay(10);
}
}
