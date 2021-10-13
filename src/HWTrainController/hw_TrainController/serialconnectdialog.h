#ifndef SERIALCONNECTDIALOG_H
#define SERIALCONNECTDIALOG_H

#include "serialport.h"

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <iostream>
#include <QTimer>
#include <QDebug>

namespace Ui {
class SerialConnectDialog;
}

class SerialConnectDialog : public QDialog
{
    Q_OBJECT

public:
    QSerialPortInfo *portInfo;

    explicit SerialConnectDialog(QWidget *parent = nullptr);
    ~SerialConnectDialog();

private slots:
    void on_connectButton_clicked();
    void on_trainPortsCombo_currentIndexChanged(int index);

private:
    QList<QSerialPortInfo> portList;
    Ui::SerialConnectDialog *ui;
};

#endif // SERIALCONNECTDIALOG_H
