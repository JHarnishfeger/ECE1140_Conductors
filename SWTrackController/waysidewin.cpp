#include "waysidewin.h"
#include "ui_waysidewin.h"
#include <sstream>

WaysideWin::WaysideWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WaysideWin)
{
    ui->setupUi(this);
}

WaysideWin::~WaysideWin()
{
    delete ui;
}

void WaysideWin::initialize(Wayside &w,int i)
{
    way = &w;
    way->sector = w.sector;
    way->setID(i);
    string title = "Wayside " + std::to_string(way->getID());
    this->setWindowTitle(QString::fromStdString(title));
    fillLists();
}

void WaysideWin::fillLists()
{
    ui->SwitchList->clear();
    ui->CrossingList->clear();
    ui->TrainList->clear();
    ui->BrokenRailList->clear();
    ui->MaintenanceList->clear();
    ui->AlertList->clear();

    QString title;
    string holder;
    for(int i=0;i<way->swich.size();i++)
    {
        title = QString::fromStdString("Block " + std::to_string(way->swich[i].getId()) + " (" + std::to_string(way->swich[i].getSwitch()) + ")");
        ui->SwitchList->addItem(title);
    }

    for(int i=0;i<way->crossing.size();i++)
    {
        title = QString::fromStdString("Block " + std::to_string(way->crossing[i].getId()) + " (" + std::to_string(way->crossing[i].getCrossing()) + ")");
        ui->CrossingList->addItem(title);
    }

    for(int i=0;i<way->getTrackOccupancy().size();i++)
    {
        title = QString::fromStdString("Block " + std::to_string(way->getTrackOccupancy()[i].getId()));
        ui->TrainList->addItem(title);
    }

    for(int i=0;i<way->getBrokenRails().size();i++)
    {
        title = QString::fromStdString("Block " + std::to_string(way->getBrokenRails()[i].getId()));
        ui->BrokenRailList->addItem(title);
    }

    for(int i=0;i<way->getMaintenance().size();i++)
    {
        title = QString::fromStdString("Block " + std::to_string(way->getMaintenance()[i].getId()));
        ui->MaintenanceList->addItem(title);
    }

    for(int i=0;i<way->getAlerts().size();i++)
    {
        ui->AlertList->addItem(QString::fromStdString(way->getAlerts()[i]));
    }
}

void WaysideWin::on_SwitchList_itemClicked(QListWidgetItem *item)
{
    QString qs = item->text();
    string word;
    stringstream str(qs.toStdString());
    str >> word;
    str >> id;
    type = "switch";
}


void WaysideWin::on_CrossingList_itemClicked(QListWidgetItem *item)
{
    QString qs = item->text();
    string word;
    stringstream str(qs.toStdString());
    str >> word;
    str >> id;
    type = "crossing";
}


void WaysideWin::on_SwitchLeft_clicked()
{
    if(type=="switch")
    {
        for(int i=0;i<way->sector.size();i++)
        {
            if(way->sector[i].getId()==id)
            {
                way->sector[i].setSwitch(0);
                break;
            }
        }
    }
    way->updateNoPLC();
    fillLists();
}


void WaysideWin::on_SwitchRight_clicked()
{
    if(type=="switch")
    {
        for(int i=0;i<way->sector.size();i++)
        {
            if(way->sector[i].getId()==id)
            {
                way->sector[i].setSwitch(1);
                break;
            }
        }
    }
    way->updateNoPLC();
    fillLists();
}


void WaysideWin::on_ImportPLC_clicked()
{
    string filename;
    filename = "C:\\Users\\justi\\Desktop\\Files\\Fall 2021\\Train Class\\Controller\\TrackController\\" + ui->PLCFile->text().toStdString();
    way->plc.importPLC(filename);
    std::cout << "RUNNING " << way->plc.getFilename() << std::endl;
    way->detectTrack();
    fillLists();
}


void WaysideWin::on_CrossingOn_clicked()
{
    if(type=="crossing")
    {
        for(int i=0;i<way->sector.size();i++)
        {
            if(way->sector[i].getId()==id)
            {
                way->sector[i].setCrossing(1);
                break;
            }
        }
    }
    way->updateNoPLC();
    fillLists();
}


void WaysideWin::on_CrossingOff_clicked()
{
    if(type=="crossing")
    {
        for(int i=0;i<way->sector.size();i++)
        {
            if(way->sector[i].getId()==id)
            {
                way->sector[i].setCrossing(0);
                break;
            }
        }
    }
    way->updateNoPLC();
    fillLists();
}

