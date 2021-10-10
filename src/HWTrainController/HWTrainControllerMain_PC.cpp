#include <iostream>
#include "SerialPort.h"
#include <stdio.h>
#include <string.h>

using namespace std;

const char* portName = "\\\\.\\COM3";

#define MAX_DATA_LENGTH 255

char incomingData[MAX_DATA_LENGTH];

//Control signals for turning on and turning off the led
//Check arduino code
const char* ledON = "01\n";
//const char* ledOFF = "OFF\n";

//Arduino SerialPort object
SerialPort *arduino;

//Blinking Delay
const unsigned int BLINKING_DELAY = 1000;

//Check if data was writen
bool didWrite;

//serialState = TRUE (send) serialState = FALSE (receive)
bool serialState;

void exampleReceiveData(void)
{
    int readResult = arduino->readSerialPort(incomingData, MAX_DATA_LENGTH);
    printf("%s", incomingData);
    Sleep(10);
}

void exampleWriteData(unsigned int delayTime)
{
    didWrite = arduino->writeSerialPort(ledON, MAX_DATA_LENGTH);
}

void autoConnect(bool serialState)
{
    //better than recusion
    //avoid stack overflows
    while(1) {
        // ui - searching
        std::cout << "Searching in progress";
        // wait connection
        while (!arduino->isConnected()) {
            Sleep(100);
            std::cout << ".";
            arduino = new SerialPort(portName);
        }

        //Checking if arduino is connected or not
        if (arduino->isConnected()) {
            std::cout  << std::endl << "Connection established at port " << portName << std::endl;
        }

        if(serialState)
            while(arduino->isConnected()) exampleWriteData(BLINKING_DELAY);
        else // SEND
            while(arduino->isConnected()) exampleReceiveData();
    }
}

int main()
{
    arduino = new SerialPort(portName);

    serialState = FALSE;

    autoConnect(serialState);
}
