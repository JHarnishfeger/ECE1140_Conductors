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
        Block b0('g','a',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
        Block b1('g','a',"crossing",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,true);
        Block b2('g','a',"switch",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
        Block b3('g','a',"rail",2.0,true,5.0,25.0,30.0,'e',32.0,0,1.0,true,false,false,false,true); //Occ
        Block b4('g','a',"switch",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
        Block b5('g','a',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,true);
        Block b6('g','b',"crossing",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
        Block b7('g','b',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,true);
        Block b8('g','b',"switch",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
        Block b9('g','b',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,true);
        vector<Block> tk{b0,b1,b2,b3,b4,b5,b6,b7,b8,b9};
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

void HWTCInterface::on_pushButton_clicked()
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
    QChar id = b.back();
    int idd = -1;
    if(id == '0'){
        idd = 0;
    }else if(id == '1'){
        idd = 1;
    }else if(id == '2'){
        idd = 2;
    }else if(id == '3'){
        idd = 3;
    }else if(id == '4'){
        idd = 4;
    }else if(id == '5'){
        idd = 5;
    }else if(id == '6'){
        idd = 6;
    }else if(id == '7'){
        idd = 7;
    }else if(id == '8'){
        idd = 8;
    }else if(id == '9'){
        idd = 9;
    }
    if(idd != -1){
        updateSwitchToUI(idd);
        blockSelected = idd;
    }
}


void HWTCInterface::on_pushButton_2_clicked()
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

