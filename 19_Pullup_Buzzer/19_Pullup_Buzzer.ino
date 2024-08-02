const String msg_1 = "1st state : ";
const String msg_2 = "2nd state : ";
const int Pin_Out = 3;
const int Pin_In_1 = A0;
const int Pin_In_2 = A1;
const int D_T = 100;
const int Pin_Buzz = 2;

int readVal_1;
int readVal_2;
int Intensity = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Pin_In_1, INPUT);
  pinMode(Pin_In_2, INPUT);
  pinMode(Pin_Out, OUTPUT);
  pinMode(Pin_Buzz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal_1 = digitalRead(Pin_In_1);
  readVal_2 = digitalRead(Pin_In_2);

  Serial.print(msg_1);
  Serial.println(readVal_1);
  Serial.print(msg_2);
  Serial.println(readVal_2);

  if (readVal_1 == 0) {
    if (Intensity >= 0 && Intensity < 255)
    Intensity += 1;
    else {
      digitalWrite(Pin_Buzz, HIGH);
      delayMicroseconds(1000);
      digitalWrite(Pin_Buzz, LOW);
      delayMicroseconds(1000);
    }
  }
  if (readVal_2 == 0) {
    if (Intensity > 0 && Intensity <= 255)
    Intensity -= 1;
    else {
      digitalWrite(Pin_Buzz, HIGH);
      delayMicroseconds(1000);
      digitalWrite(Pin_Buzz, LOW);
      delayMicroseconds(1000);
    }
  }

  analogWrite(Pin_Out, Intensity);
  Serial.print("Intensity : ");
  Serial.println(Intensity);
  
  delay(D_T);
}
