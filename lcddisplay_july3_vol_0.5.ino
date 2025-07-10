#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  lcd.init();
  Serial.begin(9600);
  lcd.backlight();
}

void loop() {

  lcd.setCursor(2,0);
  lcd.print("Hello World!");
  delay(3000);
  lcd.clear();

  lcd.setCursor(2,0);
  lcd.print("This is LCD");
  lcd.setCursor(2,1);
  lcd.print("Screen test");
  delay(3000);
  lcd.clear();

}
