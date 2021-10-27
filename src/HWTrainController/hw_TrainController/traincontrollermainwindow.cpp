#include "traincontrollermainwindow.h"
#include "ui_traincontrollermainwindow.h"

#include "serialport.h"

TrainControllerMainWindow::TrainControllerMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TrainControllerMainWindow)
{
    //variables
    portList = QSerialPortInfo::availablePorts();
    setTimer = new QTimer(this);
    setTimer->setInterval(900);

    connect(setTimer, &QTimer::timeout, this, &TrainControllerMainWindow::setUtilities);
    connect(setTimer, &QTimer::timeout, this, &TrainControllerMainWindow::setPower);
    setTimer->start();

    ui->setupUi(this);

}

TrainControllerMainWindow::~TrainControllerMainWindow()
{
    delete ui;
}

void TrainControllerMainWindow::on_connectionSettingsButton_clicked()
{
    serialConnectDialog = new SerialConnectDialog;
    serialConnectDialog->show();

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

