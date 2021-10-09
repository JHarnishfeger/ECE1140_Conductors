#define led 32

String receivedString;

void ReceiveData() {
  if (Serial.available() > 0){
    receivedString = Serial.readStringUntil('\n');
  }

  if (receivedString.equals("ON")) digitalWrite(led, HIGH);
  else if (receivedString.equals("OFF")) digitalWrite(led, LOW);
}
