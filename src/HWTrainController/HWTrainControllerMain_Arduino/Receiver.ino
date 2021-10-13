void ReceiveData() {
  if (Serial.available() > 0){
    receivedString = Serial.readStringUntil('\n');
  }

    /*String decoding
    char 0            = parity
    char 1-5          = kp
    char 6-10          = ki
    char 11-15        = authority
    char 16-20        = commandedSpeed
    char 21-25        = setpointSpeed
    char 26-30        = currentSpeed
    */

    Kp = receivedString.substring(1,5);
    Ki = receivedString.substring(6,10);
    authority = receivedString.substring(11,15);
    commandedSpeed = receivedString.substring(16,20);
    setpointSpeed = receivedString.substring(21,25);
    currentSpeed = receivedString.substring(26,30);

    lcd.setCursor(0,0);
    lcd.print(receivedString);
    
}
