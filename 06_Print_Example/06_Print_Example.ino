String STR_1 = "반지름이 ";
String STR_2 = "인 원의 넓이는 ";
String STR_3 = "이다";
const float pi = 3.14;
float R = 0;
float area;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  area = R * R * pi;
  Serial.print(STR_1);
  Serial.print(R);
  Serial.print(STR_2);
  Serial.print(area);
  Serial.println(STR_3);
  R += 0.5;
  delay(500);
}
