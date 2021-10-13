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

void TrainControllerMainWindow::on_setKpKiButton_clicked()
{
    trainController.setKp(ui->KpText->text());
    trainController.setKi(ui->KiText->text());

//    qDebug() << trainController.getKp();
//    qDebug() << trainController.getKi();
}

//void TrainControllerMainWindow::on_commandedVelocity_editingFinished()
//{
//    trainController.setCommandedVelocity(ui->commandedVelocity->text());
//    //qDebug() << trainController.getCommandedVelocity();
//}

//void TrainControllerMainWindow::on_currentVelocity_editingFinished()
//{
//    trainController.setCurrentVelocity(ui->currentVelocity->text());
//    //qDebug() << trainController.getCurrentVelocity();
//}

//void TrainControllerMainWindow::on_suggestedVelocity_editingFinished()
//{
//    trainController.setSuggestedVelocity(ui->suggestedVelocity->text());
//    //qDebug() << trainController.getSuggestedVelocity();
//}

//void TrainControllerMainWindow::on_speedLimit_editingFinished()
//{
//    trainController.setSpeedLimit(ui->speedLimit->text());
//    //qDebug() << trainController.getSpeedLimit();
//}

//void TrainControllerMainWindow::on_authority_editingFinished()
//{
//    trainController.setAuthority(ui->authority->text());
//    //qDebug() << trainController.getAuthority();
//}

void TrainControllerMainWindow::on_testButton_clicked()
{
    trainController.setCommandedVelocity(ui->commandedVelocity->text());
    trainController.setCurrentVelocity(ui->currentVelocity->text());
    trainController.setSuggestedVelocity(ui->suggestedVelocity->text());
    trainController.setSpeedLimit(ui->speedLimit->text());
    trainController.setSpeedLimit(ui->speedLimit->text());
    trainController.setAuthority(ui->authority->text());
}

void TrainControllerMainWindow::setUtilities()
{
    ui->LeftDoorsCB->setChecked(trainController.getLeftDoors());
    ui->RightDoorsCB->setChecked(trainController.getRightDoors());
    ui->InteriorLightsCB->setChecked(trainController.getInteriorLights());
    ui->ExteriorLightsCB->setChecked(trainController.getExteriorLights());
    ui->ServiceBreakCB->setChecked(trainController.getServiceBreak());
    ui->EmergencyBreakCB->setChecked(trainController.getEBreak());
}

void TrainControllerMainWindow::setPower()
{
    ui->powerLabel->setText(trainController.getPower());
    qDebug() << trainController.getPower();
}

