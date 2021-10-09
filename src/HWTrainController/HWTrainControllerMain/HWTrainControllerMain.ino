#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();

  joystickSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  joystick();
  delay(500);
}
