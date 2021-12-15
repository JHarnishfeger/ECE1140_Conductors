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

    explicit SerialPort(QObject *parent = nullptr);
    void openSerialPort(QSerialPortInfo &portInfo);

};



#endif // SERIALPORT_H
