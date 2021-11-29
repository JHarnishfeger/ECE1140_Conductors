#ifndef SERIALPORTMOC_H
#define SERIALPORTMOC_H

#include "hwtraincontrollermoc.h"

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <iostream>
#include <QTimer>
#include <QDebug>


class SerialPortMoc : public QObject
{
    Q_OBJECT
public:
    QSerialPort *arduino = nullptr;

//    QTimer *writeTimer;
//    QTimer *readTimer;

    explicit SerialPortMoc(QObject *parent = nullptr);
    void openSerialPort(QSerialPortInfo &portInfo);

public slots:
//    void readSerial();
//    void writeSerial();


signals:

};



#endif // SERIALPORTMOC_H
