#include "trackmodel.h"
#include "ui_trackmodel.h"

TrackModel::TrackModel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TrackModel)
{
    greenCreated = 0;
    redCreated = 0;
    trackSent = 0;
    ui->setupUi(this);
}

TrackModel::~TrackModel()
{
    delete ui;
}

void TrackModel::updateFromWayside(vector<Block> waysideBlocks){
    t.updateTrack(waysideBlocks);
    updateDisplay();
}

void TrackModel::TrainInfo(uint8_t currentBlock, int ID, bool line){
    emit TCData(t.handleTCTrainInfo(currentBlock, ID, line), ID);
    emit BeaconData(t.handleBeaconTrainInfo(currentBlock, ID, line), ID);
    updateDisplay();
}

void TrackModel::on_loadTrackButton_clicked()
{
    QString filename = ui->loadTrackTextBox->text();
    std::cout << " before red: " << redCreated << " green: " << greenCreated << std::endl;
    if(filename == "greenLine.txt" && greenCreated == 0){
        std::cout << "loading green" << std::endl;
        t.loadTrack(filename.toStdString());
    }
    if(filename == "redLine.txt" && redCreated == 0){
        std::cout << "loading red" << std::endl;
        t.loadTrack(filename.toStdString());
    }
    if(filename == "greenLine.txt"){
        greenCreated = true;
    }
    if(filename == "redLine.txt"){
        redCreated = true;
    }
    std::cout << "after red: " << redCreated << " green: " << greenCreated << std::endl;
    if(filename == "greenLine.txt"){
        std::cout << "filling green list" << std::endl;
        QStringList lineList;
        lineList.clear();
        std::cout << lineList.isEmpty() << std::endl;
        int lineSize = t.getGreenLine().size();
        for(int i = 0; i < lineSize; i++){
            QString line = QString::fromStdString(t.getGreenLine().at(i)->getLine());
            QString branch = QString::fromStdString(t.getGreenLine().at(i)->getBranch());
            QString id = QString::number(t.getGreenLine().at(i)->getBlockNumber());
            QString blockString = line+","+branch+","+id;
            lineList << blockString;
        }
        ui->selectBlockDropdownBox->clear();
        ui->selectBlockDropdownBox->addItems(lineList);
    }
    if(filename == "redLine.txt"){
        std::cout << "filling red list" << std::endl;
        QStringList lineList;
        lineList.clear();
        std::cout << lineList.isEmpty() << std::endl;
        int lineSize = t.getRedLine().size();
        for(int i = 0; i < lineSize; i++){
            QString line = QString::fromStdString(t.getRedLine().at(i)->getLine());
            QString branch = QString::fromStdString(t.getRedLine().at(i)->getBranch());
            QString id = QString::number(t.getRedLine().at(i)->getBlockNumber());
            QString blockString = line+","+branch+","+id;
            lineList << blockString;
        }
        ui->selectBlockDropdownBox->clear();
        ui->selectBlockDropdownBox->addItems(lineList);
    }
    if(greenCreated && redCreated && !trackSent){
        std::cout << "Sending!" << std::endl;
        emit giveTrack(t.getRedLine(), t.getGreenLine());
        trackSent = 1;
    }
}

void TrackModel::on_trackHeaterOnButton_clicked()
{
    QString currLine = ui->currentBlockTextBoxLine->text();
    QString currId = ui->currentBlockTextBoxId->text();
    Block* currBlock = t.searchBlock(currLine.toStdString(),currId.toInt());
    currBlock->setHeaterStatus(true);
    QString currBlockHeaterStatus = QString::number(currBlock->getHeaterStatus());
    ui->trackHeaterStatusTextBox->setText(currBlockHeaterStatus);
    QString currBlockTemp = QString::number(currBlock->getTemperature());
    ui->trackHeaterTemperatureTextBox->setText(currBlockTemp);
    emit updateWaysides(t.getRedLine(),t.getGreenLine());
}


