#include <Keypad.h>
int numdes[2];
int numbin[2];
const int ROW_NUM = 4;
const int COLUMN_NUM = 4;
char keys[ROW_NUM][COLUMN_NUM] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
byte pin_rows[ROW_NUM] = { 9, 8, 7, 6 };
byte pin_column[COLUMN_NUM] = { 5, 4, 3, 2 };
Keypad mykeypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("\nNumber 1: ");
  int num1 = mykeypad.waitForKey() - '0';
  Serial.println(num1);
  Serial.print("Logical Operation: ");
  char oper = mykeypad.waitForKey();
  Serial.println(oper);
  Serial.print("Number 2: ");
  int num2 = mykeypad.waitForKey() - '0';
  Serial.println(num2);
  int result = gateoper(num1, oper, num2);
  Serial.print("Result: ");
  Serial.println(result);
}
int gateoper(int a, char op, int b) {
  numdes[0] = a;
  numdes[1] = b;
  int res = 0;
  for (int i = 0; i < 2; i++) {
    if (numdes[i] == 0) {
      numbin[i] = 0b0000;
    } else if (numdes[i] == 1) {
      numbin[i] = 0b0001;
    } else if (numdes[i] == 2) {
      numbin[i] = 0b0010;
    } else if (numdes[i] == 3) {
      numbin[i] = 0b0011;
    } else if (numdes[i] == 4) {
      numbin[i] = 0b0100;
    } else if (numdes[i] == 5) {
      numbin[i] = 0b0101;
    } else if (numdes[i] == 6) {
      numbin[i] = 0b0110;
    } else if (numdes[i] == 7) {
      numbin[i] = 0b0111;
    } else if (numdes[i] == 8) {
      numbin[i] = 0b1000;
    } else if (numdes[i] == 9) {
      numbin[i] = 0b1001;
    } else {
      Serial.println("Binary number is not available.");
    }
  }
  if (op == 'A') {
    res = numbin[0] & numbin[1];
  } else if (op == 'B') {
    res = numbin[0] | numbin[1];
  } else if (op == 'C') {
    res = !(numbin[0] | numbin[1]);
  } else if (op == 'D') {
    res = !(numbin[0] & numbin[1]);
  } else if (op == '*') {
    res = numbin[0] ^ numbin[1];
  } else {
    Serial.println("Invalid operation.");
  }
  return res;
}
