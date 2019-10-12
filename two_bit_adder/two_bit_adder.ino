const int LED_PIN1 = 9;
const int LED_PIN2 = 10;
const int BUTTON_PIN1 = 14;
const int BUTTON_PIN2 = 15;

int state;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(BUTTON_PIN1, INPUT);
  pinMode(BUTTON_PIN2, INPUT);

  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);

  state = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(BUTTON_PIN2) == HIGH)
  {
    switch (state)
    {
      case 0:
        digitalWrite(LED_PIN1, LOW);
        digitalWrite(LED_PIN2, HIGH);
        state = 1;
        break;

      case 1:
        digitalWrite(LED_PIN1, HIGH);
        digitalWrite(LED_PIN2, LOW);
        state = 2;
        break;

      case 2:
        digitalWrite(LED_PIN1, HIGH);
        digitalWrite(LED_PIN2, HIGH);
        state = 3;
        break;
    }
    delay(200);
  }

  if (digitalRead(BUTTON_PIN1) == HIGH)
  {
    switch (state)
    {
      case 1:
        digitalWrite(LED_PIN1, LOW);
        digitalWrite(LED_PIN2, LOW);
        state = 0;
        break;

      case 2:
        digitalWrite(LED_PIN1, LOW);
        digitalWrite(LED_PIN2, HIGH);
        state = 1;
        break;

      case 3:
        digitalWrite(LED_PIN1, HIGH);
        digitalWrite(LED_PIN2, LOW);
        state = 2;
        break;
    }
    delay(200);
  }

}
