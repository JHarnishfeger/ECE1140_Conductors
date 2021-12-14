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
    //timer set up and updateUI running function
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(updateTestUI()));

    //Connects traincontroller to train and train timer to TC timer
    s.swtraincontroller.train=mainTrain;//Sets train in the traincontroller to the train in the trainModel UI
    s.show();
    connect(timer, SIGNAL(timeout()),&s,SLOT(timerInst()));
    timer ->start(1000);

    //Connects train controller getTCData to train model GetTCData
    connect(&s,SIGNAL(getnewTCSignal()), this, SLOT(callTCData()));

    HorS = HardwareOrSoftware;
    RorG = RedOrGreen;
    mainTrain->setID(ID);
    ui->Height_2->display(3);
    ui->Length_2->display(20);
    ui->Width_2->display(3);
}

trainUI::~trainUI(){
    delete ui;
}

/*Function is for murphy inputs to set
  failures at any point in time.
  */
QString trainUI::setBFail(bool bt){

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
QString trainUI::setEFail(bool et){
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
QString trainUI::setSFail(bool st){
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
    ui->label->setText(setEFail(engineFail));
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

    ui->label_2->setText(setBFail(brakeFail));
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
    ui->label_3->setText(setSFail(signalFail));
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

void trainUI::updateTestUI(){
    mainTrain->setSpeed(mainTrain->getPower());
    ui->lcdNumber->display(mainTrain->getSpeed());
    ui->lcdNumber_2->display(mainTrain->getAcceleration());
    ui->lcdNumber_3->display(mainTrain->getAuthority());
    ui->lcdNumber_4->display(mainTrain->getPassengers());
    ui->lcdNumber_5->display(mainTrain->getCrew());
    ui->lcdNumber_6->display(mainTrain->getTemperature());
    ui->lcdNumber_7->display(mainTrain->getPower());


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


