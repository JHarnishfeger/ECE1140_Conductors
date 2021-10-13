String parity = "1";

bool leftDoors = false;
bool rightDoors = false;
bool interiorLights = false;
bool exteriorLights = false;
bool mode = false;
bool serviceBreak = false;

void TransmitData() {
  
  String outData = parity;
 
  /*String encoding
    char 0    = parity bit      (1)
    char 1    = left doors      (0 = closed, 1 = open)
    char 2    = right doors     (0 = closed, 1 = open)
    char 3    = interior lights (0 = off, 1 = on)
    char 4    = exterior lights (0 = off, 1 = on)
    char 5-9  = power
    char 10   = break           (0 = off, 1 = on)
    char 11   = emergency break (0 = off, 1 = on)
    char 12   = mode            (0 = automatic, 1 = manual)
  */
  if (digitalRead(leftDoorsPin) == HIGH) {
      if (leftDoors == false) {
          leftDoors = true;     
      } else {
          leftDoors = false;
      }
  }

  if (digitalRead(rightDoorsPin) == HIGH) {
      if (rightDoors == false) {
          rightDoors = true;     
      } else {
          rightDoors = false;
      }
  }

  if (digitalRead(interiorLightsPin) == HIGH) {
      if (interiorLights == false) {
          interiorLights = true;     
      } else {
          interiorLights = false;
      }
  }

  if (digitalRead(exteriorLightsPin) == HIGH) {
      if (exteriorLights == false) {
          exteriorLights = true;     
      } else {
          exteriorLights = false;
      }
  }

  if(leftDoors) outData += "1";
  else outData += "0";

  if(rightDoors) outData += "1";
  else outData += "0";

  if(interiorLights) outData += "1";
  else outData += "0";

  if(exteriorLights) outData += "1";
  else outData += "0";

  //5 chars
  outData += powerIn;

  if (digitalRead(breakPin) == HIGH) {
      if (serviceBreak == false) {
          serviceBreak = true;     
      } else {
          serviceBreak = false;
      }
  }
  if(serviceBreak) outData += "1";
  else outData += "0";

  if(digitalRead(eBreakPin) == HIGH) outData += "1";
  else outData += "0";    

  if (digitalRead(modePin) == HIGH) {
      if (mode == false) {
          mode = true;     
      } else {
          mode = false;
      }
  }

  if(mode) outData += "1";
  else outData += "0";

  Serial.println(outData);
  
  Serial.flush();
}
