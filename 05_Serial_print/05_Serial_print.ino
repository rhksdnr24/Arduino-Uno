const int Pin_1 = A3;
const int Pin_2 = A4;
float V1 = 0;
float V2 = 0;
int readVal_1;
int readVal_2;
int delayTime = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(Pin_1, INPUT);
  pinMode(Pin_2, INPUT);  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal_1 = analogRead(Pin_1);
  V1 = (5. / 1023.) * readVal_1; 
  Serial.print("first V : ");
  Serial.println(V1);
  readVal_2 = analogRead(Pin_2);
  V2 = (5. / 1023.) * readVal_2; 
  Serial.print("second V : ");
  Serial.println(V2);
  delay(delayTime);
}