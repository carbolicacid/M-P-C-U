int Pin[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
int seg[] = { A0, A1, A2, A3 };
byte Code[] = {
  0x3F, 0x06, 0x5B, 0x4F,
  0x66, 0x6D, 0x7D, 0x07,
  0x7F, 0x6F, 0x77, 0x7C,
  0x39, 0x5E, 0x79, 0x71
};
unsigned int x, temp;
byte num[4];
void setup() {
  // put your setup code here, to run once:for (int i = 0; i < 8; i++) {
  pinMode(Pin[i], OUTPUT);
}
for (int i = 0; i < 4; i++) {
  pinMode(seg[i], OUTPUT);
}
}
void loop() {
  // put your main code here, to run repeatedly:
  x = 0x5A8F;
  temp = x;
  for (int i = 0; i < 4; i++) {
    num[3 - i] = temp % 16;
    temp = temp / 16;
  }
  for (int d = 0; d < 4; d++) {
    displayNum(d, Code[num[d]]);
  }
}
void displayNum(int digit, byte pattern) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(seg[i], 1);
  }
  for (int i = 0; i < 8; i++) {
    digitalWrite(Pin[i], bitRead(pattern, i));
  }
  digitalWrite(seg[digit], 0);
  delay(3);
}