#include<iostream>
using namespace std;

#include<string>
#include<stdlib.h>
#include"SerialPort.cpp"

char *port = "\\\\.\\COM4";
char output[MAX_DATA_LENGTH];
char incoming[MAX_DATA_LENGTH];

SerialPort ardu(port);

bool ifArduConnected(){
  return ardu.isConnected();
}

void writeToArdu(string com){
  string command = com;
  char *charArray = new char[command.size() + 1];
  copy(command.begin(), command.end(), charArray);
  charArray[command.size()] = '\n';

  ardu.writeSerialPort(charArray, MAX_DATA_LENGTH);

  delete [] charArray;
}

void receiveFromArdu(){
  ardu.readSerialPort(output, MAX_DATA_LENGTH);

  //cout << "zhe" <<output << endl;

}

int char_to_int(char c){
  int re;
  if(c == '0'){
    re = 0;
  }else if(c == '1'){
    re = 1;
  }else if(c == '2'){
    re = 2;
  }else if(c == '3'){
    re = 3;
  }else if(c == '4'){
    re = 4;
  }else if(c == '5'){
    re = 5;
  }else if(c == '6'){
    re = 6;
  }else if(c == '7'){
    re = 7;
  }else if(c == '8'){
    re = 8;
  }else if(c == '9'){
    re = 9;
  }
  return re;
}
