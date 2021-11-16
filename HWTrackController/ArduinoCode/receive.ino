#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

void receiveSetup() {
  lcd.init();
  lcd.backlight();

}

void receive() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(1,1);
  lcd.print("  Block:  ");
  lcd.setCursor(12,1);
  if(Serial.available() > 0){
    String info;
    info = Serial.readStringUntil('\n');

    if(info >= "0" && info <= "9"){
      lcd.print(info);
      //Serial.println(info);
      currBlock = info;
      Serial.println(currBlock);
    }
  }

}
