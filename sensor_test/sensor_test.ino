const int GND = 9;
const int VIN = 10;
const int SDL = 8;
const int SCA = 7;
const int XSHUT = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(GND, OUTPUT);
  pinMode(VIN, OUTPUT);
  
  pinMode(SDL, INPUT);
  pinMode(SCA, INPUT);
  
  digitalWrite(GND, LOW);
  digitalWrite(VIN, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(SCA));
  Serial.print("\n");
  delay(1000);
}
