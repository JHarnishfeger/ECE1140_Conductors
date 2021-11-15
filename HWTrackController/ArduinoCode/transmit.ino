void transmitSetup() {
  // put your setup code here, to run once:
  outputData = "000"; //Block 00; switch side A; Railway Crossing: off
}

void transmit() {
  // put your main code here, to run repeatedly:
  outputData[0] = currBlock[0];
  //outputData[1] = currBlock[1];
  if(trackSide == 0){
    outputData[1] = '0';
  }else if(trackSide == 1){
    outputData[1] = '1';
  }
  if(railwayCrossing == 0){
    outputData[2] = '0';
  }else if(railwayCrossing == 1){
    outputData[2] = '1';
  }

  if(Serial.available()> 0){
  Serial.print(outputData);
  }
}
