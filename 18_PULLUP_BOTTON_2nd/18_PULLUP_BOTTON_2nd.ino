const int Pin_Input = 12;
const int Pin_Output = 9;
const int D_T = 250;
int curVal;
int preVal = 1;
int intensity = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Pin_Input, INPUT);
  pinMode(Pin_Output, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  curVal = digitalRead(Pin_Input); // 

  // 이전과 변경이 없으면 계속 무한 루프 돈다

  if (curVal == 0 && preVal == 1){
    if (intensity == 0) {
      intensity = 255;
      analogWrite(Pin_Output, intensity);
    }
    else if(intensity == 255) {
      intensity = 0;
      analogWrite(Pin_Output, intensity);
    }
  }
  preVal = curVal;
  
  delay(D_T);
}