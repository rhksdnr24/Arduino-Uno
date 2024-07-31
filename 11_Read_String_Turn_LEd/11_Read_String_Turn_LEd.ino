String Color;
const String msg = "What color do you want to turn on? ";
const int Red_Pin = 2;
const int Green_Pin = 3;
const int Blue_Pin = 4;
const int Time_Delay = 250;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Red_Pin, OUTPUT);
  pinMode(Green_Pin, OUTPUT);
  pinMode(Blue_Pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  digitalWrite(Red_Pin, LOW);
  digitalWrite(Green_Pin, LOW);
  digitalWrite(Blue_Pin, LOW);
  while(Serial.available() == 0) {

  }

  Color = Serial.readString();
  Color.trim();

  if(Color == "Red") {
    digitalWrite(Red_Pin, HIGH);
    delay(Time_Delay);
  }

  else if(Color == "Green") {
    digitalWrite(Green_Pin, HIGH);
    delay(Time_Delay);
  }

  else if(Color == "Blue") {
    digitalWrite(Blue_Pin, HIGH);
    delay(Time_Delay);
  }
}
