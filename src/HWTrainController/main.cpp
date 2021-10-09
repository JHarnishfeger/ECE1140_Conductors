#define DATA_LENGTH 255

#include "SerialPort.h"
#include <iostream>

// const char* portName = "\\\\.\\COM3";

//Declare a global object
SerialPort* arduino;

//Here '\n' is a delimiter
const char *sendString = "ON\n";

int main(void)
{
  arduino = new SerialPort("\\\\.\\COM3");
  if (arduino->IsConnected()){
    bool hasWritten = arduino->WriteData(sendString, DATA_LENGTH);
    if (hasWritten) std::cout << "Data Written Successfully" << std::endl;
    else std::cerr << "Data was not written" << std::endl;
  }
}
