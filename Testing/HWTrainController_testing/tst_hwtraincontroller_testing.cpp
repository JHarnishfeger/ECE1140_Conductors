#include <QtTest>
#include <QObject>
#include <iostream>
#include <string>

// add necessary includes here
#include "hwtraincontrollermoc.h"
#include "trainmodelmoc.h"

class HWTrainController_testing : public QObject
{
    Q_OBJECT

public:


private slots:
//    void initTestCase();
//    void cleanupTestCase();
    void receiveData();
    void transmitData();
};

void HWTrainController_testing::receiveData()
{
    HWTrainControllerMoc *controller = new HWTrainControllerMoc;

    trainModelMoc *train = controller->getTrainModelMoc();

    /* test data that will:
        open left doors
        open right doors
        turn on interior lights
        set mode to automatic
        relay 600.00W of power
    */
    QString testInput = "111100000600.00";

    controller->decodeData(testInput);

    QVERIFY(train->getLeftDoor());
    QVERIFY(train->getRightDoor());
    QVERIFY(train->getInteriorLights());

    QCOMPARE(600.00, train->getPower());

}

void HWTrainController_testing::transmitData()
{
    /*String decoding
    char 0            = parity
    char 1-4          = kp
    char 5-8          = ki
    char 9-13        = commandedSpeed
    char 14-18        = currentSpeed
    char 19-23        = suggestedSpeed
    char 24-28        = speedLimit
    char 29-33        = authority
    char 34-38        = stationCode
    */

    HWTrainControllerMoc *controller = new HWTrainControllerMoc;

    controller->setKp("01000");
    controller->setKi("01000");
    controller->setCommandedSpeed("20.00");
    controller->setCurrentSpeed("05.00");
    controller->setSuggestedSpeed("15.00");
    controller->setSpeedLimit("30.00");
    controller->setAuthority("01.00");
    controller->setNextStation("Central");

    QByteArray testTransmitData = controller->encodeData();

    QString testData = "1010000100020.0005.0015.0030.0001.0001100\n";
    QByteArray testByteArray = testData.toUtf8();

    QCOMPARE(testTransmitData, testByteArray);

}


QTEST_APPLESS_MAIN(HWTrainController_testing)

#include "tst_hwtraincontroller_testing.moc"
