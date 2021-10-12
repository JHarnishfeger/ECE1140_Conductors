#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#define joyX A0
#define joyY A1
#define sw  23
int xValue, yValue;
int jxValue = 0;
int jyValue = 0;

void joystickSetup()
{
  // put your setup code here, to run once:
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
  lcd.init();
  lcd.backlight();
}

void joystick()
{
  // put your main code here, to run repeatedly
  xValue = analogRead(joyX);
  //Serial.println(xValue);
  //yValue = analogRead(joyY);
  
  if(xValue < 90) jxValue--;
  if(xValue > 900) jxValue++;
  //if(yValue < 500) jyValue--;
  //if(yValue > 700) jyValue++;

  lcd.setCursor(0,0);
  lcd.print("  Block:  ");
   
  if(abs(jxValue)% 5 == 0)
  {
    
    lcd.setCursor(12,0);
    lcd.print("1    ");
    blockNum = 1;
    
  }
  else if(abs(jxValue)% 5 == 1)
  {
    
    lcd.setCursor(12,0);
    lcd.print("2    "); 
    blockNum = 2;
       
  }
  else if(abs(jxValue)% 5 == 2)
  {
    
    lcd.setCursor(12,0);
    lcd.print("3    ");   
    blockNum = 3;
    
  }
  else if(abs(jxValue)% 5 == 3)
  {
    
    lcd.setCursor(12,0);
    lcd.print("4    ");  
     blockNum = 4;
  }
  else if(abs(jxValue)% 5 == 4)
  {
    
    lcd.setCursor(12,0);
    lcd.print("5    ");  
    blockNum = 5;
     
  }
  delay(165);
}
