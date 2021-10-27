#include "serialport.h"

SerialPort::SerialPort(QObject *parent) : QObject(parent)
{
    arduino = new QSerialPort(this);
    writeTimer = new QTimer();
    readTimer = new QTimer();
    writeTimer->setInterval(900);
    readTimer->setInterval(900);


}

void SerialPort::openSerialPort(QSerialPortInfo &arduinoInfo)
{
    arduino->setPortName(arduinoInfo.portName());
    arduino->setPort(arduinoInfo);
    arduino->open(QSerialPort::ReadWrite);
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);

    if(arduino->isOpen())
    {
        qDebug() << " Arduino Connected at port: " << arduino->portName();
    }
    else
    {
        qDebug() << "Arduino not Connected";
    }

    connect(readTimer, &QTimer::timeout, this, &SerialPort::readSerial);
    connect(writeTimer, &QTimer::timeout, this, &SerialPort::writeSerial);
    writeTimer->start();
    readTimer->start();
}

void SerialPort::readSerial()
{
    dataIN = arduino->readAll();
    temp = QString(dataIN);
    temp.remove('\r').remove('\n');

    if(dataIN_concat.length() != 13)
    {
        dataIN_concat += temp;
        if(dataIN_concat.length() == 13 && dataIN_concat.front() == "1")
        {
            dataIN_concat.remove(0,1);
            qDebug() << "Receive Length: " << dataIN_concat.length() << " " << "Receive: " << dataIN_concat;
            trainController.decodeData(dataIN_concat);
            dataIN_concat = "";
        }
        if(dataIN_concat.length() >= 13*2)
        {
            dataIN_concat = "";
        }
    }

}

void SerialPort::writeSerial()
{
    QByteArray temp = trainController.encodeData();

    const char* in = temp.data();

    arduino->write(in);
    qDebug() << "Sending: " << in;

    //arduino->write("HelloThereHelloThereHelloTher\n");
}

SerialPort trainControllerSerialPort;
