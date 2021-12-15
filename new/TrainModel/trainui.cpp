#include "trainui.h"
#include "ui_trainui.h"
#include <QTimer>
#include <QDebug>
#include <string.h>


trainUI::trainUI(QWidget *parent, bool HardwareOrSoftware,int ID, bool RedOrGreen)
    : QMainWindow(parent)
    , ui(new Ui::trainUI)
{
    ui->setupUi(this);

    //Connects traincontroller to train and train timer to TC timer
    if (HardwareOrSoftware == 1){
        s.swtraincontroller.train=mainTrain;//Sets train in the traincontroller to the train in the trainModel UI
        s.show();
        connect(this,SIGNAL(update3()),&s,SLOT(timerInst()));
        //Connects train controller getTCData to train model GetTCData
        connect(&s,SIGNAL(getnewTCSignal(uint8_t)), this, SLOT(callTCData(uint8_t)));
    }
    else if (HardwareOrSoftware == 0){
        hw.trainController.train=mainTrain;//Sets train in the traincontroller to the train in the trainModel UI
        hw.show();
        connect(this,SIGNAL(update3()),&hw,SLOT(updates()));
        //Connects train controller getTCData to train model GetTCData
        connect(&hw,SIGNAL(getnewTCSignal(uint8_t)), this, SLOT(callTCData(uint8_t)));
    }

    HorS = HardwareOrSoftware;
    RorG = RedOrGreen;
    uiID = ID;
}

trainUI::~trainUI(){
    delete ui;
}

/*Function is for murphy inputs to set
  failures at any point in time.
  */
QString trainUI::setBFail(){

  if (brakeFail == true){
    return "FAIL";
  }
  else{
    return "No Failures";
  }

  mainTrain->setFailures(engineFail,signalFail,brakeFail);
}

/*Function is for murphy inputs to set
  failures at any point in time.
  */
QString trainUI::setEFail(){
  if (engineFail == true){
    return "FAIL";
  }
  else{
    return "No Failures";
  }
  mainTrain->setFailures(engineFail,signalFail,brakeFail);
}

/*Function is for murphy inputs to set
  failures at any point in time.
  */
QString trainUI::setSFail(){
  if (signalFail == true){
    return "FAIL";
  }
  else{
    return "No Failures";
  }
  mainTrain->setFailures(engineFail,signalFail,brakeFail);
}

void trainUI::on_EngineFail_clicked()
{
    if (engineFail == true){
        engineFail = false;
    }
    else {
         engineFail = true;
    }
    ui->label->setText(setEFail());
    mainTrain->setFailures(engineFail,signalFail,brakeFail);
}


void trainUI::on_BrakeFail_clicked()
{
    if (brakeFail == true){
        brakeFail = false;
    }
    else {
         brakeFail = true;
    }

    ui->label_2->setText(setBFail());
    mainTrain->setFailures(engineFail,signalFail,brakeFail);
}


void trainUI::on_SignalFail_clicked()
{
    if (signalFail == true){
        signalFail = false;
    }
    else {
         signalFail = true;
    }
    ui->label_3->setText(setSFail());
    mainTrain->setFailures(engineFail,signalFail,brakeFail);
}

void trainUI::on_pushButton_clicked()
{
    if (mainTrain->getBrakeFail() == false){
        if(!mainTrain->getEbrakes()){
            ui->progressBar_2->setValue(100);
            mainTrain->setEbrakes(true);
        }else{
            ui->progressBar_2->setValue(25);
            mainTrain->setEbrakes(false);
        }
    }
}

//bool Train::getBfail(){
//    return brakeFail;
//}
//bool Train::getEfail(){
//    return engineFail;
//}
//bool Train::getSfail(){
//    return signalFail;
//}

void trainUI::updateUI(){
    //updating controller UIs
    emit update3();

    mainTrain->setSpeed(mainTrain->getPower());
    mainTrain->setID(uiID);
    ui->lcdNumber->display(QString::number(mainTrain->getSpeed()));
    ui->lcdNumber_2->display(QString::number(mainTrain->getAcceleration()));
    ui->lcdNumber_3->display(QString::number(mainTrain->getAuthority()));
    ui->lcdNumber_4->display(QString::number(mainTrain->getPassengers()));
    ui->lcdNumber_5->display(QString::number(mainTrain->getCrew()));
    ui->lcdNumber_6->display(QString::number(mainTrain->getTemperature()));
    ui->lcdNumber_7->display(QString::number(mainTrain->getPower()));
    ui->Height_2->display(QString::number(3));
    ui->Length_2->display(QString::number(20));
    ui->Width_2->display(QString::number(3));

    //ui->Acceleration->setText(QString::number(mainTrain->getAcceleration()));
    //ui->Speed->setText(QString::number(mainTrain->getSpeed()));
    //ui->Authority->setText(QString::number(mainTrain->getAuthority()));
    //ui->Passengers->setText(QString::number(mainTrain->getPassengers()));
    //ui->Crew->setText(QString::number(mainTrain->getCrew()));
    //ui->Temperature->setText(QString::number(mainTrain->getTemperature()));
    //ui->Power->setText(QString::number(mainTrain->getPower()));
    //ui->Length_2->setText(QString::number(32));
    //ui->Width_2->setText(QString::number(3.2));
    //ui->Height_2->setText(QString::number(2.84));

    //Brakes
    if(mainTrain->getBrakes() == true){
        ui->progressBar->setValue(100);
    }
    else{
        ui->progressBar->setValue(0);
    }

    //Ebrakes
    if(mainTrain->getEbrakes() == true){
        ui->progressBar_2->setValue(100);
    }
    else{
        ui->progressBar_2->setValue(0);
    }

    //Lights
    if (mainTrain->getInteriorLights() == true){
        ui->progressBar_5->setValue(100);
    }
    else{
        ui->progressBar_5->setValue(0);
    }
    if (mainTrain->getExteriorLights() == true){
        ui->progressBar_6->setValue(100);
    }
    else{
        ui->progressBar_6->setValue(0);
    }

    //Doors
    if (mainTrain->getLeftDoor() == true){
        ui->progressBar_3->setValue(100);
    }
    else{
        ui->progressBar_3->setValue(0);
    }
    if (mainTrain->getRightDoor() == true){
        ui->progressBar_4->setValue(100);
    }
    else{
        ui->progressBar_4->setValue(0);
    }

    ui->textBrowser->setText("Train " + QString::fromStdString(std::to_string((mainTrain->getID()))));

};

void trainUI::on_Temp_Change_sliderMoved(int position)
{
    mainTrain->setTemperature(position);
}

void trainUI::callTCData(uint8_t currentBlock){
    emit callAgainTCData(currentBlock,mainTrain->getID(),RorG);
}

