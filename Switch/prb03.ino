#define SW1 10
#define SW2 11
#define SW3 12
#define LED 13

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  int sum = digitalRead(SW1) + digitalRead(SW2) + digitalRead(SW3);
  digitalWrite(LED, sum >= 2); // logical operator turns it 0 or 1
}
