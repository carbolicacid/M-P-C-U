int Pin[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
byte Code[16] = {
  0x3F,  // 0
  0x06,  // 1
  0x5B,  // 2
  0x4F,  // 3
  0x66,  // 4
  0x6D,  // 5
  0x7D,  // 6
  0x07,  // 7
  0x7F,  // 8
  0x6F,  // 9
  0x77,  // A
  0x7C,  // b
  0x39,  // C
  0x5E,  // d
  0x79,  // E
  0x71   // F
};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 8; i++) {
    pinMode(Pin[i], OUTPUT);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 16; i++) {
    displayDigit(Code[i]);
    delay(1000);
  }
}

void displayDigit(byte pattern) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(Pin[i], bitRead(pattern, i));
  }
}
