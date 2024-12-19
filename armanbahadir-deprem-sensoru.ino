// C++ code
//
int E_C4_9Fim_Sens_C3_B6r_C3_BC = 0;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  digitalWrite(2, HIGH);
  if (digitalRead(2) == 1) {
    tone(13, 123, 999999999000); // play tone 35 (B2 = 123 Hz)
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
  } else {
    noTone(13);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}