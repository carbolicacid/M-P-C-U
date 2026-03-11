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
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("\nMulti-Digit Input: ");
  while (Serial.available() == 0) {}
  int n = Serial.parseInt();
  Serial.println(n);
  Serial.print("Single Digit Inputs:");
  int keynum[4];
  for (int i = 0; i < 4; i++) {
    keynum[i] = mykeypad.waitForKey() - '0';
    Serial.print(" ");
    Serial.print(keynum[i]);
  }
  int m = 0;
  for (int i = 0; i < 4; i++) {
    if (n % keynum[i] == 0) {
      m++;
    }
  }
  if (m == 2) {
    digitalWrite(LED1, 1);
    digitalWrite(LED2, 0);
  } else if (m == 1) {
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 1);
  } else if (m == 4) {
    int t = 1;
    while (t <= 5) {
      digitalWrite(LED1, 1);
      digitalWrite(LED2, 1);
      delay(800);
      digitalWrite(LED1, 0);
      digitalWrite(LED2, 0);
      delay(800);
      t++;
    }
  } else if (m == 3) {
    Serial.println("\n3 factors are present.");
    Serial.println("No condition is given for 3 factors.");
    Serial.println("Hence both the LEDs are off.");
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
  } else {
    Serial.println("\nNo factors are present.");
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
  }
}