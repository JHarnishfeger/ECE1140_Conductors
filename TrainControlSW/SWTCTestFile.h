#include <QtTest/QtTest>
#include <QCoreApplication>
#include "uiswtraincontroller.h"
#include "..\TrainModel\trainModel.h"

class SWTCTestFile: public QObject
{
    Q_OBJECT
public:
    SWTrainController swtraincontroller;
    trainModel *mainTrain = new trainModel;

private slots:
    void testBeaconDecoder();
    void testTCDecoder();
    void testEbrake();
};


void SWTCTestFile::testBeaconDecoder()
{
    int codedStationCode = 31;
    int codedStationHere = 1;
    int16_t beacon = ((((uint16_t)codedStationCode)<<8)+(((uint16_t)codedStationHere)));

    swtraincontroller.train=mainTrain;
    mainTrain->setBeaconData(beacon);
    swtraincontroller.decodeBeacon();
    QVERIFY(swtraincontroller.getIncommingStation() == "None");
}

void SWTCTestFile::testTCDecoder()
{
    int SpeedLimit, SuggestedSpeed, FBAuthority;
    SpeedLimit = 28;
    SuggestedSpeed = 15;
    FBAuthority=1;

    int32_t tcData = ((((int32_t)SpeedLimit)<<16)+(((int32_t)SuggestedSpeed)<<8)+(((int32_t)FBAuthority)));
    swtraincontroller.train=mainTrain;
    mainTrain->setTCData(tcData);
    swtraincontroller.decodeTrackCircuit();
    QVERIFY(swtraincontroller.getSetpointVelocity()==15);
}

void SWTCTestFile::testEbrake(){
    swtraincontroller.train=mainTrain;
    mainTrain->setEbrakes(1);
    QVERIFY(swtraincontroller.getEmergencyBrake()==true);
}


QTEST_MAIN(SWTCTestFile)
//#include "SWTCTestFile.moc"
