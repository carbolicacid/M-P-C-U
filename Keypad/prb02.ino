#include <Keypad.h>
const int ROW_NUM = 4;
const int COLUMN_NUM = 4;
char keys[ROW_NUM][COLUMN_NUM] = {
  { '1', '2', '3', '+' },
  { '4', '5', '6', '-' },
  { '7', '8', '9', '*' },
  { '^', '0', '%', '/' }
};
byte pin_rows[ROW_NUM] = { 9, 8, 7, 6 };
byte pin_column[COLUMN_NUM] = { 5, 4, 3, 2 };
Keypad mykeypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM,
                         COLUMN_NUM);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("\nEnter first number: ");
  int x = mykeypad.waitForKey() - '0';
  Serial.println(x);
  Serial.print("Enter second number: ");
  int y = mykeypad.waitForKey() - '0';
  Serial.println(y);
  Serial.print("Operation: ");
  char oper = mykeypad.waitForKey();
  Serial.println(oper);
  int result = calt(x, y, oper);
  Serial.print("Result: ");
  Serial.println(result);
  Serial.println("------------------------");
}
int calt(int a, int b, char op) {
  int result = 0;
  if (op == '+') {
    result = a + b;
  } else if (op == '-') {
    result = a - b;
  } else if (op == '*') {
    result = a * b;
  } else if (op == '/') {
    result = a / b;
  } else if (op == '%') {
    result = a % b;
  } else if (op == '^') {
    result = round(pow(a, b));
  } else {
    Serial.println("Invalid Operation");
  }
  return result;
}