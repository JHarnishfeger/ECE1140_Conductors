#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

//Reveiver and Joystick Variables
String receivedString;
String KpString = "0000";
String KiString = "0000";
String commandedSpeedString = "00.00";
String currentSpeedString = "00.00";
String suggestedSpeedString = "00.00";
String speedLimitString = "00.00";
String authorityString = "00.00";
String stationCode = "";
bool stationUpcoming = true;
String stationName = "";

//Power Variables
double commandedPower;
double Kp = 00.00;
double Ki = 00.00;
double commandedSpeed = 00.00;
double currentSpeed = 00.00;
double suggestedSpeed = 00.00;
double speedLimit = 00.00;
double authority = 99.99;
double T = 1;
double ek = 00.00;
double ek1 = 00.00;
double uk = 00.00;
double uk1 = 00.00;
double ek_SW = 00.00;
double ek1_SW = 00.00;
double uk_SW = 00.00;
double uk1_SW = 00.00;

//Pin Declarations
const int leftDoorsPin = 24;
const int rightDoorsPin = 26;
const int interiorLightsPin = 28;
const int exteriorLightsPin = 30;
const int serviceBreakPin = 32;
const int eBreakPin = 34;
const int passengerBreakPin = 36;
const int modePin = 38;

//Transmitter Variables
String parity = "1";
String commandedPowerString;
bool leftDoors = false;
bool rightDoors = false;
bool interiorLights = false;
bool exteriorLights = false;
bool serviceBreak = false;
bool eBreak = false;
bool passengerBreak = false;
bool mode = true;

void setup() {

  //Pin Initializations
  pinMode(leftDoorsPin, INPUT);
  pinMode(rightDoorsPin, INPUT);
  pinMode(interiorLightsPin, INPUT);
  pinMode(exteriorLightsPin, INPUT);
  pinMode(serviceBreakPin, INPUT);
  pinMode(eBreakPin, INPUT);
  pinMode(passengerBreakPin, INPUT);
  pinMode(modePin, INPUT);
  
  Serial.begin(9600);

  //Start the LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  joystickSetup();
}

void loop() {
  //put your main code here, to run repeatedly:
  joystick();
  ReceiveData();
  calculatePower();
  TransmitData();
  delay(100);
}
