#ifndef TRAINUI_H
#define TRAINUI_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <iostream>
#include <string>
#include "trainmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class trainUI; }
QT_END_NAMESPACE

class trainUI : public QMainWindow
{
    Q_OBJECT

public:

    //main train
    trainModel mainTrain;

    //Timer variables
    QTimer *timer;

    //UI constructor and descructor
    trainUI(QWidget *parent = nullptr);
    ~trainUI();

private slots:

    //set functions
    QString setBFail(bool bf);
    QString setEFail(bool ef);
    QString setSFail(bool sf);

    //update functoin
    void updateTestUI();

    //onclick functions
    void on_Temp_Change_actionTriggered(int action);

    void on_Temp_Change_sliderMoved(int position);

    void on_BrakeFail_clicked();

    void on_EngineFail_clicked();

    void on_SignalFail_clicked();

    void on_pushButton_clicked();

private:

    //UI
    Ui::trainUI *ui;

    //all variables
    bool brakes;
    bool eBrakes;
    bool brakeFail,engineFail,signalFail;

};
#endif // TRAINUI_H
