#include <Wire.h>
#include <LiquidCrystal_I2C_Hangul.h>
LiquidCrystal_I2C_Hangul lcd(0x3F, 16, 2);
void setup()
{
  // put your setup code here, to run once:
  Wire .begin ();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4, 1);
  lcd.print("WELCOME");
}

void loop() 
{
  // put your main code here, to run repeatedly:

}
