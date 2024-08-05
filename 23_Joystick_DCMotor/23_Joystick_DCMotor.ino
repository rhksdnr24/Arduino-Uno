const int Pin_Speed = 5;
const int dir1 = 4;
const int dir2 = 3;
const int XPin = A3;
const int YPin = A4;
const int SPin = 2;
int intensity;
int Vx;
int Vy;
int Vs;

int mSpeed = 255;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // pinMode(Pin_Tilt, INPUT);
  pinMode(Pin_Speed, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(XPin, INPUT);
  pinMode(YPin, INPUT);
  pinMode(SPin, INPUT);
  digitalWrite(SPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  Vx = analogRead(XPin);
  Vy = analogRead(YPin);
  Vs = digitalRead(SPin);
  
  Serial.print("X : ");
  Serial.print(Vx);
  Serial.print(" Y : ");
  Serial.print(Vy);
  Serial.print(" S : ");
  Serial.println(Vs);
  
  // 뒤로밀면 시계방향
  intensity = abs(Vy - 513);
  Serial.print(" I : ");
  Serial.println(intensity/2);
  if (Vy < 513) {
    digitalWrite(dir2, HIGH);
    digitalWrite(dir1, LOW);
    analogWrite(Pin_Speed, intensity / 2 - 1);
  }
  else if (Vy > 512) {
    digitalWrite(dir2, LOW);
    digitalWrite(dir1, HIGH);
    analogWrite(Pin_Speed, intensity / 2 - 1);
  }
  else {
    analogWrite(Pin_Speed, 0);
  }
}
