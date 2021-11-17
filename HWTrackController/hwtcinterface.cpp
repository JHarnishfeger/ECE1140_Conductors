#include "hwtcinterface.h"
#include "ui_hwtcinterface.h"

HWTCInterface::HWTCInterface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HWTCInterface)
{
    ui->setupUi(this);

    hwMode = 1;
    ui->ModeBox->setChecked(true);
    brokenRailDetected = 0;



        //setHWTrack(tk);



}

HWTCInterface::~HWTCInterface()
{
    delete ui;
}

void HWTCInterface::setHWTrack(vector<Block> tk){
    hwTrack = tk;
    hwtc.initializeHW(hwTrack);
    hwWaysidePtr = hwtc.getWayside();
    bool hwConnect = hwWaysidePtr->ifHWConnected();
    if(hwConnect){
        ui->HWConnection->setChecked(true);
    }else{
        ui->HWConnection->setChecked(false);
    }

    addBlocksToUI();
}

void HWTCInterface::setHWMode(bool m){
    hwMode = m;
    hwtc.setControlMode(m);
}

void HWTCInterface::addBlocksToUI(){
    int tracksz;
    tracksz = hwWaysidePtr->getTrackSize();
    vector<int> ids = hwWaysidePtr->getId();

    for(int i = 0; i < tracksz; i++){
        int id = ids[i];
        QString bid = "Block " + QString::number(id);

        //QListWidgetItem *item = new QListWidgetItem(s);
        ui->blockList->addItem(bid);
    }

}

void HWTCInterface::updateSwitchToUI(int id){
    vector<bool> switchPo = hwWaysidePtr->getBlockSwitchPosition();
    if(switchPo[id] == 0){
        ui->LeftBox->setChecked(true);
        ui->RightBox->setChecked(false);
    }else{
        ui->LeftBox->setChecked(false);
        ui->RightBox->setChecked(true);
    }
}

void HWTCInterface::updateCrossingToUI(int id){
    vector<bool> croState = hwWaysidePtr->getBlockCrossingState();
    if(croState[id] == 1){
        ui->CrossingBox->setChecked(true);
    }else{
        ui->CrossingBox->setChecked(false);
    }
}

void HWTCInterface::on_pushButton_clicked() // Mode button
{
    bool mm = 0;
    if(hwMode == 0){
        mm = 1;
    }else if(hwMode == 1){
        mm = 0;
    }
    setHWMode(mm);

    if(hwMode == 0){
        ui->ModeBox->setChecked(false);
    }else if(hwMode == 1){
        ui->ModeBox->setChecked(true);
    }

}




void HWTCInterface::on_blockList_itemClicked(QListWidgetItem *item)
{
    QString b = item->text();
    b.remove(0,6);
    //qDebug() << b;
    //QChar id = b.back();
    int idd = b.toInt();

        updateSwitchToUI(idd);
        updateCrossingToUI(idd);
        blockSelected = idd;
}


void HWTCInterface::on_pushButton_2_clicked() //Update button
{
    hwtc.selectBlock_Manual(blockSelected);
    hwWaysidePtr->receiveFromArduino();
    updateSwitchToUI(blockSelected);
    updateCrossingToUI(blockSelected);
}




void HWTCInterface::on_ModeBox_stateChanged(int arg1)
{
    if(arg1 == 0){
        ui->pushButton_2->hide();
    }else{
        ui->pushButton_2->show();
    }
}

