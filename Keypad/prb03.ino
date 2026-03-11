#include <Keypad.h>
#define LED1 10
#define LED2 11
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
Keypad mykeypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM,
                         COLUMN_NUM);
void setup() {  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("\nActual Password: ");
  while (Serial.available() == 0) {}
  int AP = Serial.parseInt();
  Serial.println(AP);
  Serial.print("Input Password: ");
  int keynum = 0;
  int value = 0;
  for (int i = 0; i < 4; i++) {
    keynum = mykeypad.waitForKey() - '0';
    Serial.print(keynum);
    value = value * 10 + keynum;
  }
  if (AP == value) {
    digitalWrite(LED1, 1);
    digitalWrite(LED2, 0);
  } else {
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 1);
  }
}