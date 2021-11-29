void ReceiveData()
{
  if (Serial.available() > 0){
    receivedString = Serial.readStringUntil('\n');


    /*String decoding
    char 0            = parity
    char 1-5          = kp
    char 6-10         = ki
    char 11-15        = commandedSpeed
    char 16-20        = currentSpeed
    char 21-25        = suggestedSpeed
    char 26-30        = speedLimit
    char 31-35        = authority
    char 36-40        = stationCode
    */

    KpString = receivedString.substring(1,6); //[1 2 3 4 5]
    KiString = receivedString.substring(6,11); //[6 7 8 9 10]
    commandedSpeedString = receivedString.substring(11,16); //[11 12 13 14 15]
    currentSpeedString = receivedString.substring(16,21);//[16 17 18 19 20]
    suggestedSpeedString = receivedString.substring(21,26); //[21 22 23 24 25]
    speedLimitString = receivedString.substring(26,31); //[26 27 28 29 30]
    authorityString = receivedString.substring(31,36); //[31 32 33 34 35]
    stationCode = receivedString.substring(36,41); //[36 37 38 39 40]

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
    else if(stationCode == "10100") stationName = "NO NEXT STATION";
    
    return stationName;
}
