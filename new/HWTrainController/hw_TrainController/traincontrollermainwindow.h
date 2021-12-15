#ifndef TRAINCONTROLLERMAINWINDOW_H
#define TRAINCONTROLLERMAINWINDOW_H

#include "serialport.h"
#include "traincontroller.h"
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <iostream>
#include <QTimer>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class TrainControllerMainWindow; }
QT_END_NAMESPACE

class TrainControllerMainWindow : public QMainWindow{
    Q_OBJECT

public:
    Ui::TrainControllerMainWindow *ui;
    QSerialPortInfo *portInfo;
    QTimer *setTimer;
    TrainController trainController;

    TrainControllerMainWindow(QWidget *parent = nullptr);
    ~TrainControllerMainWindow();

private slots:

    void on_enterButton_clicked();

    void updates();

    void on_testButton_clicked();
    void setUtilities();
    void setPower();

    void on_connectionComboBox_currentIndexChanged(int index);

    void on_ConnectButton_clicked();

private:
    QList<QSerialPortInfo> portList;

};

#endif // TRAINCONTROLLERMAINWINDOW_H
