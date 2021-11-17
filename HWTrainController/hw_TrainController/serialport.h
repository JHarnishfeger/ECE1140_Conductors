#ifndef SERIALPORT_H
#define SERIALPORT_H

//#include "traincontroller.h"

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <iostream>
#include <QTimer>
#include <QDebug>


class SerialPort : public QObject
{
    Q_OBJECT
public:
    QSerialPort *arduino = nullptr;

//    QTimer *writeTimer;
//    QTimer *readTimer;

    explicit SerialPort(QObject *parent = nullptr);
    void openSerialPort(QSerialPortInfo &portInfo);

public slots:
//    void readSerial();
//    void writeSerial();


signals:

};



#endif // SERIALPORT_H
