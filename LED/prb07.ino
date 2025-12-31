int LED = 6;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

  int a, b, c;

  Serial.println("Enter number of blinks: ");
  while (Serial.available() == 0) {}
  a = Serial.parseInt();

  Serial.println("Enter ON time: ");
  while (Serial.available() == 0) {}
  b = Serial.parseInt();

  Serial.println("Enter duty cycle: ");
  while (Serial.available() == 0) {}
  c = Serial.parseInt();

  blinkLED(a, b, c);
}

void loop() {
}
void blinkLED(int a, int b, int c) {
  float onTime = b * (c / 100.0);
  float offTime = b - onTime;

  for (int i = 0; i < a; i++) {
    digitalWrite(LED, HIGH);
    delay(onTime * 1000);

    digitalWrite(LED, LOW);
    delay(offTime * 1000);
  }
}
