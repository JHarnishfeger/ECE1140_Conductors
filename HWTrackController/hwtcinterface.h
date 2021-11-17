#ifndef HWTCINTERFACE_H
#define HWTCINTERFACE_H

#include <QMainWindow>
#include "HWTrackController.h"
#include <QListWidget>
//#include <QChar>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class HWTCInterface; }
QT_END_NAMESPACE


class HWTCInterface : public QMainWindow
{
    Q_OBJECT

public:
    HWTCInterface(QWidget *parent = nullptr);
    ~HWTCInterface();
    void setHWTrack(vector<Block>);


private slots:
    void on_pushButton_clicked();




    void on_blockList_itemClicked(QListWidgetItem *item);

    void on_pushButton_2_clicked();



    void on_ModeBox_stateChanged(int arg1);

private:
    Ui::HWTCInterface *ui;
    HWTrackController hwtc;
    Wayside_HW *hwWaysidePtr;
    vector<Block> hwTrack;
    bool hwMode;
    bool brokenRailDetected;
    int blockSelected;
    void setHWMode(bool);
    void addBlocksToUI();
    void updateSwitchToUI(int);
    void updateCrossingToUI(int);
};
#endif // HWTCINTERFACE_H