void TrackModel::on_trackHeaterOffButton_clicked()
{
    QString currLine = ui->currentBlockTextBoxLine->text();
    QString currId = ui->currentBlockTextBoxId->text();
    Block* currBlock = t.searchBlock(currLine.toStdString(),currId.toInt());
    currBlock->setHeaterStatus(false);
    QString currBlockHeaterStatus = QString::number(currBlock->getHeaterStatus());
    ui->trackHeaterStatusTextBox->setText(currBlockHeaterStatus);
    QString currBlockTemp = QString::number(currBlock->getTemperature());
    ui->trackHeaterTemperatureTextBox->setText(currBlockTemp);
    emit updateWaysides(t.getRedLine(),t.getGreenLine());
}




void TrackModel::on_railStatusFixButton_clicked()
{
    QString currLine = ui->currentBlockTextBoxLine->text();
    QString currId = ui->currentBlockTextBoxId->text();
    Block* currBlock = t.searchBlock(currLine.toStdString(),currId.toInt());
    currBlock->setRailStatus(true);
    QString currBlockRailStatus = QString::number(currBlock->getRailStatus());
    ui->railStatusTextBox->setText(currBlockRailStatus);
    emit updateWaysides(t.getRedLine(),t.getGreenLine());
}


void TrackModel::on_railStatusBreakButton_clicked()
{
    QString currLine = ui->currentBlockTextBoxLine->text();
    QString currId = ui->currentBlockTextBoxId->text();
    Block* currBlock = t.searchBlock(currLine.toStdString(),currId.toInt());
    currBlock->setRailStatus(false);
    QString currBlockRailStatus = QString::number(currBlock->getRailStatus());
    ui->railStatusTextBox->setText(currBlockRailStatus);
    emit updateWaysides(t.getRedLine(),t.getGreenLine());
}


void TrackModel::on_circuitStatusFix_clicked()
{
    QString currLine = ui->currentBlockTextBoxLine->text();
    QString currId = ui->currentBlockTextBoxId->text();
    Block* currBlock = t.searchBlock(currLine.toStdString(),currId.toInt());
    currBlock->setCircuitStatus(true);
    QString currBlockCircuitStatus = QString::number(currBlock->getCircuitStatus());
    ui->circuitStatusTextBox->setText(currBlockCircuitStatus);
    emit updateWaysides(t.getRedLine(),t.getGreenLine());
}


void TrackModel::on_circuitStatusBreak_clicked()
{
    QString currLine = ui->currentBlockTextBoxLine->text();
    QString currId = ui->currentBlockTextBoxId->text();
    Block* currBlock = t.searchBlock(currLine.toStdString(),currId.toInt());
    currBlock->setCircuitStatus(false);
    QString currBlockCircuitStatus = QString::number(currBlock->getCircuitStatus());
    ui->circuitStatusTextBox->setText(currBlockCircuitStatus);
    emit updateWaysides(t.getRedLine(),t.getGreenLine());
}


void TrackModel::on_powerStatusFix_clicked()
{
    QString currLine = ui->currentBlockTextBoxLine->text();
    QString currId = ui->currentBlockTextBoxId->text();
    Block* currBlock = t.searchBlock(currLine.toStdString(),currId.toInt());
    currBlock->setPowerStatus(true);
    QString currBlockPowerStatus = QString::number(currBlock->getPowerStatus());
    ui->powerStatusTextBox->setText(currBlockPowerStatus);
    emit updateWaysides(t.getRedLine(),t.getGreenLine());
}


void TrackModel::on_powerStatusBreak_clicked()
{
    QString currLine = ui->currentBlockTextBoxLine->text();
    QString currId = ui->currentBlockTextBoxId->text();
    Block* currBlock = t.searchBlock(currLine.toStdString(),currId.toInt());
    currBlock->setPowerStatus(false);
    QString currBlockPowerStatus = QString::number(currBlock->getPowerStatus());
    ui->powerStatusTextBox->setText(currBlockPowerStatus);
    emit updateWaysides(t.getRedLine(),t.getGreenLine());
}


