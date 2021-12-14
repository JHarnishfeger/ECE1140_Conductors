void calculatePower()
{
  double commandedPower1, commandedPower2;
  double commandedPower1AVG = 0.0;
  double commandedPower2AVG = 0.0;
  double avgPower;

  for(int i = 0; i < 3; i++)
  {
    if(serviceBreak || eBreak || passengerBreak || authority <= 0)
    {
      commandedPower1 = 0;
    }
    else
    {
      //if in automatic mode, use currentSpeed, if in manual use suggestedSpeed
      if(mode && (currentSpeed < speedLimit))
      {
        ek = suggestedSpeed - currentSpeed;
      }
      else if(!mode && (currentSpeed < speedLimit))
      {
        ek = commandedSpeed - currentSpeed;
      }
      else
      {
        ek = speedLimit - currentSpeed;
      }
  
      //Calculates uk and sets current error to previous error
      uk = uk1 + (T/2) * (ek-ek1);
      ek1 = ek;
  
      //Calculates power
      commandedPower1 = Kp * ek + Ki * uk;
  
      if(commandedPower1 > 120000)
      {
        commandedPower1 = 120000;
      }
//      Serial.print("CommandedPower1 ");
//      Serial.println(commandedPower1);

      commandedPower1AVG = commandedPower1AVG + commandedPower1;
    }
  
    //Cross Checking with SW power calculation
    if (serviceBreak || eBreak || passengerBreak || authority <= 0){ //If any brake is enables or no authority, power is cut
      commandedPower2 = 0;
    }else{
      //If in automatic mode, use commanded velocity, if in manual use setpoint velocity
      if (mode&&currentSpeed<speedLimit)
          ek_SW  = suggestedSpeed - currentSpeed;
      else if(!mode&&currentSpeed<speedLimit)
          ek_SW  = commandedSpeed - currentSpeed;
      else
          ek_SW  = speedLimit - currentSpeed;
  
      //Calculates uk and sets current error to previous error
      uk_SW = uk1_SW + (T / 2) * (ek_SW - ek1_SW);
      ek1_SW = ek_SW;
  
      //Calculates power
      commandedPower2 = Kp * ek_SW + Ki * uk_SW;
  
      //If power calculation exceeds max power, set power command to max power
      if(commandedPower2 > 120000)
          commandedPower2 = 120000;

//      Serial.print("CommandedPower2: ");
//      Serial.println(commandedPower2);

      commandedPower2AVG = commandedPower2AVG + commandedPower2;
      
    }
  }

  avgPower = (commandedPower1AVG + commandedPower2AVG) / 2;

  commandedPower = avgPower;

  



}
