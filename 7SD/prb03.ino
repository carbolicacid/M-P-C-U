int Pin[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
int n, a;
byte cc[] = { 0x79, 0x3F };
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(Pin[i], OUTPUT);
  }
}
void loop() {
  // put your main code here, to run repeatedly:Serial.print("\nEnter a number: ");
  while (Serial.available() == 0) {}
  n = Serial.parseInt();
  Serial.println(n);
  a = n % 2;
  if (a == 0) {
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