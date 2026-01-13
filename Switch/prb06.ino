int button1 = 2;
int button2 = 3;
int button3 = 4;
int ledPin  = 13;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int b1 = digitalRead(button1);
  int b2 = !digitalRead(button2);
  int b3 = !digitalRead(button3);

  digitalWrite(ledPin, (b1 + b2 + b3) % 2 == 1);
  delay(50);
}
