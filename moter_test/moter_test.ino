                                                                                                                                                                                                                                                                                 int L = 10;
const int R = 11;

void setup()
{
  pinMode(L, OUTPUT);
  pinMode(R, OUTPUT);
}

void loop()
{
  analogWrite(L, 200);
  analogWrite(R, 0);
}
