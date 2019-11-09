const int LMOTOR1 = 9;
const int LMOTOR2 = 10;
const int RMOTOR1 = 11;
const int RMOTOR2 = 12;

const int LTOF = 6;
const int MTOF = 7;
const int RTOF = 8;

const int LREF = 2;
const int FREF = 3;
const int RREF = 4;
const int BREF = 5;

bool leftHigh = true;

void charge() {
  analogWrite(LMOTOR1, 128);
  analogWrite(LMOTOR2, 0);
  analogWrite(RMOTOR1, 128);
  analogWrite(RMOTOR2, 0);
}

void lTurn() {
  analogWrite(LMOTOR1, 80);
  analogWrite(LMOTOR2, 0);
  analogWrite(RMOTOR1, 0);
  analogWrite(RMOTOR2, 80);
}

void rTurn() {
  analogWrite(LMOTOR1, 0);
  analogWrite(LMOTOR2, 80);
  analogWrite(RMOTOR1, 80);
  analogWrite(RMOTOR2, 0);
}

void fwd() {
  analogWrite(LMOTOR1, 80);
  analogWrite(LMOTOR2, 0);
  analogWrite(RMOTOR1, 80);
  analogWrite(RMOTOR2, 0);
}

void backUp() {
  analogWrite(LMOTOR1, 0);
  analogWrite(LMOTOR2, 80);
  analogWrite(RMOTOR1, 0);
  analogWrite(RMOTOR2, 80);
}

void setup() {
  pinMode(LMOTOR1, OUTPUT);
  pinMode(LMOTOR2, OUTPUT);
  pinMode(RMOTOR1, OUTPUT);
  pinMode(RMOTOR2, OUTPUT);

  pinMode(LTOF, INPUT);
  pinMode(MTOF, INPUT);
  pinMode(RTOF, INPUT);

  pinMode(LREF, INPUT);
  pinMode(MREF, INPUT);
  pinMode(RREF, INPUT);
  pinMode(BREF, INPUT);
}


void loop() {
  int distL = digitalRead(LTOF);
  int distM = digitalRead(MTOF);
  int distR = digitalRead(RTOF);

  int refF = digitalRead(LREF);
  int refB = digitalRead(BREF);

  if (distL == LOW && distM == HIGH && distR == LOW)
  {
    charge();
  }
  else if (distL == HIGH && distR == LOW)
  {
    lTurn();
    leftHigh = true;
  }
  else if (distL == LOW && distR == HIGH)
  {
    rTurn();
    leftHigh = false;
  }
  else if (distL == LOW && distM == LOW && distR == LOW)
  {
    if (leftHigh)
    {
      lTurn();
    }
    else
    {
      rTurn();
    }
  }

  if (refF == HIGH)
  {
    backUp();
    delay(1000);
  }
  else if (refB == HIGH)
  {
    fwd();
    delay(1000);
  }
}
