const int RED = 10;
const int GREEN = 7;
const int BLUE = 4;

void setup(){
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  BLINK(RED, 5);
  delay(100);
  BLINK(GREEN, 10);
  delay(100);
  BLINK(BLUE, 15);
  delay(100);
}

void BLINK(int COLOR, int Numbers){
  for(int i = 0; i < Numbers; i++){
    digitalWrite(COLOR, HIGH);
    delay(50);
    digitalWrite(COLOR, LOW);
    delay(50);
  }
}