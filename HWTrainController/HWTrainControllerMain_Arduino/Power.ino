void calculatePower()
{
  if(serviceBreak || eBreak || passengerBreak || authority <= 0)
  {
//    Serial.println("In here");
//    Serial.println(serviceBreak);
//    Serial.println(eBreak);
//    Serial.println(passengerBreak);
//    Serial.println(authority);
    commandedPower = 0;
  }
  else
  {
    //if in automatic mode, use currentSpeed, if in manual use suggestedSpeed
    if(mode && (currentSpeed < speedLimit))
    {
//      Serial.println("if");
//      Serial.println(mode);
//      Serial.println(currentSpeed);
//      Serial.println(speedLimit);
      ek = suggestedSpeed - currentSpeed;
    }
    else if(!mode && (currentSpeed < speedLimit))
    {
//      Serial.println("else if");
//      Serial.println(mode);
//      Serial.println(currentSpeed);
//      Serial.println(speedLimit);
//      Serial.println(commandedSpeed);
      ek = commandedSpeed - currentSpeed;
    }
    else
    {
//      Serial.println("else");
//      Serial.println(mode);
//      Serial.println(currentSpeed);
//      Serial.println(speedLimit);
      ek = speedLimit - currentSpeed;
    }

    //Calculates uk and sets current error to previous error
    uk = uk1 + (T/2) * (ek-ek1);
    ek1 = ek;

    //Calculates power
    commandedPower = Kp * ek + Ki * uk;

  }

  //Serial.println(commandedPower);
  
}
