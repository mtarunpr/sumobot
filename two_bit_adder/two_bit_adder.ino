const int LED_PIN1 = 9;
const int LED_PIN2 = 10;
const int BUTTON_PIN1 = 14;
const int BUTTON_PIN2 = 15;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(BUTTON_PIN1, INPUT);
  pinMode(BUTTON_PIN2, INPUT);

  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
