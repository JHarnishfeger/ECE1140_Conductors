void calculatePower(){
  
  double commandedPower;
  double commandedPowerAVG = 0.0;
  double avgPower;

  for(int i = 0; i < 2; i++){
    
    if(serviceBreak || eBreak || passengerBreak || breakFail || authority <= 0){
      commandedPower = 0;
    }
    else{
      //if in automatic mode, use currentSpeed, if in manual use suggestedSpeed
      if(mode && (currentSpeed < speedLimit)){
        ek = suggestedSpeed - currentSpeed;
      }
      else if(!mode && (currentSpeed < speedLimit)){
        ek = commandedSpeed - currentSpeed;
      }
      else{
        ek = speedLimit - currentSpeed;
      }
  
      //Calculates uk and sets current error to previous error
      uk = uk1 + (T/2) * (ek-ek1);
      ek1 = ek;
  
      //Calculates power
      commandedPower = Kp * ek + Ki * uk;
  
      if(commandedPower > 120000){
        commandedPower = 120000;
      }

        commandedPowerAVG = commandedPowerAVG + commandedPower;
    }
  }

  avgPower = (commandedPowerAVG) / 2;

  commandedPower = avgPower;

  



}
