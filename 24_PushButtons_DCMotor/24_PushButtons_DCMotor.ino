const String msg_1 = "Your intensity is : ";
const int Pin_Pull_0 = A0;
const int Pin_Pull_1 = A1;

const int Pin_Speed = 5;
const int Pin_dir1 = 4;
const int Pin_dir2 = 3;

int readVal_0;
int readVal_1;
int intensity = 0;
const int D_T = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Pin_Pull_0, INPUT);
  pinMode(Pin_Pull_1, INPUT);
  pinMode(Pin_Speed, OUTPUT);
  pinMode(Pin_dir1, OUTPUT);
  pinMode(Pin_dir2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal_0 = digitalRead(Pin_Pull_0);
  readVal_1 = digitalRead(Pin_Pull_1);

  if(intensity >= -255 && intensity < 255) { 
    if (readVal_0 == 0) {
      intensity += 1;
    }
  }
  if(intensity > -255 && intensity <= 255) { 
    if (readVal_1 == 0) {
      intensity -= 1;    
    }
  }


  // 반시계방향으로
  if(intensity > 0) {
    digitalWrite(Pin_dir1, HIGH);
    digitalWrite(Pin_dir2, LOW);
    analogWrite(Pin_Speed, intensity);
  }
  // 시계방향으로
  else {
    digitalWrite(Pin_dir1, LOW);
    digitalWrite(Pin_dir2, HIGH);
    analogWrite(Pin_Speed, (-1) * (intensity));
  }

  Serial.print(msg_1);
  Serial.println(intensity);

  delay(D_T);
}
