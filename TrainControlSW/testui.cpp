#include "testui.h"
#include "ui_testui.h"
#include <QtDebug>

//Creates a test UI, makes a timer for UI, and creates one train to start
Testui::Testui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Testui)
{
    s.show();
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(updateTestUI()));
    timer->start(1000);

}

Testui::~Testui()
{
    delete ui;
}


//Updates Test UI Every 1ms
void Testui::updateTestUI()
{
        if(s.swtraincontroller.getLeftDoors())
            ui->LeftDoors->setText("Open");
        else
            ui->LeftDoors->setText("Closed");

        if(s.swtraincontroller.getRightDoors())
            ui->RightDoors->setText("Open");
        else
            ui->RightDoors->setText("Closed");

        if(s.swtraincontroller.getExteriorLights())
            ui->ExteriorLights->setText("On");
        else
            ui->ExteriorLights->setText("Off");

        if(s.swtraincontroller.getInteriorLights())
            ui->InteriorLights->setText("On");
        else
            ui->InteriorLights->setText("Off");

        ui->NextStation->setText(QString::fromStdString(s.swtraincontroller.getIncommingStation()));
}

void Testui::on_sendTackCircuit_clicked()
{
    //Normally, this data will be sent via 64-bit unsigned int, however for testing purposes I will just get the value on the inavidual instance of the train
    s.swtraincontroller.setAuthority(1);
    s.swtraincontroller.setMBAuthority(150);
    s.swtraincontroller.setSetpointVelocity(50);
    s.swtraincontroller.setSpeedLimit(50);
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
    s.swtraincontroller.setPassengerBrake(true);
}


void Testui::on_currentVelocity_returnPressed()
{
    s.swtraincontroller.setCurrentVelocity(ui->currentVelocity->text().toDouble());
}

