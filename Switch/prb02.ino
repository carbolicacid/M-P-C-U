#define PB1 8
#define PB2 9

#define LED1 4
#define LED2 5
#define LED3 6
#define LED4 7

void setup() {
  pinMode(PB1, INPUT_PULLUP);
  pinMode(PB2, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  int a = digitalRead(PB1);
  int b = digitalRead(PB2);

  if (!a && b) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED4, LOW);
  }
  else if (!a && !b) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }
  else if (a && b) {
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED4, LOW);
  }
  else {
    digitalWrite(LED2, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED3, LOW);
  }
}

