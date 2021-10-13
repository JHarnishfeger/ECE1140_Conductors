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
    char 31-35        = stationCode
    */

    Kp = receivedString.substring(1,5);
    Ki = receivedString.substring(6,10);
    authority = receivedString.substring(11,15);
    commandedSpeed = receivedString.substring(16,20);
    setpointSpeed = receivedString.substring(21,25);
    currentSpeed = receivedString.substring(26,30);
    
    stationCode = receivedString.substring(31,35);
    stationName = decodeStationName(stationCode);
    

//    lcd.setCursor(0,0);
//    lcd.print(receivedString);
    
}

String decodeStationName(String code)
{
    if(stationCode == "00000") stationCode = "SHADYSIDE";
    else if(stationCode == "00001") stationCode = "HERRON AVE";
    else if(stationCode == "00010") stationCode = "SWISSVILLE";
    else if(stationCode == "00011") stationCode = "PENN STATION";
    else if(stationCode == "00100") stationCode = "STEEL PLAZA";
    else if(stationCode == "00101") stationCode = "FIRST AVE";
    else if(stationCode == "00110") stationCode = "STATION SQUARE";
    else if(stationCode == "00111") stationCode = "SOUTH HILLS JUNCTION";
    else if(stationCode == "01000") stationCode = "PIONEER";
    else if(stationCode == "01001") stationCode = "EDGEBROOK";
    else if(stationCode == "01010") stationCode = "WHITED";
    else if(stationCode == "01011") stationCode = "SOUTH BANK";
    else if(stationCode == "01100") stationCode = "CENTRAL";
    else if(stationCode == "01101") stationCode = "INGLEWOOD";
    else if(stationCode == "01110") stationCode = "OVERBROOK";
    else if(stationCode == "01111") stationCode = "GLENBURY";
    else if(stationCode == "10000") stationCode = "DORMONT";
    else if(stationCode == "10001") stationCode = "MT. LEBANON";
    else if(stationCode == "10010") stationCode = "POPLAR";
    else if(stationCode == "10011") stationCode = "CASTLE SHANNON";
    else stationCode = "YARD";
    return stationCode;
}
