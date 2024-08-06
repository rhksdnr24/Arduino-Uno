const int Pin_Trig = 12;
const int Pin_Echo = 11;
const String msg_1 = "Time : ";
const String msg_2 = " Distance : ";

int pingTravelTime;
void setup() {
  // put your setup code here, to run once:
  pinMode(Pin_Trig, OUTPUT);
  pinMode(Pin_Echo, INPUT);
  Serial.begin(9600);
}

// float S2D(int time) {
//   return time * (0.0343 / 2);
// }

float S2D(int time) {
  return time * (0.013464);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Pin_Trig, LOW);
  delayMicroseconds(10);
  digitalWrite(Pin_Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Pin_Trig, LOW);
  pingTravelTime = pulseIn(Pin_Echo, HIGH);
  delay(25);
  Serial.print(0);
  Serial.print(",");
  Serial.print(S2D(pingTravelTime));
  Serial.print(",");
  Serial.println(10);
}