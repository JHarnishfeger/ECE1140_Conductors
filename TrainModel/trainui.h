#ifndef TRAINUI_H
#define TRAINUI_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <iostream>
#include <string>
#include "trainmodel.h"
#include "../TrainControlSW/uiswtraincontroller.h"
#include "../HWTrainController/hw_TrainController/hwtrainui.h"

QT_BEGIN_NAMESPACE
namespace Ui { class trainUI; }
QT_END_NAMESPACE

class trainUI : public QMainWindow
{
    Q_OBJECT

public:
    int i=0;

    //main train
    trainModel *mainTrain = new trainModel(HorS);

    //Train Controller UIs
    UISWTrainController s;
    HWTrainUI hw;

    //Timer variables
    QTimer *timer;

    //UI constructor and descructor
    trainUI(QWidget *parent = nullptr, bool HardwareOrSoftware = 1,int ID = 1, bool RedOrGreen= 1);
    ~trainUI();

private slots:

    //Set Functions for display
    QString setBFail();
    QString setEFail();
    QString setSFail();

    //update functoin
    void updateTestUI();

    //onclick functions
    void on_Temp_Change_sliderMoved(int position);

    //Fail buttons
    void on_BrakeFail_clicked();
    void on_EngineFail_clicked();
    void on_SignalFail_clicked();

    //Emergency Brake Button
    void on_pushButton_clicked();

    //Get new track circuit data
    void callTCData(uint8_t currentBlock);

signals:

    void callAgainTCData(uint8_t currentBlock, int trainID);

private:

    //UI
    Ui::trainUI *ui;

    //all variables
    bool brakes;
    bool eBrakes;
    bool brakeFail,engineFail,signalFail;
    bool HorS; // Software is value of 1 // Hardware is value of 0
    bool RorG; // Red is value of 1 // Green is value of 0

};
#endif // TRAINUI_H
