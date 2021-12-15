#include "hwtcinterface.h"
#include "ui_hwtcinterface.h"

HWTCInterface::HWTCInterface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HWTCInterface)
{
    ui->setupUi(this);

    hwMode = 1; //Set to manual mode
    ui->ModeBox->setChecked(true);
    brokenRailDetected = 0;
    HWready = 0;

}

HWTCInterface::~HWTCInterface()
{
    delete ui;
}

void HWTCInterface::getCTCWayStruct(std::list<WayStruct*> waystrs){
    for(WayStruct* w : waystrs){
        if(w->id==hwWaysidePtr->wayStr.id)
            hwWaysidePtr->wayStr = *w;
    }
}

void HWTCInterface::setHWTrack(vector<Block> tk){
    hwTrack = tk;
    hwtc.initializeHW(hwTrack);
    HWready = 1;
    hwWaysidePtr = hwtc.getWayside();
    bool hwConnect = hwWaysidePtr->ifHWConnected();
    if(hwConnect){
        ui->HWConnection->setChecked(true);
    }else{
        ui->HWConnection->setChecked(false);
    }

    addBlocksToUI();
    hwtc.setControlMode(hwMode);
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

void HWTCInterface::updateTrainPresentToUI(int id){
    vector<bool> trainPre = hwWaysidePtr->getBlockOccupancy();
    if(trainPre[id] == 1){
        ui -> TrainPresentBox->setChecked(true);
    }else{
        ui -> TrainPresentBox->setChecked(false);
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

    if(hwWaysidePtr->getMode() == 0){
        ui->ModeBox->setChecked(false);
    }else if(hwWaysidePtr->getMode() == 1){
        ui->ModeBox->setChecked(true);
    }

}

void HWTCInterface::on_blockList_itemClicked(QListWidgetItem *item)
{
    QString b = item->text();
    b.remove(0,6);
    int idd = b.toInt();
    idd--;
    vector<bool> ifSwitch = hwWaysidePtr->getIfBlockHasSwitch();
    vector<bool> ifCross = hwWaysidePtr->getIfBlockHasCrossing();

    if(ifSwitch[idd] == 0){
        ui->LeftBox->setDisabled(true);
        ui->RightBox->setDisabled(true);
    }else{
        ui->LeftBox->setDisabled(false);
        ui->RightBox->setDisabled(false);
    }

    if(ifCross[idd] == 0){
        ui->CrossingBox->setDisabled(true);
    }else{
        ui->CrossingBox->setDisabled(false);
    }

    updateSwitchToUI(idd);
    updateCrossingToUI(idd);
    updateTrainPresentToUI(idd);
    blockSelected = idd;
}


void HWTCInterface::on_pushButton_2_clicked() //Update button
{
    int successfulReveive = 0;
    hwtc.selectBlock_Manual(blockSelected+1);
    successfulReveive = hwWaysidePtr->receiveFromArduino();
    if(successfulReveive == 1){
        updateSwitchToUI(blockSelected);
        updateCrossingToUI(blockSelected);
    }else if(successfulReveive == 0){
        QMessageBox::about(this, "Update Failed", "Update Failed. Please click UPDATE only while pressing the physical update button. ");
    }else if(successfulReveive == -1){
        QMessageBox::about(this, "Update Failed", "Update Failed -- Train Present on the Block! ");
    }
    emit updateToHWTrack(hwWaysidePtr->sector);
    emit updateCTCWayStruct(hwWaysidePtr->wayStr);
}




void HWTCInterface::on_ModeBox_stateChanged(int arg1)
{
    if(arg1 == 0){
        ui->pushButton_2->setDisabled(true);
    }else{
        ui->pushButton_2->setDisabled(false);
    }
}


void HWTCInterface::on_PLCButton_clicked()
{
    /*
    vector<bool> sw = hwWaysidePtr->getBlockSwitchPosition();
    for(int i = 0; i < sw.size(); i++){
        cout << sw[i] << " ";
    }
    cout << endl;
    */
    string filename;
    filename = ui->PLCtextBox->text().toStdString() + ".txt";
    hwWaysidePtr->hwPLC.importPLC(filename);
    cout << "Running " << hwWaysidePtr->hwPLC.getFilename() << endl;
    hwWaysidePtr->detectTrack();
    /*
    sw = hwWaysidePtr->getBlockSwitchPosition();
    for(int i = 0; i < sw.size(); i++){
        cout << sw[i] << " ";
    }
    cout << endl;
    */
    emit updateCTCWayStruct(hwWaysidePtr->wayStr);
}

void HWTCInterface::updateHWTrackController(){
    hwtc.updateHWWayside();
}

void HWTCInterface::setTrack(vector<Block> track){
    setHWTrack(track);
    emit sendHWWayStruct(hwtc.getWayStructHW());
}

void HWTCInterface::updateFromHWTrack(vector<Block*> red, vector<Block*> green){
    vector<Block> track;
    if(hwWaysidePtr->getLine() == "r"){
        for(int i = 0; i < hwWaysidePtr->getTrackSize(); i++){
            track.push_back(*red[i]);
        }
    }else{
        for(int i = 0; i < hwWaysidePtr->getTrackSize(); i++){
            track.push_back(*green[i]);
        }
    }
    hwWaysidePtr->updateTrack(track);
    emit updateCTCWayStruct(hwWaysidePtr->wayStr);
    /*std::cout << "Track Before: " << std::endl;
    for(int i=0;i<track.size();i++)
        std::cout << track[i].getSwitchStatus() << " ";
    std::cout << std::endl;
    for(int i=0;i<hwWaysidePtr->sector.size();i++)
        std::cout << hwWaysidePtr->sector[i].getSwitchStatus() << " ";
    std::cout << std::endl;*/
    //emit updateToHWTrack(hwWaysidePtr->sector);
    /*std::cout << "Track Before: " << std::endl;
    for(int i=0;i<track.size();i++)
        std::cout << track[i].getSwitchStatus() << " ";
    std::cout << std::endl;
    for(int i=0;i<hwWaysidePtr->sector.size();i++)
        std::cout << hwWaysidePtr->sector[i].getSwitchStatus() << " ";*/
    //std::cout << std::endl;
}

void HWTCInterface::runHWPLC(){
    //std::cout << HWready << std::endl;
    if(HWready){
        emit pingForWayStruct();
        if(hwWaysidePtr->hwPLC.getFilename()!=""){
            hwWaysidePtr->detectTrack();
        }
        emit updateToHWTrack(hwWaysidePtr->sector);
        hwWaysidePtr->updateToWayStr();
        //std::cout << "BEFORE: " << hwWaysidePtr->wayStr.sector[11].getSwitchStatus() << std::endl;
        //std::cout << "Its: " << hwWaysidePtr->wayStr.id << std::endl;
        emit updateCTCWayStruct(hwWaysidePtr->wayStr);
    }
}
