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
}

void joystick()
{
  // put your main code here, to run repeatedly
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);
  
  if(xValue < 500) jxValue--;
  if(xValue > 700) jxValue++;
  if(yValue < 500) jyValue--;
  if(yValue > 700) jyValue++;

  if(abs(jxValue)% 3 == 0)
  {
    lcd.setCursor(0,0);
    lcd.print("  Train Controller  ");
    lcd.setCursor(0,2);
    lcd.print("     Home Menu      ");
  }
  else if(abs(jxValue)% 3 == 1)
  {
    lcd.setCursor(0,0);
    lcd.print("  Train Controller  ");
    lcd.setCursor(0,2);
    lcd.print("       Menu 2       ");    
  }
  else if(abs(jxValue)% 3 == 2)
  {
    lcd.setCursor(0,0);
    lcd.print("  Train Controller  ");
    lcd.setCursor(0,2);
    lcd.print("       Menu 3       ");    
  }
  //delay(150);
}
