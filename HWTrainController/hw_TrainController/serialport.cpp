#include "serialport.h"

SerialPort::SerialPort(QObject *parent) : QObject(parent){
    arduino = new QSerialPort(this);
}

void SerialPort::openSerialPort(QSerialPortInfo &arduinoInfo){
    arduino->setPortName(arduinoInfo.portName());
    arduino->setPort(arduinoInfo);
    arduino->open(QSerialPort::ReadWrite);
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);

    if(arduino->isOpen()){
        qDebug() << "Arduino Connected at port: " << arduino->portName();
    }
    else{
        qDebug() << "Arduino connection failed";
        qDebug() << arduino->NotOpenError;
    }
}



