#include "uiswtraincontroller.h"
#include "ui_uiswtraincontroller.h"
#include<QDebug>

UISWTrainController::UISWTrainController(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UISWTrainController)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(timerInst()));
    timer->start(1000);
}

UISWTrainController::~UISWTrainController()
{
    delete ui;
}

void UISWTrainController::timerInst()
{
    ui->currentVelocity->setText(QString::number(swtraincontroller->getCurrentVelocity()));
    ui->suggestedVelocity->setText(QString::number(swtraincontroller->getSetpointVelocity()));
    ui->speedLimit->setText(QString::number(swtraincontroller->getSpeedLimit()));
    ui->authority->setText(QString::number(swtraincontroller->getAuthority()));
    ui->power->setText(QString::number(swtraincontroller->getPowerCommand()));
    ui->incomingStation->setText(QString::fromStdString(swtraincontroller->getIncommingStation()));
    ui->nxtStation->setText(QString::fromStdString(swtraincontroller->getIncommingStation()));
}


void UISWTrainController::on_driverEmergencyBrake_clicked()
{
    swtraincontroller->setEmergencyBrake(true);
}

void UISWTrainController::on_leftDoors_valueChanged(int value)
{
    swtraincontroller->setLeftDoors(value);
}


void UISWTrainController::on_rightDoors_valueChanged(int value)
{
    swtraincontroller->setRightDoors(value);
}


void UISWTrainController::on_interiorLights_valueChanged(int value)
{
    swtraincontroller->setInteriorLights(value);
}


void UISWTrainController::on_exteriorLights_valueChanged(int value)
{
    swtraincontroller->setExteriorLights(value);
}


void UISWTrainController::on_serviceBrake_clicked()
{
    swtraincontroller->setServiceBrake(true);
}


void UISWTrainController::on_modeswitch_valueChanged(int value)
{
    swtraincontroller->setMode(value);
}


void UISWTrainController::on_announceStation_clicked()
{
    //Impliment later
}


void UISWTrainController::on_kp_returnPressed()
{
    swtraincontroller->setKp(ui->kp->text().toDouble());
}


void UISWTrainController::on_ki_returnPressed()
{
    swtraincontroller->setKi(ui->ki->text().toDouble());
}


void UISWTrainController::on_commandeVelocity_returnPressed()
{
    swtraincontroller->setCommandedVelocity(ui->commandeVelocity->text().toDouble());
}

