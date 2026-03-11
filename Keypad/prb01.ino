#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
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
  lcd.init();
  lcd.backlight();
  lcd.clear();
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("\nNumber of digit: ");
  int n = mykeypad.waitForKey() - '0';
  Serial.println(n);
  Serial.print("Input: ");
  int keyval = 0;
  int value = 0;
  for (int i = 1; i <= n; i++) {
    keyval = mykeypad.waitForKey() - '0';
    Serial.print(keyval);
    value = value * 10 + keyval;
  }
  lcd.clear();
  if ((value % 2) == 0) {
    lcd.setCursor(0, 0);
    lcd.print("Result: EVEN");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Result: ODD");
  }
}