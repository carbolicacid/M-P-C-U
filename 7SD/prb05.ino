void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  int Pin[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
  int A, B, n;
  byte cc[] = { 0x6E, 0x54 };
  void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    for (int i = 0; i < 8; i++) {
      pinMode(Pin[i], OUTPUT);
    }
  }
  void loop() {
    // put your main code here, to run repeatedly:Serial.print("\nEnter the 1st value: ");
    while (Serial.available() == 0) {}
    A = Serial.parseInt();
    Serial.println(A);
    Serial.print("\nEnter the 2nd value: ");
    while (Serial.available() == 0) {}
    B = Serial.parseInt();
    Serial.println(B);
    n = A % B;
    if (n == 0) {
      displayDigit(cc[0]);
    } else {
      displayDigit(cc[1]);
    }
  }
  void displayDigit(byte pattern) {
    for (int i = 0; i < 8; i++) {
      digitalWrite(Pin[i], bitRead(pattern, i));
    }
  }
}
