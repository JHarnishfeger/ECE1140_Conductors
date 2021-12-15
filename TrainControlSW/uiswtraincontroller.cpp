#include "uiswtraincontroller.h"
#include "ui_uiswtraincontroller.h"
#include<QDebug>

UISWTrainController::UISWTrainController(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UISWTrainController)
{
    ui->setupUi(this);
}

UISWTrainController::~UISWTrainController()
{
    delete ui;
    swtraincontroller.~SWTrainController();
}

void UISWTrainController::timerInst()
{
    decodeSignals();
    //failureCheck();
    updateUI();
    swtraincontroller.calculatePower();
    swtraincontroller.failureCheck();
    if(swtraincontroller.newBlock())
        emit getnewTCSignal(swtraincontroller.getEncodedBlock());
}


/*
void UISWTrainController::failureCheck()
{
    if(swtraincontroller.getTCFailure()){//If track circuit failure
        if(!swtraincontroller.getEmergencyBrake()&&!swtraincontroller.getBrakeFailure())//Enable Ebrake if not
            swtraincontroller.setEmergencyBrake(1);
    }else if(swtraincontroller.getEngineFailure()){//If track engine failure
        if(!swtraincontroller.getEmergencyBrake()&&!swtraincontroller.getBrakeFailure())
            swtraincontroller.setEmergencyBrake(1);
    }else if(swtraincontroller.getBrakeFailure()){//If brake failure
        swtraincontroller.setPowerCommand(0);
        swtraincontroller.setEmergencyBrake(0);
        swtraincontroller.setServiceBrake(0);
    }
}
*/
void UISWTrainController::decodeSignals(){
    swtraincontroller.decodeBeacon();
    swtraincontroller.decodeTrackCircuit();
}

void UISWTrainController::updateUI()
{
    ui->IDLabel->setText(QString::number(swtraincontroller.getTrainID()));
    ui->currentVelocity->setText(QString::number(swtraincontroller.getCurrentVelocity()));
    ui->suggestedVelocity->setText(QString::number(swtraincontroller.getSetpointVelocity()));
    ui->speedLimit->setText(QString::number(swtraincontroller.getSpeedLimit()));
    ui->authority->setText(QString::number(swtraincontroller.getAuthority()));
    ui->power->setText(QString::number(swtraincontroller.getPowerCommand()));
    ui->incomingStation->setText(QString::fromStdString(swtraincontroller.getIncommingStation()));
    ui->nxtStation->setText(QString::fromStdString(swtraincontroller.getIncommingStation()));
}

void UISWTrainController::on_driverEmergencyBrake_clicked()
{
    if(!swtraincontroller.getBrakeFailure()){
        swtraincontroller.setEmergencyBrake(!swtraincontroller.getEmergencyBrake());
    }
}

void UISWTrainController::on_leftDoors_valueChanged(int value)
{
    swtraincontroller.setLeftDoors(value);
}


void UISWTrainController::on_rightDoors_valueChanged(int value)
{
    swtraincontroller.setRightDoors(value);
}


void UISWTrainController::on_interiorLights_valueChanged(int value)
{
    swtraincontroller.setInteriorLights(value);
}


void UISWTrainController::on_exteriorLights_valueChanged(int value)
{
    swtraincontroller.setExteriorLights(value);
}


void UISWTrainController::on_serviceBrake_clicked()
{
    if(!swtraincontroller.getBrakeFailure()){
        swtraincontroller.setServiceBrake(!swtraincontroller.getServiceBrake());
    }
}


void UISWTrainController::on_modeswitch_valueChanged(int value)
{
    swtraincontroller.setMode(value);
}


void UISWTrainController::on_announceStation_clicked()
{
    //Impliment later
}


void UISWTrainController::on_kp_returnPressed()
{
    swtraincontroller.setKp(ui->kp->text().toDouble());
}


void UISWTrainController::on_ki_returnPressed()
{
    swtraincontroller.setKi(ui->ki->text().toDouble());
}


void UISWTrainController::on_commandeVelocity_returnPressed()
{
    swtraincontroller.setCommandedVelocity(ui->commandeVelocity->text().toDouble());
}

