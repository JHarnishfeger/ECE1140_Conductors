#include "hwtrainui.h"
#include "ui_hwtrainui.h"

HWTrainUI::HWTrainUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HWTrainUI)
{
    ui->setupUi(this);

   //variables
   portList = QSerialPortInfo::availablePorts();

   for(auto &port : portList){
       QString portName = port.portName();
       ui->ports->addItem(portName);
   }

}

HWTrainUI::~HWTrainUI(){
    delete ui;
}

void HWTrainUI::decodeSignals(){
    trainController.decodeBeacon();
    trainController.decodeTrackCircuit();
}

void HWTrainUI::on_connectButton_clicked(){
    if(portInfo != NULL){
        trainController.serialport.openSerialPort(*portInfo);
    }
    else{
        qDebug() << "NULL";
    }
}

void HWTrainUI::on_commandedSpeed_returnPressed(){
    trainController.setCommandedSpeed(ui->commandedSpeed->text());
}

void HWTrainUI::on_enterButton_clicked(){
    trainController.setKp(ui->KpText->text());
    trainController.setKi(ui->KiText->text());
}

void HWTrainUI::on_ports_currentIndexChanged(int index){
    if(index>= 0 && index < portList.length()){
        portInfo = &(portList[index]);
    }
}

void HWTrainUI::updates(){
    if(trainController.serialport.arduino->isOpen()){
        trainController.writeSerial();
        trainController.readSerial();
    }
    else{
        qDebug() << "Serial Port Not Connected...";
    }
    if(trainController.newBlock()){
        emit getnewTCSignal(trainController.getEncodedBlock());
        decodeSignals();
    }
    ui->lcdNumber->display(QString::number(trainController.getTrainID()));
}



