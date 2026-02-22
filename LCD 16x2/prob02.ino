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