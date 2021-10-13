#include "serialconnectdialog.h"
#include "ui_serialconnectdialog.h"

#include "serialport.h"

SerialConnectDialog::SerialConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialConnectDialog)
{
    //variables
    portList = QSerialPortInfo::availablePorts();

    ui->setupUi(this);

    for(auto &port : portList)
    {
        QString portName = port.portName();
        ui->trainPortsCombo->addItem(portName);
    }


}

SerialConnectDialog::~SerialConnectDialog()
{
    delete ui;
}

void SerialConnectDialog::on_connectButton_clicked()
{
    if(portInfo != NULL)
    {
        trainControllerSerialPort.openSerialPort(*portInfo);
    }
    else
    {
        qDebug() << "NULL";
    }

}

void SerialConnectDialog::on_trainPortsCombo_currentIndexChanged(int index)
{
    if(index>= 0 && index < portList.length())
    {
        portInfo = &(portList[index]);
    }
}
