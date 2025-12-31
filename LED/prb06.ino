void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Enter a 3-Digit integer: ");
  while (Serial.available() == 0) {}
  int a = Serial.parseInt();

  int A3 = (a / 100);
  int A2 = (a / 10) % 10;
  int A1 = (a % 10);

  if (A3 > A1) {
    for (int i = 0; i < A2; i++) {
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(6, LOW);
      delay(500);
    }
    digitalWrite(3, LOW);
  }

  else if (A3 < A1) {
    for (int i = 0; i < A2; i++) {
      digitalWrite(3, HIGH);
      delay(500);
      digitalWrite(3, LOW);
      delay(500);
    }
    digitalWrite(6, LOW);

  }

  else if (A3 == A1) {

    digitalWrite(6, LOW);

    digitalWrite(3, LOW);
  }
}
