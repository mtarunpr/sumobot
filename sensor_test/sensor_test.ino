const int GND = 9;
const int VCC = 8;
const int L = 7;
const int M = 6;
const int R = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(GND, OUTPUT);
  pinMode(VCC, OUTPUT);
  pinMode(L, INPUT);
  pinMode(M, INPUT);
  pinMode(R, INPUT);
  
  digitalWrite(GND, LOW);
  digitalWrite(VCC, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(digitalRead(L));
  Serial.print("\n");
  delay(1000);
}
