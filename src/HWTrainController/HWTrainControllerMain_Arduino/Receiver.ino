void ReceiveData() {
  if (Serial.available() > 0){
    receivedString = Serial.readStringUntil('\n');
  }

  if(receivedString.substring(0,1).equals("1")) digitalWrite(led1, HIGH);
  else if(receivedString.substring(0,1).equals("0")) digitalWrite(led1, LOW);

  if(receivedString.substring(1,2).equals("1")) digitalWrite(led2, HIGH);
  else if(receivedString.substring(1,2).equals("0")) digitalWrite(led2, LOW);

  delay(100);
}
