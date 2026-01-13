#define A 6
#define B 5
#define C 4
#define LED 12

void setup() {
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int a = digitalRead(A);
  int b = digitalRead(B);
  int c = digitalRead(C);

  if ((a == 0 && b == 0 && c == 0) || (a == 0 && b == 1 && c == 0) || (a == 1 && b == 1 && c == 0) || (a == 1 && b == 1 && c == 1)) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
