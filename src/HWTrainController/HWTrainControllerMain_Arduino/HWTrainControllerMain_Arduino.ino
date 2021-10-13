#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

String receivedString;
String powerIn = "12000";

const int leftDoorsPin = 24;
const int rightDoorsPin = 26;
const int interiorLightsPin = 28;
const int exteriorLightsPin = 30;
const int breakPin = 36;
const int eBreakPin = 25;
const int modePin = 32;

//String Kp = "";
//String Ki = "";
//String authority = "";
//String commandedSpeed = "";
//String setpointSpeed = "";
//String currentSpeed = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();


  pinMode(leftDoorsPin, INPUT);
  pinMode(rightDoorsPin, INPUT);
  pinMode(interiorLightsPin, INPUT);
  pinMode(exteriorLightsPin, INPUT);
  pinMode(breakPin, INPUT);
  pinMode(eBreakPin, INPUT);
  pinMode(modePin, INPUT);
  //configure();
  joystickSetup();
}

void loop() {
  //put your main code here, to run repeatedly:
  joystick();
  TransmitData();
  ReceiveData();
  delay(900);

  

}
