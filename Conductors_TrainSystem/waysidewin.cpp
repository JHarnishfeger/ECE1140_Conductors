#include "waysidewin.h"
#include "ui_waysidewin.h"
#include <sstream>

WaysideWin::WaysideWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WaysideWin){
    ui->setupUi(this);
}

WaysideWin::~WaysideWin(){
    delete ui;
}

void WaysideWin::updateFromTrack(vector<Block*> red, vector<Block*> green){
    vector<Block> redLine;
    vector<Block> greenLine;
    vector<Block> newSector;
    //Convert lines to vector<Block>
    for(int i=0;i<red.size();i++){
        redLine.push_back(*red[i]);
    }
    for(int i=0;i<green.size();i++){
        greenLine.push_back(*green[i]);
    }

    if(way->getLine()){ //Green
        for(int i=0;i<greenLine.size();i++){
            if(greenLine[i].getBlockNumber()>=way->sector[0].getBlockNumber()&&greenLine[i].getBlockNumber()<=way->sector[way->sector.size()-1].getBlockNumber())
                newSector.push_back((greenLine[i]));
        }
    }
    else{
        for(int i=0;i<redLine.size();i++){
            if(redLine[i].getBlockNumber()>=way->sector[0].getBlockNumber()&&redLine[i].getBlockNumber()<=way->sector[way->sector.size()-1].getBlockNumber())
                newSector.push_back((redLine[i]));
        }
    }

    for(int i=0;i<newSector.size();i++){
        way->sector[i].setTrainPresent(newSector[i].getTrainPresent());
    }
}

void WaysideWin::initialize(Wayside &w,int i){
    way = &w;
    way->sector = w.sector;
    way->setID(i);
    string title = "Wayside " + std::to_string(way->getBlockNumber());
    this->setWindowTitle(QString::fromStdString(title));
    fillLists();
}

void WaysideWin::fillLists(){
    ui->SwitchList->clear();
    ui->CrossingList->clear();
    ui->TrainList->clear();
    ui->BrokenRailList->clear();
    ui->AlertList->clear();

    QString title;
    string holder;
    for(int i=0;i<way->swich.size();i++){
        title = QString::fromStdString("Block " + std::to_string(way->swich[i].getBlockNumber()) + " (" + std::to_string(way->swich[i].getSwitchStatus()) + ")");
        ui->SwitchList->addItem(title);
    }

    for(int i=0;i<way->crossing.size();i++){
        title = QString::fromStdString("Block " + std::to_string(way->crossing[i].getBlockNumber()) + " (" + std::to_string(way->crossing[i].getCrossingStatus()) + ")");
        ui->CrossingList->addItem(title);
    }

    for(int i=0;i<way->getTrackOccupancy().size();i++){
        title = QString::fromStdString("Block " + std::to_string(way->getTrackOccupancy()[i].getBlockNumber()));
        ui->TrainList->addItem(title);
    }

    for(int i=0;i<way->getBrokenRails().size();i++){
        title = QString::fromStdString("Block " + std::to_string(way->getBrokenRails()[i].getBlockNumber()));
        ui->BrokenRailList->addItem(title);
    }

    for(int i=0;i<way->getAlerts().size();i++){
        ui->AlertList->addItem(QString::fromStdString(way->getAlerts()[i]));
    }
}

void WaysideWin::update(){
    way->update();
    fillLists();
}

void WaysideWin::on_SwitchList_itemClicked(QListWidgetItem *item){
    QString qs = item->text();
    string word;
    stringstream str(qs.toStdString());
    str >> word;
    str >> id;
    type = "SWITCH";
}


void WaysideWin::on_CrossingList_itemClicked(QListWidgetItem *item){
    QString qs = item->text();
    string word;
    stringstream str(qs.toStdString());
    str >> word;
    str >> id;
    type = "";
}


void WaysideWin::on_SwitchLeft_clicked(){
    if(type=="SWITCH"&&way->getMode()){
        for(int i=0;i<way->sector.size();i++){
            if(way->sector[i].getBlockNumber()==id){
                way->sector[i].setSwitchStatus(0);
                break;
            }
        }
    }
    way->wayStr.sector = way->sector;
    way->wayStr.auth = way->getAuthority();
    way->wayStr.id = way->getBlockNumber();
    emit updateCTCWayStruct(way->wayStr);
    way->updateNoPLC();
    emit updateFromWayside(way->sector);
    fillLists();
}


void WaysideWin::on_SwitchRight_clicked(){
    if(type=="SWITCH"&&way->getMode()){
        for(int i=0;i<way->sector.size();i++){
            if(way->sector[i].getBlockNumber()==id){
                way->sector[i].setSwitchStatus(1);
                break;
            }
        }
    }
    way->wayStr.sector = way->sector;
    way->wayStr.auth = way->getAuthority();
    way->wayStr.id = way->getBlockNumber();
    emit updateCTCWayStruct(way->wayStr);
    way->updateNoPLC();
    emit updateFromWayside(way->sector);
    fillLists();
}


void WaysideWin::on_ImportPLC_clicked(){
    string filename;
    filename = ui->PLCFile->text().toStdString() + ".txt";
    std::cout << QDir::currentPath().toStdString() << std::endl;
    way->plc.importPLC(filename);
    std::cout << "RUNNING " << way->plc.getFilename() << std::endl;
    way->detectTrack();
    fillLists();
}


void WaysideWin::on_CrossingOn_clicked(){
    if(type==""&&way->getMode()){
        for(int i=0;i<way->sector.size();i++){
            if(way->sector[i].getBlockNumber()==id){
                way->sector[i].setCrossingStatus(1);
                break;
            }
        }
    }
    way->wayStr.sector = way->sector;
    way->wayStr.auth = way->getAuthority();
    way->wayStr.id = way->getBlockNumber();
    emit updateCTCWayStruct(way->wayStr);
    way->updateNoPLC();
    emit updateFromWayside(way->sector);
    fillLists();
}


void WaysideWin::on_CrossingOff_clicked(){
    if(type==""&&way->getMode()){
        for(int i=0;i<way->sector.size();i++){
            if(way->sector[i].getBlockNumber()==id){
                way->sector[i].setCrossingStatus(0);
                break;
            }
        }
    }
    way->wayStr.sector = way->sector;
    way->wayStr.auth = way->getAuthority();
    way->wayStr.id = way->getBlockNumber();
    emit updateCTCWayStruct(way->wayStr);
    way->updateNoPLC();
    emit updateFromWayside(way->sector);
    fillLists();
}