void TrackModel::on_selectBlockButton_clicked()
{
   QString currBlockString = ui->selectBlockDropdownBox->currentText();
   QStringList currBlockList = currBlockString.split(QLatin1Char(','));
   QString line = currBlockList[0];
   int id = ui->selectBlockDropdownBox->currentIndex();

   Block* searchedBlock = t.searchBlock(line.toStdString(),id);

   //Update searchedBlock current block display
   QString currBlockLine = QString::fromStdString(searchedBlock->getLine());
   QString currBlockBranch = QString::fromStdString(searchedBlock->getBranch());
   QString currBlockId = QString::number(searchedBlock->getBlockNumber());
   ui->currentBlockTextBoxLine->setText(currBlockLine);
   ui->currentBlockTextBoxBranch->setText(currBlockBranch);
   ui->currentBlockTextBoxId->setText(currBlockId);

   //get stats for searchedBlock
   QString currBlockRailStatus = QString::number(searchedBlock->getRailStatus());
   QString currBlockCircuitStatus = QString::number(searchedBlock->getCircuitStatus());
   QString currBlockPowerStatus = QString::number(searchedBlock->getPowerStatus());
   QString currBlockHeaterStatus = QString::number(searchedBlock->getHeaterStatus());
   QString currBlockHeaterTemp = QString::number(searchedBlock->getTemperature());
   QString currBlockType = QString::fromStdString(searchedBlock->getType());
   QString currBlockLength = QString::number(searchedBlock->getLength());
   QString currBlockGrade = QString::number(searchedBlock->getGrade());
   QString currBlockElevation = QString::number(searchedBlock->getElevation());
   QString currBlockSpeedLimit = QString::number(searchedBlock->getSpeedLimit());
   QString currBlockSuggestedSpeed = QString::number(searchedBlock->getSuggestedSpeed());
   QString currBlockStationName = QString::fromStdString(searchedBlock->getStationName());
   QString currBlockAuthority = QString::number(searchedBlock->getAuthority());
   QString currBlockCrossingStatus = QString::number(searchedBlock->getCrossingStatus());
   QString currBlockSwitchStatus = QString::number(searchedBlock->getSwitchStatus());
   QString currBlockTrainPresent = QString::number(searchedBlock->getTrainPresent());
   QString currBlockPassengers = QString::number(searchedBlock->getPassengerCount());
   QString currBlockStationSide = QString::number(searchedBlock->getStationSide());
   QString currBlockTrafficLightStatus = QString::number(searchedBlock->getTrafficLightStatus());
   QString currBlockBeaconPresent = QString::number(searchedBlock->getBeaconPresent());

   //update stats for searchedBlock
   ui->lineTextBox->setText(currBlockLine);
   ui->branchTextBox->setText(currBlockBranch);
   ui->idTextBox->setText(currBlockId);
   ui->railStatusTextBox->setText(currBlockRailStatus);
   ui->circuitStatusTextBox->setText(currBlockCircuitStatus);
   ui->powerStatusTextBox->setText(currBlockPowerStatus);
   ui->trackHeaterStatusTextBox->setText(currBlockHeaterStatus);
   ui->trackHeaterTemperatureTextBox->setText(currBlockHeaterTemp);
   ui->typeTextBox->setText(currBlockType);
   ui->lengthTextBox->setText(currBlockLength);
   ui->gradeTextBox->setText(currBlockGrade);
   ui->elevationTextBox->setText(currBlockElevation);
   ui->speedLimitTextBox->setText(currBlockSpeedLimit);
   ui->suggestedSpeedTextBox->setText(currBlockSuggestedSpeed);
   ui->stationNameTextBox->setText(currBlockStationName);
   ui->authorityTextBox->setText(currBlockAuthority);
   ui->crossingStatusTextBox->setText(currBlockCrossingStatus);
   ui->switchStatusTextBox->setText(currBlockSwitchStatus);
   ui->trainPresentTextBox->setText(currBlockTrainPresent);
   ui->passengersTextBox->setText(currBlockPassengers);
   ui->stationSideTextBox->setText(currBlockStationSide);
   ui->trafficLightStatusTextBox->setText(currBlockTrafficLightStatus);
   ui->beaconPresentTextBox->setText(currBlockBeaconPresent);
}

