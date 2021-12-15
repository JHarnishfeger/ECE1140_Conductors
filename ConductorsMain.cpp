//#include <QCoreApplication>
#include <QApplication>
#include <QMainWindow>
#include <QListWidgetItem>
#include <QVector>
#include <QWidget>
#include <QTimer>
//using std::byte;
#include "Clock.h"
#include "ctcwindow.h"
#include "swtcinterface.h"
#include "trackmodel.h"
#include "hwtcinterface.h"
#include "TrainModel/trainmaker.h"
#include "MBO/SMBA.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int interval = 1000;

    std::cout << QDir::currentPath().toStdString() << std::endl;

//    CTCWindow cwin;
//    cwin.show();
    SWTCInterface swtrack;
    swtrack.show();
    HWTCInterface hwtrack;
    hwtrack.show();
    TrackModel trmodel;
    trmodel.show();
    trainMaker tnmodel;
    SMBA mba;

    //Init MBO
    //std::cout << "Here" << std::endl;

    Clock sysTimer;
    //Connect signals/slots

    QObject::connect(&sysTimer,SIGNAL(tick()),&swtrack,SLOT(update()));
    QObject::connect(&sysTimer,SIGNAL(tick()),&hwtrack,SLOT(runHWPLC()));
    QObject::connect(&sysTimer,SIGNAL(tick()),&tnmodel,SLOT(update()));
    //QObject::connect(&sysTimer,SIGNAL(tick()),&cwin,SLOT(update()));
    QObject::connect(&trmodel,SIGNAL(updateWaysides(vector<Block*>,vector<Block*>)),&swtrack,SLOT(updateFromTrack(vector<Block*>,vector<Block*>)));
    QObject::connect(&trmodel,SIGNAL(updateWaysides(vector<Block*>,vector<Block*>)),&hwtrack,SLOT(updateFromHWTrack(vector<Block*>,vector<Block*>)));
    QObject::connect(&swtrack,SIGNAL(updateToTrack(vector<Block>)),&trmodel,SLOT(updateFromWayside(vector<Block>)));
    QObject::connect(&hwtrack,SIGNAL(updateToHWTrack(vector<Block>)),&trmodel,SLOT(updateFromWayside(vector<Block>)));
    QObject::connect(&trmodel,SIGNAL(giveTrack(vector<Block*>,vector<Block*>)),&swtrack,SLOT(setTrack(vector<Block*>,vector<Block*>)));
    QObject::connect(&swtrack,SIGNAL(hwSet(vector<Block>)),&hwtrack,SLOT(setTrack(vector<Block>)));
    QObject::connect(&hwtrack,SIGNAL(sendHWWayStruct(WayStruct*)),&swtrack,SLOT(getHWWaystruct(WayStruct*)));
    //QObject::connect(&swtrack,SIGNAL(waysidesSet(std::vector<WayStruct>*,WayStruct*)),&cwin,SLOT(initializeWaystructs(std::vector<WayStruct>*,WayStruct*)));
    QObject::connect(&tnmodel,SIGNAL(TrainInfo(uint8_t,int,bool)),&trmodel,SLOT(TrainInfo(uint8_t,int,bool)));
    QObject::connect(&trmodel,SIGNAL(TCData(uint64_t,int)),&tnmodel,SLOT(TCData(uint64_t,int)));
    QObject::connect(&trmodel,SIGNAL(BeaconData(uint16_t,int)),&tnmodel,SLOT(BeaconData(uint16_t,int)));
    QObject::connect(&mba,SIGNAL(setAuth(double,int)),&tnmodel,SLOT(setAuth(double,int)));
    QObject::connect(&tnmodel,SIGNAL(transferCoords(int,int,double,double)),&mba,SLOT(transferCoords(int,int,double,double)));

    tnmodel.newTrain(1,1);
    //tnmodel.newTrain(0,0);

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
