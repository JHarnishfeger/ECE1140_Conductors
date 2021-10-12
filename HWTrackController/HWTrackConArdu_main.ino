int blockNum;;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  buttonsSetup();
  joystickSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  Detection_TestUI();
  joystick();
  buttons(blockNum);

}
