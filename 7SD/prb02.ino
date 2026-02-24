int Pin[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
int n, p;
byte Code[] = {
  0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
  0x7F, 0x6F, 0x77, 0x7C,
  0x39, 0x5E, 0x79, 0x71
};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(Pin[i], OUTPUT);
  }
  pinMode(10, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("\nEnter the number: ");
  while (Serial.available() == 0) {}
  n = Serial.parseInt();
  Serial.println(n);
  p = n;
  int i = 2;
  while (p <= 15) {
    digitalWrite(10, 0);
    displayDigit(Code[p]);
    p = n * i;
    i++;
    delay(1000);
  }
  digitalWrite(10, 1);
}
void displayDigit(byte pattern) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(Pin[i], bitRead(pattern, i));
  }
}