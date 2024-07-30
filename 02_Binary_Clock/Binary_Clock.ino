const int pin1 = 2;
const int pin2 = 3;
const int pin3 = 4;
const int pin4 = 5;


void setup() {
  // put your setup code here, to run once:
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
pinMode(pin4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:


  for(int i = 0; i < 16; i++) {
    char * STR = toBinaryString(i);

    for (int j = 0; j < 4; j++) {
      if (STR[j] == '1') {
        digitalWrite(j + 2, HIGH);
      }
      else if(STR[j] == '0') {
        digitalWrite(j + 2, LOW);
      }
    }
    delay(100);      
  }

}


char* toBinaryString(int number) {
  // 정적 배열 사용 (32비트 + null 문자)
  static char binaryString[5];
  
  for (int i = 3; i >= 0; --i) {
    // 각 비트를 검사하여 1 또는 0 저장
    binaryString[3 - i] = (number & (1 << i)) ? '1' : '0';
  }
  binaryString[4] = '\0'; // 문자열 끝에 null 문자 추가
  
  return binaryString;
}