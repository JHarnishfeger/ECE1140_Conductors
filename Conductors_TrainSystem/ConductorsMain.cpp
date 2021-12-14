//#include <QCoreApplication>
#include <QApplication>
#include <QMainWindow>
#include <QListWidgetItem>
#include <QVector>
#include <QWidget>
#include <QTimer>
//using std::byte;
#include "ctcwindow.h"
#include "swtcinterface.h"
#include "trackmodel.h"
#include "hwtcinterface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int interval = 1000;

    CTCWindow cwin;
    cwin.show();
    SWTCInterface swtrack;
    swtrack.show();
    HWTCInterface hwtrack;
    hwtrack.show();
    TrackModel trmodel;
    trmodel.show();
    //Init TrackModel
    //Init TrainModel
    //Init SWTrain
    //Init HWTrain
    //Init MBO
    std::cout << "Here" << std::endl;

    QTimer* clock = new QTimer;
    clock->start(interval);
    //Connect signals/slots

    QObject::connect(&trmodel,SIGNAL(giveTrack(vector<Block*>, vector<Block*>)),&swtrack,SLOT(setTrack(vector<Block*>, vector<Block*>)));
    QObject::connect(&swtrack,SIGNAL(hwSet(vector<Block>)),&hwtrack,SLOT(setTrack(vector<Block>)));
    QObject::connect(&hwtrack,SIGNAL(sendHWWayStruct(WayStruct*)),&swtrack,SLOT(getHWWaystruct(WayStruct*)));
    QObject::connect(&swtrack,SIGNAL(waysidesSet(std::vector<WayStruct>*, WayStruct*)),&cwin,SLOT(initializeWaystructs(std::vector<WayStruct>*, WayStruct*)));


    /* UI SIDE
     *
     * Track Model sends track data to SWTrack
     * SWTrack initializes waysides, designates HWTrack wayside
     * HWTrack responds with HWWaystruct, SWTrack sends all wayside data to CTC
     * CTC receives schedule from MBO
     * --Additional setup--
     *
    */

    return a.exec();
}
