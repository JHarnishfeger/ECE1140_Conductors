#include "swtcinterface.h"
#include "ui_swtcinterface.h"

SWTCInterface::SWTCInterface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SWTCInterface)
{
    ui->setupUi(this);
    fillLists();
}

SWTCInterface::~SWTCInterface()
{
    delete ui;
}

void SWTCInterface::fillLists()
{
    ui->SwitchList->clear();
    ui->CrossingList->clear();
    ui->TrainList->clear();
    ui->BrokenRailList->clear();
    ui->MaintenanceList->clear();
    ui->AlertList->clear();

    QString title;
    for(int i=0;i<tc.swich.size();i++)
    {
        title = QString::fromStdString("Line " + std::to_string(tc.swich[i].getLine()) + ", Block " + std::to_string(tc.swich[i].getId()));
        ui->SwitchList->addItem(title);
    }

    for(int i=0;i<tc.crossing.size();i++)
    {
        title = QString::fromStdString("Line " + std::to_string(tc.crossing[i].getLine()) + ", Block " + std::to_string(tc.crossing[i].getId()));
        ui->CrossingList->addItem(title);
    }

    for(int i=0;i<tc.trackOccupancy.size();i++)
    {
        title = QString::fromStdString("Line " + std::to_string(tc.trackOccupancy[i].getLine()) + ", Block " + std::to_string(tc.trackOccupancy[i].getId()));
        ui->TrainList->addItem(title);
    }

    for(int i=0;i<tc.brokenRail.size();i++)
    {
        title = QString::fromStdString("Line " + std::to_string(tc.brokenRail[i].getLine()) + ", Block " + std::to_string(tc.brokenRail[i].getId()));
        ui->BrokenRailList->addItem(title);
    }

    for(int i=0;i<tc.maintenance.size();i++)
    {
        title = QString::fromStdString("Line " + std::to_string(tc.maintenance[i].getLine()) + ", Block " + std::to_string(tc.maintenance[i].getId()));
        ui->MaintenanceList->addItem(title);
    }

    for(int i=0;i<tc.alerts.size();i++)
    {
        ui->AlertList->addItem(QString::fromStdString(tc.alerts[i]));
    }
}

void SWTCInterface::on_CrossingButton_clicked()
{
    for(int i=0;i<tc.waysides.size();i++)
    {
        if(tc.waysides[i].getLine()!=selected.getLine())
            continue;
        for(int j=0;j<tc.waysides[i].sector.size();j++)
        {
            if(tc.waysides[i].sector[j].getId()==selected.getId())
            {
                tc.toggleCrossing(tc.waysides[i].sector[j]);
                i = tc.waysides.size();
                break;
            }
        }
    }
}


void SWTCInterface::on_SwitchButton_clicked()
{
    for(int i=0;i<tc.waysides.size();i++)
    {
        if(tc.waysides[i].getLine()!=selected.getLine())
            continue;
        for(int j=0;j<tc.waysides[i].sector.size();j++)
        {
            if(tc.waysides[i].sector[j].getId()==selected.getId())
            {
                tc.switchTrack(tc.waysides[i].sector[j]);
                i = tc.waysides.size();
                break;
            }
        }
    }
}


void SWTCInterface::on_SwitchList_itemClicked(QListWidgetItem *item)
{
    string title = item->text().toStdString();
    char line = title[5];
    int id = std::stoi(title.substr(14));
    selected.setId(id);
    selected.setLine(line);
    for(int i=0;i<tc.swich.size();i++)
    {
        if(tc.swich[i].getId()==selected.getId()&&tc.swich[i].getLine()==selected.getLine())
        {
            selected.setSwitch(tc.swich[i].getSwitch());
            break;
        }
    }
    ui->TargetName->setText("Selected Item: Switch");
    ui->BlockNumber->setText(QString::fromStdString("Block: " + std::to_string(id)));
    ui->SwitchPosition->setText(QString::fromStdString("Position: " + std::to_string(selected.getSwitch())));
}


void SWTCInterface::on_CrossingList_itemClicked(QListWidgetItem *item)
{
    string title = item->text().toStdString();
    char line = title[5];
    int id = std::stoi(title.substr(14));
    selected.setId(id);
    selected.setLine(line);
    for(int i=0;i<tc.crossing.size();i++)
    {
        if(tc.crossing[i].getId()==selected.getId()&&tc.crossing[i].getLine()==selected.getLine())
        {
            selected.setCrossing(tc.crossing[i].getCrossing());
            break;
        }
    }
    ui->TargetName->setText("Selected Item: Crossing");
    ui->BlockNumber->setText(QString::fromStdString("Block: " + std::to_string(id)));
    ui->SwitchPosition->setText(QString::fromStdString("Position: Not Selected"));
}

