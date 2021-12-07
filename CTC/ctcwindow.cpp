#include "ctcwindow.h"
#include "./ui_ctcwindow.h"
#include <QFileDialog>
#include "Block.h"
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include "ScheduleManager.h"

CTCWindow::CTCWindow(std::vector<WayStruct>* sw_waystructs, WayStruct* hw_waystruct, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CTCWindow)
    , ctc(sw_waystructs, hw_waystruct)
{
    ui->setupUi(this);
    this->setFixedSize(this->size().width(), this->size().height());

    ctc.update(0);

    //TODO: Add switch list to drop-down here
    std::list<int> switches = ctc.getSwitches();
    for(int s : switches){
        ui->comboBox->addItem("Switch on Block " + QString::number(s), QVariant(s));
    }

    trackMap = new TrackMap(this->ui->graphicsView);
    ui->graphicsView->setScene(trackMap->getScene());

    /*
    std::list<std::string> fakeOccupiedList;
    fakeOccupiedList.push_back("F");
    fakeOccupiedList.push_back("I");
    fakeOccupiedList.push_back("Q");
    trackMap->setOccupiedBranches(fakeOccupiedList);
    */
}

CTCWindow::~CTCWindow()
{
    delete trackMap;
}

void CTCWindow::update(){
    ctc.update(0);
    trackMap->setOccupiedBranches(ctc.getBranchesWithTrainsPresent());
}

void CTCWindow::on_button_chooseSchedule_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Open Schedule File");

    std::string s = "Opening Schedule file " + filepath.toStdString() + "\n";
    ctc.loadSchedule(filepath.toStdString());

    s += ctc.displaySchedule();
    ui->textBrowser_schedule->setText(QString::fromStdString(s));
}


void CTCWindow::on_horizontalSlider_mode_sliderMoved(int position)
{
    if(position == 0){
        ctc.setCTCMode(false);
    }else if(position == 1){
        ctc.setCTCMode(true);
    }
}


void CTCWindow::on_lineEdit_selectBlock_returnPressed()
{
    std::string text = ui->lineEdit_selectBlock->text().toStdString();
    int blockId;
    try{
        blockId = std::stoi(text);
        if(ctc.blockExists(blockId)){

            ui->textBrowser_blockPropertiesId->setText(QString::fromStdString(std::to_string(blockId)));

            bool m = ctc.getTrackMaintenence(blockId);
            if(m){
                ui->textBrowser_blockPropertiesMaintenence->setText("Closed");
            }else{
                ui->textBrowser_blockPropertiesMaintenence->setText("Open");
            }

            bool tp = ctc.getBlockHasTrainPresent(blockId);
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
        if(ctc.getTrackMaintenence(blockId)){
            ctc.setTrackMaintenence(blockId, false);
        }else{
            ctc.setTrackMaintenence(blockId, true);
        }

        bool m = ctc.getTrackMaintenence(blockId);
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

void CTCWindow::on_pushButton_dispatchTrain_clicked()
{
    std::string trainNo;
    int destinationBlockId;
    int destinationTime;
    std::cout << "Test\n";
    try{
        trainNo = ui->label_manualDispatchtrain->text().toStdString();
        destinationBlockId = std::stoi(ui->label_manualDispatchTo->text().toStdString());
        destinationTime = std::stoi(ui->label_manualDispatchToTime->text().toStdString());
    }catch(std::exception& e){
        return;
    }
    //string, int, int
    ctc.dispatchTrain(CTCSchedule(trainNo, destinationBlockId, destinationTime));
}


void CTCWindow::on_comboBox_activated()
{
    std::string label = ui->comboBox->currentText().toStdString();
    int blockId = std::stoi(label.substr(label.size()-2, 2));
    ui->textBrowser_switchId->setText(QString::fromStdString(std::to_string(blockId)));

    bool direction = ctc.getBlockDirection(blockId);
    QString directionText;
    if(direction == false){
        directionText = "Normal";
    }else{
        directionText = "Reverse";
    }
    ui->textBrowser_switchDirection->setText(directionText);
}


void CTCWindow::on_pushButton_openCloseSwitch_clicked()
{
    std::string label = ui->comboBox->currentText().toStdString();
    int blockId = std::stoi(label.substr(label.size()-2, 2));

    bool direction = ctc.getBlockDirection(blockId);
    if(direction == false){
        ctc.setTrackSwitch(blockId, true);
    }else{
        ctc.setTrackSwitch(blockId, false);
    }
    on_comboBox_activated();
}

void CTCWindow::initializeWaystructs(std::vector<WayStruct>* sw_waystructs, WayStruct* hw_waystruct){
    ctc = CTC(sw_waystructs, hw_waystruct);
}
