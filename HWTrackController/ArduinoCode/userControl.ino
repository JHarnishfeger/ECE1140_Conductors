
static int updateButton = 32;
int ifUpdate; //Switch and crossing states will be updated when ifUpdate = 1


static int switchButton = 30;
static int railwayCrosiingButton = 40;

int switchState = 0;
int crossingState = 0;

void userControlSetup() {
  // put your setup code here, to run once:
  pinMode(updateButton, INPUT);
  pinMode(switchButton, INPUT);
  pinMode(railwayCrosiingButton, INPUT);
}

void userControl() {
  // put your main code here, to run repeatedly:
  //update?
  ifUpdate = 0;
  ifUpdate = digitalRead(updateButton);
  if(ifUpdate != 0){
    ifUpdate = digitalRead(updateButton);


  //Reading buttons' states:
  switchState = digitalRead(switchButton);
  crossingState = digitalRead(railwayCrosiingButton);

  //Printing to serial:
  if(switchState==HIGH){
    trackSide = 1;
  }else if(switchState==LOW){
    trackSide = 0;
  }
  if(crossingState==HIGH){
    railwayCrossing = 1;
  }else if(crossingState==LOW){
    railwayCrossing = 0;
  }

  if(switchState==HIGH){
    trackSide = 1;
  }else if(switchState==LOW){
    trackSide = 0;
  }

  if(crossingState==HIGH){
    railwayCrossing = 1;
  }else if(crossingState==LOW){
    railwayCrossing = 0;
  }
  transmit();
  }

}
