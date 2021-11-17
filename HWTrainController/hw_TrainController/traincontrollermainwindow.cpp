#include "traincontrollermainwindow.h"
#include "ui_traincontrollermainwindow.h"

#include "serialport.h"

TrainControllerMainWindow::TrainControllerMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TrainControllerMainWindow)
{
     ui->setupUi(this);

    //variables
    portList = QSerialPortInfo::availablePorts();

    for(auto &port : portList)
    {
        QString portName = port.portName();
        ui->connectionComboBox->addItem(portName);
    }

    setTimer = new QTimer(this);
    setTimer->setInterval(1000);

    connect(setTimer, &QTimer::timeout, this, &TrainControllerMainWindow::updates);
    setTimer->start();

}

TrainControllerMainWindow::~TrainControllerMainWindow()
{
    delete ui;
}

void TrainControllerMainWindow::updates()
{
    if(trainController.serialport.arduino->isOpen())
    {
        trainController.writeSerial();
        trainController.readSerial();
    }
    else
    {
        qDebug() << "Serial Port Not Connected...";
    }

    setUtilities()
    setPower();
}

void TrainControllerMainWindow::on_enterButton_clicked()
{
    trainController.setKp(ui->KpText->text());
    trainController.setKi(ui->KiText->text());
}

void TrainControllerMainWindow::on_testButton_clicked()
{
    trainController.setCommandedSpeed(ui->commandedSpeed->text());
    trainController.setCurrentSpeed(ui->currentSpeed->text());
    trainController.setSuggestedSpeed(ui->suggestedSpeed->text());
    trainController.setSpeedLimit(ui->speedLimit->text());
    trainController.setAuthority(ui->authority->text());
    trainController.setNextStation(ui->nextStation->text());

}

void TrainControllerMainWindow::setUtilities()
{
    ui->LeftDoorsCB->setChecked(trainController.getLeftDoors());
    ui->RightDoorsCB->setChecked(trainController.getRightDoors());
    ui->InteriorLightsCB->setChecked(trainController.getInteriorLights());
    ui->ExteriorLightsCB->setChecked(trainController.getExteriorLights());
    ui->ServiceBreakCB->setChecked(trainController.getServiceBreak());
    ui->EmergencyBreakCB->setChecked(trainController.getEBreak());
    ui->PassengerBreakCB->setChecked(trainController.getPassengerBreak());
    ui->mode->setText(trainController.getMode());
}

void TrainControllerMainWindow::setPower()
{
    ui->powerLabel->setText(trainController.getCommandedPower());
}


void TrainControllerMainWindow::on_connectionComboBox_currentIndexChanged(int index)
{
    if(index>= 0 && index < portList.length())
    {
        portInfo = &(portList[index]);
    }
}

void TrainControllerMainWindow::on_ConnectButton_clicked()
{
    if(portInfo != NULL)
    {
        trainController.serialport.openSerialPort(*portInfo);
    }
    else
    {
        qDebug() << "NULL";
    }
}

