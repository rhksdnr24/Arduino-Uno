String Color;
const int Red_Pin = 6;
const int Green_Pin = 5;
const int Blue_Pin = 3;

int Red_Intensity;
int Green_Intensity;
int Blue_Intensity;

const String msg_1 = "Choose the RGB intensity to turn on your LED";
const String msg_2 = "R's intensity : ";
const String msg_3 = "G's intensity : ";
const String msg_4 = "B's intensity : ";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Red_Pin, OUTPUT);
  pinMode(Green_Pin, OUTPUT);
  pinMode(Blue_Pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg_1);

  while(Serial.available() == 0) {

  }
  Red_Intensity = Serial.parseInt();
  Serial.print(msg_2);
  Serial.println(Red_Intensity);
  while(Serial.available() > 0) {
    Serial.read();
  }

  while(Serial.available() == 0) {

  }
  Green_Intensity = Serial.parseInt();
  Serial.print(msg_3);
  Serial.println(Green_Intensity);
  while(Serial.available() > 0) {
    Serial.read();
  }

  while(Serial.available() == 0) {

  }
  Blue_Intensity = Serial.parseInt();
  Serial.print(msg_4);
  Serial.println(Blue_Intensity);
  while(Serial.available() > 0) {
    Serial.read();
  }

  analogWrite(Red_Pin, Red_Intensity);
  analogWrite(Green_Pin, Green_Intensity);
  analogWrite(Blue_Pin, Blue_Intensity);

}
