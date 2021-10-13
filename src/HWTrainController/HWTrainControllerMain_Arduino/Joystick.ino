#define joyX A0
#define joyY A1
#define sw  23
int xValue, yValue;
int jxValue = 0;
int jyValue = 0;

String Kp = "";
String Ki = "";
String authority = "";
String commandedSpeed = "";
String setpointSpeed = "";
String currentSpeed = "";
String stationName = "";
String stationCode = "";
bool stationUpcoming;

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

  if(abs(jxValue)% 5 == 0)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Current Speed: ");
    lcd.setCursor(0,1);
    lcd.print(currentSpeed + "mph");
    lcd.setCursor(0,2);
    lcd.print("Setpoint Speed:");
    lcd.setCursor(0,3);
    lcd.print(setpointSpeed + " mi/hr");
  }
  else if(abs(jxValue)% 5 == 1)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Kp: " + Kp + " W/(m/s)");
    lcd.setCursor(0,1);
    lcd.print("Ki: " + Ki + " W/m"); 
  }
  else if(abs(jxValue)% 5 == 2)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Commanded Speed: ");
    lcd.setCursor(0,1);
    lcd.print(commandedSpeed + " mi/hr");
    lcd.setCursor(0,2);
    lcd.print("Authority: ");
    lcd.setCursor(0,3);
    lcd.print(authority + " blocks");   
  }
    else if(abs(jxValue) % 5 == 3)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Arriving at Station: ");
    lcd.setCursor(0,1);
    lcd.print(stationName);
    
  }
  //delay(150);
}
