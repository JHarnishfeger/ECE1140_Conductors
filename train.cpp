#include "train.h"
#include "ui_train.h"

Train::Train(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Train)
{
    ui->setupUi(this);

    //timer set up and updateUI running function
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(updateTestUI()));
    timer ->start(1);
}

Train::~Train()
{
    delete ui;
}

/*Function is for murphy inputs to set
  failures at any point in time.
  */
QString Train::setBFail(bool bt){

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
QString Train::setEFail(bool et){
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
QString Train::setSFail(bool st){
  signalFail = st;
  if (signalFail == true){
    return "FAIL";
  }
  else{
    return "No Failures";
  }
  mainTrain.setFailures(engineFail,signalFail,brakeFail);
}

void Train::on_EngineFail_clicked()
{
    ui->label->setText(setBFail(true));
    ui->label_16->setText("EMERGENCY");
    mainTrain.setFailures(engineFail,signalFail,brakeFail);
}


void Train::on_BrakeFail_clicked()
{
    ui->label_2->setText(setEFail(true));
    ui->label_16->setText("EMERGENCY");
    mainTrain.setFailures(engineFail,signalFail,brakeFail);
}


void Train::on_SignalFail_clicked()
{
    ui->label_3->setText(setSFail(true));
    ui->label_16->setText("EMERGENCY");
    mainTrain.setFailures(engineFail,signalFail,brakeFail);
}

void Train::on_pushButton_clicked()
{
    ui->progressBar_2->setValue(100);
    ui->label_16->setText("BRAKE");
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


void Train::on_lcdNumber_overflow()
{
    ui->lcdNumber->display(-1);
}

void Train::updateTestUI(){

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

}

//////////////////////////////////////////////////////////////////////
//                                                                  //
//      Extra Fucntions from before in case I need them again       //
//                                                                  //
//////////////////////////////////////////////////////////////////////


///*Function is to set the commanded speed
//  of the train through an input of power.
//  */
//void Train::setSpeed(double power){
//  mainTrain->setSpeed(power);
//  actualSpeed = mainTrain->getSpeed();
//  acceleration = mainTrain->getAcceleration();
//
//  ui->lcdNumber_7->display(power);
//  ui->lcdNumber->display(actualSpeed);
//  ui->lcdNumber_2->display(acceleration);
//
//}
//
//void Train::setPassengers(int n){
//    numPassengers = n;
//
//    mainTrain->setPassengers(numPassengers);
//
//}
//
///*Function is to set the authority using
//  an input from the MBO, moving block authority.
//  */
//void Train::setAuthority(int mba){
//  authority = mba;
//  mainTrain->setAuthority(authority);
//  ui->lcdNumber_3->display(authority);
//}
//
//void Train::setTemperature(double temp){
//    temperature = temp;
//    mainTrain->setTemperature(temperature);
//    ui->lcdNumber_6->display(temperature);
//}
//
///*Function is to set the boolean value
//  of the brakes for display on UI.
//  */
//void Train::setBrakes(bool b){
//    brakes = b;
//
//}
//
///*Function is to set the boolean value
//  of the Ebrakes for display on UI.
//  */
//void Train::setEbrakes(bool Eb){
//    eBrakes = Eb;
//}
//
//void Train::setLights(bool in,bool out){
//
//    //setting in main train
//    mainTrain->setLights(interiorLight,exteriorLight);
//}
//
//void Train::setDoors(bool l,bool r){
//
//    mainTrain->setDoors(leftDoor,rightDoor);
//}
