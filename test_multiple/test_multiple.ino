#include <i2c_t3.h>
#include <VL53L0X.h>

VL53L0X sensorL;
VL53L0X sensorM;
VL53L0X sensorR;

void setup()
{
  while(!Serial);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  delay(500);
  Wire.begin();


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

}

void loop()
{
/*  Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;

  for (byte i = 1; i < 120; i++)
  {
    Wire.beginTransmission(i);
    if (Wire.endTransmission() == 0)
    {
      Serial.print("Found address: ");
      Serial.print(i, DEC);
      Serial.print(" (0x");
      Serial.print(i, HEX);
      Serial.println(")");
      count++;
      
      delay (1);
    } 
  }
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");

  delay(3000);
  */

  Serial.print(sensorL.readRangeSingleMillimeters());
  if (sensorL.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  Serial.print(", ");
  Serial.print(sensorM.readRangeSingleMillimeters());
  if (sensorM.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  Serial.print(", ");
  Serial.print(sensorR.readRangeSingleMillimeters());
  if (sensorR.timeoutOccurred()) { Serial.print(" TIMEOUT"); }

  Serial.println();
}
