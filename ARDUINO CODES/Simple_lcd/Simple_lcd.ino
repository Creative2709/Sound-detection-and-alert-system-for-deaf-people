#include <Wire.h>
#include <LiquidCrystal_I2C.h>


const int I2C_ADDR = 0x27;
const int LCD_COLUMNS = 16;
const int LCD_ROWS = 2; 

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_ROWS);
void setup() {
Wire.begin();
lcd.init();
lcd.backlight();
lcd.print("Sound Alert for");
lcd.setCursor(0,1);
lcd.print("Deaf People...");

}

void loop() {
lcd.setCursor(0,1);

}
