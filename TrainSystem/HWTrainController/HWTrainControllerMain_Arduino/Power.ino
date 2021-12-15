void calculatePower(){
  
  double avgPower;
  double power;
  
  double power_redun;
  double ek_redun = 0;
  double ek1_redun = ek1;
  double uk_redun = 0;
  double uk1_redun = uk1;

  //first power check
  if(serviceBreak || eBreak || passengerBreak || breakFailString == "1" || authority <= 0){
    power = 0;
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
    power = Kp * ek + Ki * uk;

    if(power > 120000){
      power = 120000;
    }
  }

  //second power check (redundancy)
  if(serviceBreak || eBreak || passengerBreak || breakFailString == "1" || authority <= 0){
    power_redun = 0;
  }
  else{
    //if in automatic mode, use currentSpeed, if in manual use suggestedSpeed
    if(mode && (currentSpeed < speedLimit)){
      ek_redun = suggestedSpeed - currentSpeed;
    }
    else if(!mode && (currentSpeed < speedLimit)){
      ek_redun = commandedSpeed - currentSpeed;
    }
    else{
      ek_redun = speedLimit - currentSpeed;
    }

    //Calculates uk and sets current error to previous error
    uk_redun = uk1_redun + (T/2) * (ek-ek1);
    ek1_redun = ek_redun;

    //Calculates power
    power_redun = Kp * ek_redun + Ki * uk_redun;

    if(power_redun > 120000){
      power_redun = 120000;
    }
  }

  avgPower = (power + power_redun)/2;

//  if(mode&&authority > 0){
//    atStation();
//  }

  if(avgPower<0&&!brake4slow){
    brake4slow = 1;
    setBrake = true;
  }
  else{
    brake4slow = 0;
    setBrake = false;
  }
 }

  
  commandedPower = avgPower;

}
