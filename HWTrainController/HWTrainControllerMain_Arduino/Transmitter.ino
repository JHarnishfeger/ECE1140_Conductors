 void TransmitData() {
   
   String outData = parity;
  
   /*String encoding
     char 0    = parity bit      (1)
     char 1    = left doors      (0 = closed, 1 = open)
     char 2    = right doors     (0 = closed, 1 = open)
     char 3    = interior lights (0 = off, 1 = on)
     char 4    = exterior lights (0 = off, 1 = on)
     char 5    = serviceBreak    (0 = off, 1 = on)
     char 6    = eBreak          (0 = off, 1 = on)         
     char 7    = passengerBreak  (0 = off, 1 = on)
     char 8    = mode            (0 = automatic, 1 = manual)
     char 9-end = commandedPower  
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
 
   
   if (digitalRead(serviceBreakPin) == HIGH) {
       if (serviceBreak == false) {
           serviceBreak = true;     
       } else {
           serviceBreak = false;
       }
   }
 
   if (digitalRead(eBreakPin) == HIGH) {
       if (eBreak == false) {
           eBreak = true;     
       } else {
           eBreak = false;
       }
   }
 
   if (digitalRead(passengerBreakPin) == HIGH) {
       passengerBreak = true;
   }
   else
   {
       passengerBreak = false;
   }
 
   if (digitalRead(modePin) == HIGH) {
       mode = true;
   }
   else
   {
       mode = false;
   }
 
   if(engineFailString == "1" || tcFailString == "1"){
     eBreak = true;
   }
 
   if(setBrake == true){
     serviceBreak = setBrake;
   }
 
   if(leftDoors) outData += "1";  //button 1
   else outData += "0";
 
   if(rightDoors) outData += "1";  //button 2
   else outData += "0";
 
   if(interiorLights) outData += "1";  //button 3
   else outData += "0";
 
   if(exteriorLights) outData += "1";  //button 4
   else outData += "0";
 
   if(serviceBreak) outData += "1";  //button 5
   else outData += "0";
 
   if(eBreak) outData += "1";  //button 6
   else outData += "0";
 
   if(passengerBreak) outData += "1";  //switch 1
   else outData += "0";
 
   if(mode) outData += "1";  //switch 2
   else outData += "0";
 
   //convert double to string
   commandedPowerString = String(commandedPower);
 
   //5 chars
   outData += commandedPowerString;
 
   Serial.println(outData);
   
   Serial.flush();
 }
