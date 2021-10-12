int trainDetected_railBroken = 0; // Will be a two-digit int; for each digit, 1 = false, 2 = true. Ex: 22 means both train and broken are detected.
//String type; // a = authority; s = speed.
//float num;

void Detection_TestUI() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    
    /*
    type = Serial.readString();
    
    if(type == 'A' || type == 'a'){
      Serial.println("Enter Authority: "); 
      if(Serial.available() > 0){
        num = Serial.parseFloat();
      }
      Serial.println("Authority: ");
      Serial.println(num);
    }else if(type == 'S' || type == 's'){
      Serial.println("Enter Speed: ");
      num = Serial.parseFloat();
      Serial.println(num);
    }else{*/
      trainDetected_railBroken = Serial.parseInt();
    if(trainDetected_railBroken != 0){
      if(trainDetected_railBroken == 11){
        Serial.println("Train & Broken Rail Detection:"); 
        Serial.print(trainDetected_railBroken);
        Serial.print("  |  ");
        Serial.println("No Train (1) ; No Broken Rail (1).");
      }else if(trainDetected_railBroken == 12){
        Serial.println("Train & Broken Rail Detection:"); 
        Serial.print(trainDetected_railBroken);
        Serial.print("  |  ");
        Serial.println("No Train (1) ; Broken Rail Detected (2) !!!");
      }else if(trainDetected_railBroken == 21){
        Serial.println("Train & Broken Rail Detection:"); 
        Serial.print(trainDetected_railBroken);
        Serial.print("  |  ");
        Serial.println("Train Detected (2) ; No Broken Rail (1).");
      }else if(trainDetected_railBroken == 22){
        Serial.println("Train & Broken Rail Detection:"); 
        Serial.print(trainDetected_railBroken);
        Serial.print("  |  ");
        Serial.println("Train Detected (2) ; Broken Rail Detected (2) !!!");
      }else{
        Serial.println("ERROR: Invalid Input Format!");
      }
    }
    //}
  }
}
