void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}
#define pb 8
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  pinMode(pb, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}
void loop() {
  int buttonState = digitalRead(pb);
  if (buttonState == 0) {  // With INPUT_PULLUP: LOW =
    pressed
      lcd.clear();
    lcd.setCursor(3, 1);
    lcd.print("UNIVERSITY");
  } else {  // HIGH = not pressed
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("AHSANULLAH");
  }
  delay(500);
}
3.
#include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  lcd.clear();
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  Serial.print("\nGive integer LevelTerm: ");
  while (Serial.available() == 0) {}
  int inp = Serial.parseInt();
  Serial.println(inp);
  int level = inp / 10;
  int term = inp % 10;
  if (level <= 5 && level >= 1) {
    if (term == 1 || term == 2) {
      lcd.setCursor(0, 0);
      lcd.print("Level ");
      lcd.print(level);
      lcd.setCursor(0, 1);
      lcd.print("Term ");
      lcd.print(term);
    } else {
      lcd.setCursor(0, 0);
      lcd.print("INVALID INPUT");
    }
  } else {
    lcd.setCursor(0, 0);
    lcd.print("INVALID INPUT");
  }
}
void loop() {
}