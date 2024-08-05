const int D_T = 50;
const int Pin_Latch = 11;
const int Pin_Clock = 9;
const int Pin_Data = 12;

byte LEDs = 0x00;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Pin_Latch, OUTPUT);
  pinMode(Pin_Clock, OUTPUT);
  pinMode(Pin_Data, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 256; i++) 
  {
    LEDs = i;
    digitalWrite(Pin_Latch, LOW);
    shiftOut(Pin_Data, Pin_Clock, LSBFIRST, LEDs);
    digitalWrite(Pin_Latch, HIGH);
    delay(D_T);
  }
}