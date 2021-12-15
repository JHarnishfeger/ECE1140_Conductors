void ReceiveData()
{
  if (Serial.available() > 0){
    receivedString = Serial.readStringUntil('\n');


    /*String decoding
    char 0            = parity
    char 1-4          = kp
    char 5-8          = ki
    char 9-13         = commandedSpeed
    char 14-18        = currentSpeed
    char 19-23        = suggestedSpeed
    char 24-28        = speedLimit
    char 29-33        = authority
    char 34-38        = stationCode
    char 39           = breakFail 
    */

    KpString = receivedString.substring(1,5); //[1 2 3 4]
    KiString = receivedString.substring(5,9); //[5 6 7 8]
    commandedSpeedString = receivedString.substring(9,14); //[9 10 11 12 13]
    currentSpeedString = receivedString.substring(14,19);//[14 15 16 17 18]
    suggestedSpeedString = receivedString.substring(19,24); //[19 20 21 22 23]
    speedLimitString = receivedString.substring(24,29); //[24 25 26 27 28]
    authorityString = receivedString.substring(29,34); //[29 30 31 32 33]
    stationCode = receivedString.substring(34,39); //[34 35 36 37 38]
    breakFail = receivedString.substring(39,40) == '1'; //[39]
    engineFailString = receivedString.substring(40,41); //[40]
    tcFailString = receivedString.substring(41,42); //[41]

    //decode the stationcode into name of the station
    stationName = decodeStationName(stationCode);

    convert2Numbers();

    
  }
    
}

String decodeStationName(String stationCode)
{
    if(stationCode == "00000") stationName = "SHADYSIDE";
    else if(stationCode == "00001") stationName = "HERRON AVE";
    else if(stationCode == "00010") stationName = "SWISSVILLE";
    else if(stationCode == "00011") stationName = "PENN STATION";
    else if(stationCode == "00100") stationName = "STEEL PLAZA";
    else if(stationCode == "00101") stationName = "FIRST AVE";
    else if(stationCode == "00110") stationName = "STATION SQUARE";
    else if(stationCode == "00111") stationName = "SOUTH HILLS JUNCTION";
    else if(stationCode == "01000") stationName = "PIONEER";
    else if(stationCode == "01001") stationName = "EDGEBROOK";
    else if(stationCode == "01010") stationName = "WHITED";
    else if(stationCode == "01011") stationName = "SOUTH BANK";
    else if(stationCode == "01100") stationName = "CENTRAL";
    else if(stationCode == "01101") stationName = "INGLEWOOD";
    else if(stationCode == "01110") stationName = "OVERBROOK";
    else if(stationCode == "01111") stationName = "GLENBURY";
    else if(stationCode == "10000") stationName = "DORMONT";
    else if(stationCode == "10001") stationName = "MT. LEBANON";
    else if(stationCode == "10010") stationName = "POPLAR";
    else if(stationCode == "10011") stationName = "CASTLE SHANNON";
    else if(stationCode == "11111") stationName = "YARD";
    
    return stationName;
}
