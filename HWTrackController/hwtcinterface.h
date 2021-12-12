#ifndef HWTCINTERFACE_H
#define HWTCINTERFACE_H

#include <QMainWindow>
#include "HWTrackController.h"
#include <QListWidget>
#include <QDebug>
#include <QMessageBox>
#include <QPalette>
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
    void updateHWTrackController();

private slots:
    void on_pushButton_clicked();

    void on_blockList_itemClicked(QListWidgetItem *item);

    void on_pushButton_2_clicked();



    void on_ModeBox_stateChanged(int arg1);

    void on_PLCButton_clicked();

    void setTrack(vector<Block> track);

signals:
    void sendWayStruct(WayStruct *way);

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
    void updateTrainPresentToUI(int);
};
#endif // HWTCINTERFACE_H
