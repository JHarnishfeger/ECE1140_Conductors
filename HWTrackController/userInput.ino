
static int updateButton = 32;
int ifUpdate; //Switch and crossing states will be updated when ifUpdate = 1


static int switchButton = 30;
static int railwayCrosiingButton = 40;

bool trackSide = 0; // 0 = Side A; 1 = Side B
bool railwayCrossing = 0; // 0 = inactivated; 1 = activated

int switchState = 0;
int crossingState = 0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(32, INPUT);
pinMode(switchButton, INPUT);
pinMode(railwayCrosiingButton, INPUT);
}

void loop() {
  //update?
  ifUpdate = 0;
  while(ifUpdate==0){
    ifUpdate = digitalRead(updateButton);
  }
   
  //Reading buttons' states:
  switchState = digitalRead(switchButton);
  crossingState = digitalRead(railwayCrosiingButton);

  //Printing to serial:
  if(switchState==HIGH){
    trackSide = 1;
    Serial.print(trackSide);
  }else if(switchState==LOW){
    trackSide = 0;
    Serial.print(trackSide);
  }
  if(crossingState==HIGH){
    railwayCrossing = 1;
    Serial.print(railwayCrossing);
  }else if(crossingState==LOW){
    railwayCrossing = 0;
    Serial.print(railwayCrossing);
  }

  Serial.print("  |  ");
  
  Serial.print("Track Switch: ");
  if(switchState==HIGH){
    trackSide = 1;
    Serial.print(trackSide);
    Serial.print(" -- Side B; ");
  }else if(switchState==LOW){
    trackSide = 0;
    Serial.print(trackSide);
    Serial.print(" -- Side A; ");
  }
  
  Serial.print("Railway Crossing: ");
  if(crossingState==HIGH){
    railwayCrossing = 1;
    Serial.print(railwayCrossing);
    Serial.println(" -- activated.");
  }else if(crossingState==LOW){
    railwayCrossing = 0;
    Serial.print(railwayCrossing);
    Serial.println(" -- inactivated.");
  }

  
  delay(100);

}
