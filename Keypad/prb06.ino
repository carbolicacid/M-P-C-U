#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#define LED1 10
#define LED2 11
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int ROW_NUM = 4;
const int COLUMN_NUM = 4;
char keys[ROW_NUM][COLUMN_NUM] = {
  { '1', '2', '3', 'A' }, { '4', '5', '6', 'B' }, { '7', '8', '9', 'C' }, { '*', '0', '#', 'D' }
};
byte pin_rows[ROW_NUM] = { 9, 8, 7, 6 };
byte pin_column[COLUMN_NUM] = { 5, 4, 3, 2 };
Keypad mykeypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM,
                         COLUMN_NUM);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  randomSeed(analogRead(A0));
}
void loop() {
  // put your main code here, to run repeatedly:
  int x = random(100);
  int k = 0;
  Serial.print("\nRandom Number: ");
  Serial.println(x);
  Serial.print("Number of Allowed Guesses: ");
  while (Serial.available() == 0) {}
  int n = Serial.parseInt();
  Serial.println(n);
  digitalWrite(LED1, 0);
  digitalWrite(LED2, 0);
  lcd.clear();
  for (int i = 1; i <= n; i++) {
    int keynum = 0;
    int value = 0;
    for (int j = 0; j < 2; j++) {
      keynum = mykeypad.waitForKey() - '0';
      value = value * 10 + keynum;
    }
    lcd.clear();
    if (value == x) {
      lcd.setCursor(0, 0);
      lcd.print("Guess ");
      lcd.print(i);
      lcd.print(": ");
      lcd.print(value);
      lcd.setCursor(0, 1);
      lcd.print("Correct");
      digitalWrite(LED1, 1);
      digitalWrite(LED2, 0);
      break;
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Guess ");
      lcd.print(i);
      lcd.print(": ");
      lcd.print(value);
      lcd.setCursor(0, 1);
      lcd.print("Wrong !");
      k++;
    }
  }
  if (k == n) {
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 1);
  }
}