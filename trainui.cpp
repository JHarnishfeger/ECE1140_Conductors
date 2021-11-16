#include "trainui.h"
#include "ui_trainui.h"
#include <QTimer>
#include <QDebug>
#include <string.h>

trainUI::trainUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::trainUI)
{
    ui->setupUi(this);

    //timer set up and updateUI running function
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(updateTestUI()));
    timer ->start(1000);

}

trainUI::~trainUI(){
    delete ui;
}

/*Function is for murphy inputs to set
  failures at any point in time.
  */
QString trainUI::setBFail(bool bt){

  brakeFail = bt;
  if (brakeFail == true){
    return "FAIL";
  }
  else{
    return "No Failures";
  }

  mainTrain.setFailures(engineFail,signalFail,brakeFail);
}

/*Function is for murphy inputs to set
  failures at any point in time.
  */
QString trainUI::setEFail(bool et){
  engineFail = et;
  if (engineFail == true){
    return "FAIL";
  }
  else{
    return "No Failures";
  }
  mainTrain.setFailures(engineFail,signalFail,brakeFail);
}

/*Function is for murphy inputs to set
  failures at any point in time.
  */
QString trainUI::setSFail(bool st){
  signalFail = st;
  if (signalFail == true){
    return "FAIL";
  }
  else{
    return "No Failures";
  }
  mainTrain.setFailures(engineFail,signalFail,brakeFail);
}

void trainUI::on_EngineFail_clicked()
{
    ui->label->setText(setEFail(true));
    mainTrain.setFailures(engineFail,signalFail,brakeFail);
}


void trainUI::on_BrakeFail_clicked()
{
    ui->label_2->setText(setBFail(true));
    mainTrain.setFailures(engineFail,signalFail,brakeFail);
}


void trainUI::on_SignalFail_clicked()
{
    ui->label_3->setText(setSFail(true));
    mainTrain.setFailures(engineFail,signalFail,brakeFail);
}

void trainUI::on_pushButton_clicked()
{
    if (mainTrain.getBrakeFail() == false){
        ui->progressBar_2->setValue(100);
        mainTrain.setEbrakes(true);
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

    //mainTrain.setSpeed(mainTrain.getPower());
    mainTrain.setSpeed(rand()%90000+10000);
    ui->lcdNumber->display(mainTrain.getSpeed());
    ui->lcdNumber_2->display(mainTrain.getAcceleration());
    ui->lcdNumber_3->display(mainTrain.getAuthority());
    ui->lcdNumber_4->display(mainTrain.getPassengers());
    ui->lcdNumber_5->display(mainTrain.getCrew());
    ui->lcdNumber_6->display(mainTrain.getTemperature());
    ui->lcdNumber_7->display(mainTrain.getPower());

    //Brakes
    if(mainTrain.getBrakes() == true){
        ui->progressBar->setValue(100);
    }
    else{
        ui->progressBar->setValue(25);
    }

    //Ebrakes
    if(mainTrain.getEbrakes() == true){
        ui->progressBar_2->setValue(100);
    }
    else{
        ui->progressBar_2->setValue(25);
    }

    //Lights
    if (mainTrain.getInteriorLights() == true){
        ui->progressBar_5->setValue(100);
    }
    else{
        ui->progressBar_5->setValue(25);
    }
    if (mainTrain.getExteriorLights() == true){
        ui->progressBar_6->setValue(100);
    }
    else{
        ui->progressBar_6->setValue(25);
    }

    //Doors
    if (mainTrain.getLeftDoor() == true){
        ui->progressBar_3->setValue(100);
    }
    else{
        ui->progressBar_3->setValue(25);
    }
    if (mainTrain.getRightDoor() == true){
        ui->progressBar_4->setValue(100);
    }
    else{
        ui->progressBar_4->setValue(25);
    }

    ui->textBrowser->setText("               Train " + QString::fromStdString(std::to_string((mainTrain.getID()))));

};

//made by accident and if I delete it it gives an unfixable error
void trainUI::on_Temp_Change_actionTriggered(int action){}

void trainUI::on_Temp_Change_sliderMoved(int position)
{
    mainTrain.setTemperature(position);
}


