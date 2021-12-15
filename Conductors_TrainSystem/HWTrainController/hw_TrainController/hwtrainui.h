#ifndef HWTRAINUI_H
#define HWTRAINUI_H

#include "serialport.h"
#include "traincontroller.h"
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <iostream>
#include <QTimer>
#include <QDebug>

namespace Ui {
class HWTrainUI;
}

class HWTrainUI : public QMainWindow{
    Q_OBJECT

public:

    Ui::HWTrainUI *ui;
    QSerialPortInfo *portInfo;
    QTimer *setTimer;
    TrainController trainController;

    explicit HWTrainUI(QWidget *parent = nullptr);
    ~HWTrainUI();

signals:
    void getNewTCSignal(uint8_t encodedBlock);

private slots:

    void decodeSignals();
    void on_connectButton_clicked();
    void on_commandedSpeed_returnPressed();
    void on_enterButton_clicked();
    void updates();
    void on_ports_currentIndexChanged(int index);

private:
    QList<QSerialPortInfo> portList;
};

#endif // HWTRAINUI_H