void TrackModel::updateDisplay(){
    QString currLine = ui->currentBlockTextBoxLine->text();
    QString currId = ui->currentBlockTextBoxId->text();
    if(currLine != "" && currLine != "line" && currLine != " "){
        Block* searchedBlock = t.searchBlock(currLine.toStdString(),currId.toInt()-1);

        //get stats for searchedBlock
        QString currBlockRailStatus = QString::number(searchedBlock->getRailStatus());
        QString currBlockCircuitStatus = QString::number(searchedBlock->getCircuitStatus());
        QString currBlockPowerStatus = QString::number(searchedBlock->getPowerStatus());
        QString currBlockHeaterStatus = QString::number(searchedBlock->getHeaterStatus());
        QString currBlockHeaterTemp = QString::number(searchedBlock->getTemperature());
        QString currBlockType = QString::fromStdString(searchedBlock->getType());
        QString currBlockLength = QString::number(searchedBlock->getLength());
        QString currBlockGrade = QString::number(searchedBlock->getGrade());
        QString currBlockElevation = QString::number(searchedBlock->getElevation());
        QString currBlockSpeedLimit = QString::number(searchedBlock->getSpeedLimit());
        QString currBlockSuggestedSpeed = QString::number(searchedBlock->getSuggestedSpeed());
        QString currBlockStationName = QString::fromStdString(searchedBlock->getStationName());
        QString currBlockAuthority = QString::number(searchedBlock->getAuthority());
        QString currBlockCrossingStatus = QString::number(searchedBlock->getCrossingStatus());
        QString currBlockSwitchStatus = QString::number(searchedBlock->getSwitchStatus());
        QString currBlockTrainPresent = QString::number(searchedBlock->getTrainPresent());
        QString currBlockPassengers = QString::number(searchedBlock->getPassengerCount());
        QString currBlockStationSide = QString::number(searchedBlock->getStationSide());
        QString currBlockTrafficLightStatus = QString::number(searchedBlock->getTrafficLightStatus());
        QString currBlockBeaconPresent = QString::number(searchedBlock->getBeaconPresent());

        //update stats for searchedBlock
        ui->railStatusTextBox->setText(currBlockRailStatus);
        ui->circuitStatusTextBox->setText(currBlockCircuitStatus);
        ui->powerStatusTextBox->setText(currBlockPowerStatus);
        ui->trackHeaterStatusTextBox->setText(currBlockHeaterStatus);
        ui->trackHeaterTemperatureTextBox->setText(currBlockHeaterTemp);
        ui->typeTextBox->setText(currBlockType);
        ui->lengthTextBox->setText(currBlockLength);
        ui->gradeTextBox->setText(currBlockGrade);
        ui->elevationTextBox->setText(currBlockElevation);
        ui->speedLimitTextBox->setText(currBlockSpeedLimit);
        ui->suggestedSpeedTextBox->setText(currBlockSuggestedSpeed);
        ui->stationNameTextBox->setText(currBlockStationName);
        ui->authorityTextBox->setText(currBlockAuthority);
        ui->crossingStatusTextBox->setText(currBlockCrossingStatus);
        ui->switchStatusTextBox->setText(currBlockSwitchStatus);
        ui->trainPresentTextBox->setText(currBlockTrainPresent);
        ui->passengersTextBox->setText(currBlockPassengers);
        ui->stationSideTextBox->setText(currBlockStationSide);
        ui->trafficLightStatusTextBox->setText(currBlockTrafficLightStatus);
        ui->beaconPresentTextBox->setText(currBlockBeaconPresent);
    }
}
