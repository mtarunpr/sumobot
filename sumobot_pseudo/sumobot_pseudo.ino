#include <i2c_t3.h>
#include <VL53L0X.h>
#include <QTRSensors.h>

VL53L0X sensorL;
VL53L0X sensorM;
VL53L0X sensorR;

const int LMOTOR1 = 8;
const int LMOTOR2 = 9;
const int RMOTOR1 = 10;
const int RMOTOR2 = 11;

/*const int LREF = 2;
const int FREF = 3;
const int RREF = 4;
const int BREF = 5;*/

bool leftHigh = true;

QTRSensors qtr;

const uint8_t SensorCount = 2;
uint16_t sensorValues[SensorCount];

const int edgeTime = 500;
const int tofCutoff = 8000;
const int refCutoff = 1500;

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
  while(!Serial);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  delay(500);
  Wire.begin();
  
  qtr.setTypeRC();

  // 14 - FRONT, 15 - BACK
  qtr.setSensorPins((const uint8_t[]){14, 15}, SensorCount);
  qtr.setEmitterPin(2);

  Serial.begin (9600);

  digitalWrite(4, HIGH);
  delay(150);
  Serial.println("00");
  sensorL.init();
  Serial.println("01");
  delay(100);
  sensorL.setAddress((uint8_t)22);
  Serial.println("02");

  digitalWrite(5, HIGH);
  delay(150);
  sensorM.init();
  Serial.println("03");
  delay(100);
  sensorM.setAddress((uint8_t)25);
  Serial.println("04");

  digitalWrite(6, HIGH);
  delay(150);
  sensorR.init();
  Serial.println("04");
  delay(100);
  sensorR.setAddress((uint8_t)28);
  Serial.println("05");

  Serial.println("addresses set");
  
  pinMode(LMOTOR1, OUTPUT);
  pinMode(LMOTOR2, OUTPUT);
  pinMode(RMOTOR1, OUTPUT);
  pinMode(RMOTOR2, OUTPUT);

/*  pinMode(LREF, INPUT);
  pinMode(MREF, INPUT);
  pinMode(RREF, INPUT);
  pinMode(BREF, INPUT); */
}


void loop() {

  qtr.read(sensorValues);

  int distL = sensorL.readRangeSingleMillimeters();
  if (sensorL.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  int distM = Serial.print(sensorM.readRangeSingleMillimeters());
  if (sensorM.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  int distR = Serial.print(sensorR.readRangeSingleMillimeters());
  if (sensorR.timeoutOccurred()) { Serial.print(" TIMEOUT"); }

  Serial.println();

  // int refF = digitalRead(LREF);
  // int refB = digitalRead(BREF);

  if (distL >= tofCutoff && distM < tofCutoff && distR >= tofCutoff)
  {
    charge();
  }
  else if (distL < tofCutoff && distR >= tofCutoff)
  {
    lTurn();
    leftHigh = true;
  }
  else if (distL >= tofCutoff && distR < tofCutoff)
  {
    rTurn();
    leftHigh = false;
  }
  else if (distL >= tofCutoff && distM >= tofCutoff && distR >= tofCutoff)
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

  if (sensorValues[0] < refCutoff)
  {
    backUp();
    delay(edgeTime);
  }
  else if (sensorValues[1] < refCutoff)
  {
    fwd();
    delay(edgeTime);
  }
}
