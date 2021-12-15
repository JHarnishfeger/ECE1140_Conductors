#include "testui.h"
#include "ui_testui.h"

//Creates a test UI, makes a timer for UI, and creates one train to start
Testui::Testui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Testui)
{
    ui->setupUi(this);
    sig.newTrainController();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(updateTestUI()));
    timer->start(1);
}

Testui::~Testui()
{
    delete ui;
}

//Creates a new train by calling the signal handler function to create a train controller pointer
void Testui::on_makeTrain_clicked()
{
    sig.newTrainController();
}

//Will set variable to select which train control
void Testui::on_spinBox_valueChanged(int arg1)
{
    sig.train_select = train_select;
    train_select = arg1-1;
}

//Updates Test UI Every 1ms
void Testui::updateTestUI()
{
    if(sig.trainList[train_select]->getLeftDoors())
        ui->LeftDoors->setText("Open");
    else
        ui->LeftDoors->setText("Closed");

    if(sig.trainList[train_select]->getRightDoors())
        ui->RightDoors->setText("Open");
    else
        ui->RightDoors->setText("Closed");

    if(sig.trainList[train_select]->getExteriorLights())
        ui->ExteriorLights->setText("On");
    else
        ui->ExteriorLights->setText("Off");

    if(sig.trainList[train_select]->getInteriorLights())
        ui->InteriorLights->setText("On");
    else
        ui->InteriorLights->setText("Off");

    ui->NextStation->setText(QString::fromStdString(sig.trainList[train_select]->getIncommingStation()));

    ui->Power->setText(QString::number(sig.sendPowerTest()));

    ui->GPS->setText(QString::number(sig.sendGPSTest()));
}

void Testui::on_SendBeaconData_clicked()
{
    //Normally, this data will be sent via 64-bit unsigned int, however for testing purposes I will just get the value on the inavidual instance of the train
    sig.trainList[train_select]->setAuthority(100);
    sig.trainList[train_select]->setMBAuthority(150);
    sig.trainList[train_select]->setSetpointVelocity(50);
    sig.trainList[train_select]->setSpeedLimit(50);
    sig.trainList[train_select]->setIncommingStation("Shady Side");
}


void Testui::on_EngineFailure_clicked()
{
    //Activate Engine Failure, power integrator stops
}


void Testui::on_SignalPickupFailure_clicked()
{
    //Signal Pickup Fail, stop train
}


void Testui::on_BrakeFailure_clicked()
{
    //Brake failure, dont take any brake info and cut power integral
}


void Testui::on_passengerEmergencyBrake_clicked()
{
    sig.trainList[train_select]->setPassengerBrake(true);
}


void Testui::on_currentVelocity_returnPressed()
{
    sig.trainList[train_select]->setCurrentVelocity(ui->currentVelocity->text().toDouble());
    sig.trainList[train_select]->calculatePower();
    sig.trainList[train_select]->gps = rand() % 899999 + 100000; //Random generation of GPS for testing purposes, this will eventually be passed in from the train model via the signal handler and decoded, then back to the signal hendler to be passed to MBO

}

