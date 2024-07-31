const float pi = 3.14;
int radius;
const String msg_1 = "How much length of your circle?";
const String msg_2 = "radius of circle's area is : ";
float area;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg_1);

  while(Serial.available() == 0) {

  }
  radius = Serial.parseInt();

  while(Serial.available() > 0) {
    Serial.read();
  }

  area = radius * radius * pi;

  Serial.print(radius);
  Serial.print(msg_2);
  Serial.println(area);
}
