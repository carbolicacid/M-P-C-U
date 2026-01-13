#define SW1 12
#define SW2 11
#define PB 10
#define LED 4

void setup() {
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(PB, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  int b1 = !digitalRead(PB);  // for pullup 
  int b2 = digitalRead(SW1);
  int b3 = digitalRead(SW2);

  int pressedCount = b1 + b2 + b3;

  digitalWrite(LED, pressedCount % 2 == 1); 
  delay(50);
}
