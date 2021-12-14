
String currBlock;
String outputData;

bool trackSide = 0; // 0 = Side A; 1 = Side B
bool railwayCrossing = 0; // 0 = inactivated; 1 = activated

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  userControlSetup();
  receiveSetup();
  transmitSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  receive();
  userControl();
}
