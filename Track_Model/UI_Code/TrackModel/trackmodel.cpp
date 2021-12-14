#include "trackmodel.h"
#include "ui_trackmodel.h"

TrackModel::TrackModel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TrackModel)
{
    ui->setupUi(this);
}

TrackModel::~TrackModel()
{
    delete ui;
}


void TrackModel::on_loadTrackButton_clicked()
{
    QString filename = ui->loadTrackTextBox->text();
    cout << "clicked" << endl;
    t.loadTrack(filename.toStdString());
    int lineSize = t.getGreenLine().size();
    QStringList lineList;
    for(int i = 0; i < lineSize; i++){
        QString line = QString::fromStdString(t.getGreenLine().at(i)->getLine());
        QString branch = QString::fromStdString(t.getGreenLine().at(i)->getBranch());
        QString id = QString::number(t.getGreenLine().at(i)->getBlockNumber());
        QString blockString = line+","+branch+","+id;
        lineList << blockString;
    }
    ui->selectBlockDropdownBox->addItems(lineList);
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
}




void TrackModel::on_railStatusFixButton_clicked()
{
    QString currLine = ui->currentBlockTextBoxLine->text();
    QString currId = ui->currentBlockTextBoxId->text();
    Block* currBlock = t.searchBlock(currLine.toStdString(),currId.toInt());
    currBlock->setRailStatus(true);
    QString currBlockRailStatus = QString::number(currBlock->getRailStatus());
    ui->railStatusTextBox->setText(currBlockRailStatus);
}


void TrackModel::on_railStatusBreakButton_clicked()
{
    QString currLine = ui->currentBlockTextBoxLine->text();
    QString currId = ui->currentBlockTextBoxId->text();
    Block* currBlock = t.searchBlock(currLine.toStdString(),currId.toInt());
    currBlock->setRailStatus(false);
    QString currBlockRailStatus = QString::number(currBlock->getRailStatus());
    ui->railStatusTextBox->setText(currBlockRailStatus);
}


void TrackModel::on_circuitStatusFix_clicked()
{
    QString currLine = ui->currentBlockTextBoxLine->text();
    QString currId = ui->currentBlockTextBoxId->text();
    Block* currBlock = t.searchBlock(currLine.toStdString(),currId.toInt());
    currBlock->setCircuitStatus(true);
    QString currBlockCircuitStatus = QString::number(currBlock->getCircuitStatus());
    ui->circuitStatusTextBox->setText(currBlockCircuitStatus);
}


void TrackModel::on_circuitStatusBreak_clicked()
{
    QString currLine = ui->currentBlockTextBoxLine->text();
    QString currId = ui->currentBlockTextBoxId->text();
    Block* currBlock = t.searchBlock(currLine.toStdString(),currId.toInt());
    currBlock->setCircuitStatus(false);
    QString currBlockCircuitStatus = QString::number(currBlock->getCircuitStatus());
    ui->circuitStatusTextBox->setText(currBlockCircuitStatus);
}


void TrackModel::on_powerStatusFix_clicked()
{
    QString currLine = ui->currentBlockTextBoxLine->text();
    QString currId = ui->currentBlockTextBoxId->text();
    Block* currBlock = t.searchBlock(currLine.toStdString(),currId.toInt());
    currBlock->setPowerStatus(true);
    QString currBlockPowerStatus = QString::number(currBlock->getPowerStatus());
    ui->powerStatusTextBox->setText(currBlockPowerStatus);
}


void TrackModel::on_powerStatusBreak_clicked()
{
    QString currLine = ui->currentBlockTextBoxLine->text();
    QString currId = ui->currentBlockTextBoxId->text();
    Block* currBlock = t.searchBlock(currLine.toStdString(),currId.toInt());
    currBlock->setPowerStatus(false);
    QString currBlockPowerStatus = QString::number(currBlock->getPowerStatus());
    ui->powerStatusTextBox->setText(currBlockPowerStatus);
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

