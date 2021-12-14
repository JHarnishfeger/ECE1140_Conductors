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
    Block b0(10,"g","a","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
        Block b1(10,"g","a","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,0);
        Block b2(10,"g","a","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
        Block b3(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,0);
        Block b4(10,"g","b","crossing","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
        Block b5(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,0);
        Block b6(10,"g","b","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
        Block b7(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,0);
        Block b8(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
        Block b9(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,1);
        Block b10(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,1);
        Block b11(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,1);
        Block b12(10,"g","a","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,0);
        Block b13(10,"g","a","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
        Block b14(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,0);
        Block b15(10,"g","b","crossing","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
        Block b16(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,0);
        Block b17(10,"g","b","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
        Block b18(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,0);
        Block b19(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
        Block b20(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,1);
        Block b21(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,1);
        Block b22(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,1);
        Block b23(10,"g","a","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,0);
        Block b24(10,"g","a","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
        Block b25(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,0);
        Block b26(10,"g","b","crossing","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
        Block b27(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,0);
        Block b28(10,"g","b","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
        Block b29(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,0);
        Block b30(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
        Block b31(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,1);
        Block b32(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,1);
        //Block b33(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,1,0,1);
        vector<Block> tk{b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16,b17,b18,
                    b19,b20,b21,b22,b23,b24,b25,b26,b27,b28,b29,b30,b31,b32};
        setHWTrack(tk);
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

HWTCInterface::~HWTCInterface()
{
    delete ui;
}

void HWTCInterface::setHWTrack(vector<Block> tk){
    hwTrack = tk;
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

