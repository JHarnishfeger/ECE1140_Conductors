#ifndef TRAINCONTROLLERMAINWINDOW_H
#define TRAINCONTROLLERMAINWINDOW_H

#include "serialport.h"
#include "serialconnectdialog.h"
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

class TrainControllerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui::TrainControllerMainWindow *ui;
    QSerialPortInfo *portInfo;
    QTimer *setTimer;

    TrainControllerMainWindow(QWidget *parent = nullptr);
    ~TrainControllerMainWindow();


private slots:
    void on_connectionSettingsButton_clicked();

    void on_setKpKiButton_clicked();

//    void on_commandedVelocity_editingFinished();

//    void on_currentVelocity_editingFinished();

//    void on_suggestedVelocity_editingFinished();

//    void on_speedLimit_editingFinished();

//    void on_authority_editingFinished();

    void on_testButton_clicked();
    void setUtilities();
    void setPower();

private:
    QList<QSerialPortInfo> portList;
    SerialConnectDialog *serialConnectDialog;


};

#endif // TRAINCONTROLLERMAINWINDOW_H
