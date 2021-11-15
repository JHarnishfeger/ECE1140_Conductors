#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QGraphicsTextItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size().width(), this->size().height());

    std::vector<Block> fakeTrack; //Dummy track for CTC to use
    for(int i = 0; i < 100; i++){
        fakeTrack.push_back(Block());
        if(i % 20 == 0 && i != 0){
            fakeTrack[i].setType("switch");
        }
    }
    ctc.update(fakeTrack, 0.f);

    std::vector<Block> switches = ctc.getSwitches();
    for(int i = 0; i < switches.size(); i++){
        ui->comboBox->addItem("Switch " + QString::fromStdString(std::to_string(i)), QVariant(switches[i].getId()));
    }
    on_comboBox_activated(0); //Fill out the switch fields when the window opens

    //Graphics setup
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush redBrush(Qt::red);
    QBrush yellowBrush(Qt::yellow);
    QPen blackPen(Qt::black);
    blackPen.setWidth(2);

    testRect = new QGraphicsRectItem*[100];
    for(int i = 0; i < 50; i++){
        if(i % 15 == 0 && i != 0){
            testRect[i] = scene->addRect(-250+10*i, 0, 10, 10, blackPen, yellowBrush);
        }else{
            testRect[i] = scene->addRect(-250+10*i, 0, 10, 10, blackPen, redBrush);
        }
    }
    testRect[50] = scene->addRect(-100, 10, 10, 10, blackPen, redBrush);
    for(int i = 51; i < 100; i++){
        if(i % 15 == 0 && i != 0){
            testRect[i] = scene->addRect(-250+10*(i-51), 20, 10, 10, blackPen, yellowBrush);
        }else{
            testRect[i] = scene->addRect(-250+10*(i-51), 20, 10, 10, blackPen, redBrush);
        }
    }
    testText = scene->addText("This view will display a graphical map of the track.\nEach box represents a track block.\nColors will represent various block states.");
    testText->setPos(-250, -75);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete[] testRect;
    delete testText;
}

void MainWindow::on_button_chooseSchedule_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Open Schedule File");

    std::string s = "Opening Schedule file " + filepath.toStdString() + "\n";
    for(int i = 0; i < 10; i++){
        ctc.addSchedule(CTCSchedule(i, i, (double)i));
    }
    s += ctc.displaySchedule();
    ui->textBrowser_schedule->setText(QString::fromStdString(s));
}


void MainWindow::on_horizontalSlider_mode_sliderMoved(int position)
{
    if(position == 0){
        ctc.setCTCMode(false);
    }else if(position == 1){
        ctc.setCTCMode(true);
    }
}


void MainWindow::on_lineEdit_selectBlock_returnPressed()
{
    std::string text = ui->lineEdit_selectBlock->text().toStdString();
    int blockId;
    try{
        blockId = std::stoi(text);

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
    }catch(std::exception e){
        ui->textBrowser_blockPropertiesId->setText("");
        ui->textBrowser_blockPropertiesMaintenence->setText("");
        ui->textBrowser_blockPropertiesTrainPresent->setText("");
        ui->textBrowser_blockPropertiesThroughput->setText("");
        return;
    }

}

void MainWindow::on_pushButton_openCloseForMaintenecnce_clicked()
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
    }catch(std::exception){

    }
}

void MainWindow::on_pushButton_selectBlockGo_clicked()
{
    on_lineEdit_selectBlock_returnPressed();
}

void MainWindow::on_pushButton_dispatchTrain_clicked()
{
    int trainNo;
    int destinationBlockId;
    double destinationTime;

    try{
        trainNo = std::stoi(ui->label_manualDispatchtrain->text().toStdString());
        destinationBlockId = std::stoi(ui->label_manualDispatchTo->text().toStdString());
        destinationTime = std::stod(ui->label_manualDispatchToTime->text().toStdString());
    }catch(std::exception){
        return;
    }
    ctc.dispatchTrain(CTCSchedule(trainNo, destinationBlockId, destinationTime));
}


void MainWindow::on_comboBox_activated(int index)
{
    int blockId = ui->comboBox->currentData().Int;
    ui->textBrowser_switchId->setText(QString::fromStdString(std::to_string(blockId)));

    char direction = ctc.getBlockDirection(blockId);
    QString directionText;
    if(direction == 'e'){
        directionText = "Normal";
    }else{
        directionText = "Reverse";
    }
    ui->textBrowser_switchDirection->setText(directionText);
}


void MainWindow::on_pushButton_openCloseSwitch_clicked()
{
    int blockId = ui->comboBox->currentData().Int;
    char direction = ctc.getBlockDirection(blockId);
    if(direction == 'e'){
        ctc.setTrackSwitch(blockId, 'w');
    }else{
        ctc.setTrackSwitch(blockId, 'e');
    }
    on_comboBox_activated(ui->comboBox->currentIndex());
}

