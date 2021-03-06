#include "ctcwindow.h"
#include "./ui_ctcwindow.h"
#include <QFileDialog>
#include "Block.h"
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include "ScheduleManager.h"
#include "TrainTracker.h"

CTCWindow::CTCWindow(std::vector<WayStruct>* sw_waystructs, WayStruct* hw_waystruct, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CTCWindow)
    , ctc(new CTC(this, sw_waystructs, hw_waystruct))
{
    ui->setupUi(this);
    this->setFixedSize(this->size().width(), this->size().height());

    ctc->update(0);

    std::list<int> switches = ctc->getSwitches();
    for(int s : switches){
        ui->comboBox->addItem("Switch on Block " + QString::number(s), QVariant(s));
    }

    trackMap = new TrackMap(this->ui->graphicsView);
    ui->graphicsView->setScene(trackMap->getScene());
}

CTCWindow::~CTCWindow()
{
    delete trackMap;
}

void CTCWindow::returnWayStructs(){
    emit sendWayStructs(ctc->waysideManager.waysides);
}

void CTCWindow::updateLocalWayStructs(WayStruct wayStr){
    //std::cout << "WAYSTR " << wayStr.id << std::endl;
    //std::cout << "SWITCH ON 12: " << wayStr.sector[11].getSwitchStatus() << std::endl;
    for(WayStruct* w : ctc->waysideManager.waysides){
        if(wayStr.id==w->id){
            //std::cout << "ORIGINAL: " << w->sector[11].getSwitchStatus() << std::endl;
            *w = wayStr;
        }
    }
}

void CTCWindow::update(){
    ctc->update(1);
    trackMap->setOccupiedBranches(ctc->getBranchesWithTrainsPresent());
    updateSelectedBlockStatus();
    updateSelectedSwitchStatus();
}

void CTCWindow::on_button_chooseSchedule_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Open Schedule File");

    std::string s = "Opening Schedule file " + filepath.toStdString() + "\n";
    ctc->loadSchedule(filepath.toStdString());

    s += ctc->displaySchedule();
    ui->textBrowser_schedule->setText(QString::fromStdString(s));
}


void CTCWindow::on_horizontalSlider_mode_sliderMoved(int position)
{
    if(position == 0){
        ctc->setCTCMode(false);
    }else if(position == 1){
        ctc->setCTCMode(true);
    }
}


void CTCWindow::on_lineEdit_selectBlock_returnPressed()
{
    std::string text = ui->lineEdit_selectBlock->text().toStdString();
    int blockId;
    try{
        blockId = std::stoi(text);
        if(ctc->blockExists(blockId)){

            ui->textBrowser_blockPropertiesId->setText(QString::fromStdString(std::to_string(blockId)));

            bool m = ctc->getTrackMaintenence(blockId);
            if(m){
                ui->textBrowser_blockPropertiesMaintenence->setText("Closed");
            }else{
                ui->textBrowser_blockPropertiesMaintenence->setText("Open");
            }

            bool tp = ctc->getBlockHasTrainPresent(blockId);
            if(tp){
                ui->textBrowser_blockPropertiesTrainPresent->setText("Yes");
            }else{
                ui->textBrowser_blockPropertiesTrainPresent->setText("No");
            }

            ui->textBrowser_blockPropertiesThroughput->setText("0");
        }else{
            throw std::logic_error("Block is not valid.");
        }
    }catch(std::exception& e){
        ui->textBrowser_blockPropertiesId->setText("");
        ui->textBrowser_blockPropertiesMaintenence->setText("");
        ui->textBrowser_blockPropertiesTrainPresent->setText("");
        ui->textBrowser_blockPropertiesThroughput->setText("");
        return;
    }

}

void CTCWindow::on_pushButton_openCloseForMaintenecnce_clicked()
{
    std::string text = ui->lineEdit_selectBlock->text().toStdString();
    int blockId;
    try{
        blockId = std::stoi(text);
        if(ctc->getTrackMaintenence(blockId)){
            ctc->setTrackMaintenence(blockId, false);
        }else{
            ctc->setTrackMaintenence(blockId, true);
        }

        bool m = ctc->getTrackMaintenence(blockId);
        if(m){
            ui->textBrowser_blockPropertiesMaintenence->setText("Closed");
        }else{
            ui->textBrowser_blockPropertiesMaintenence->setText("Open");
        }
    }catch(std::exception& e){

    }
}

void CTCWindow::on_pushButton_selectBlockGo_clicked()
{
    on_lineEdit_selectBlock_returnPressed();
}

//SW Dispatch
void CTCWindow::on_pushButton_dispatchTrain_clicked()
{
    dispatchTrain(false);
}

//HW Dispatch
void CTCWindow::on_pushButton_dispatchTrain_2_clicked()
{
    dispatchTrain(true);
}

void CTCWindow::on_comboBox_activated()
{
    std::string label = ui->comboBox->currentText().toStdString();
    int blockId = std::stoi(label.substr(label.size()-2, 2));
    ui->textBrowser_switchId->setText(QString::fromStdString(std::to_string(blockId)));

    bool direction = ctc->getBlockDirection(blockId);
    QString directionText;
    if(direction == false){
        directionText = "Normal";
    }else{
        directionText = "Reverse";
    }
    ui->textBrowser_switchDirection->setText(directionText);
}

void CTCWindow::updateSelectedSwitchStatus(){
    on_comboBox_activated();
}

void CTCWindow::updateSelectedBlockStatus(){
    std::string text = ui->lineEdit_selectBlock->text().toStdString();
    if(!text.empty()){
        on_pushButton_selectBlockGo_clicked();
    }
}


void CTCWindow::on_pushButton_openCloseSwitch_clicked()
{
    std::string label = ui->comboBox->currentText().toStdString();
    int blockId = std::stoi(label.substr(label.size()-2, 2));

    bool direction = ctc->getBlockDirection(blockId);
    if(direction == false){
        ctc->setTrackSwitch(blockId, true);
    }else{
        ctc->setTrackSwitch(blockId, false);
    }
    on_comboBox_activated();
}

void CTCWindow::initializeWaystructs(std::vector<WayStruct>* sw_waystructs, WayStruct* hw_waystruct){
    //std::cout << "INTERMEDIARY: " << &sw_waystructs << std::endl;
    delete ctc;
    ctc = new CTC(this, sw_waystructs, hw_waystruct);
}

void CTCWindow::makeNewTrainEmit(bool hw){
    emit makeNewTrain(!hw, true);
}


void CTCWindow::dispatchTrain(bool hw){
    std::string trainNo;
    std::string destinationStation;
    int destinationTime;
    try{
        trainNo = ui->lineEdit_dispatchTrain->text().toStdString();
        destinationStation = ui->lineEdit_dispatchTo->text().toStdString();
        std::string destinationTimeStr = ui->lineEdit_dispatchTime->text().toStdString();
        destinationTime = std::stoi(destinationTimeStr);
    }catch(std::exception& e){
        std::cout << "CTC: Could not parse dispatch info\n";
        return;
    }
    ctc->dispatchTrain(CTCSchedule(trainNo, destinationStation, destinationTime), hw);
}
