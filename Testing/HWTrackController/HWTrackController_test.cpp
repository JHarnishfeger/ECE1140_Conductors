#include <QtTest>
#include <QCoreApplication>

#include "HWTrackController.h"

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private:
    HWTrackController HWTrackCon;
    Wayside_HW *wayPtr;

private slots:
    void testIniHW();
    void testSetSuggestedSpeed();
    void testGetSwitchPosition();
};

test::test()
{
        Block b0(10,"g","a","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,0,0,0,0);
        Block b1(10,"g","a","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,0,0,1,0);
        Block b2(10,"g","a","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,0,0,0,0);
        Block b3(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,0,0,1,0);
        Block b4(10,"g","b","crossing","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,0,0,0,0);     
        vector<Block> tk{b0,b1,b2,b3,b4};
        HWTrackCon.initializeHW(tk);
        wayPtr = HWTrackCon.getWayside();
}

test::~test()
{

}


void test::testIniHW()
{
    int size = wayPtr->getTrackSize();
    QVERIFY(!(size == 0));
    QVERIFY(size == 5);
    QVERIFY(wayPtr->getLine() == "g");
}


void test::testSetSuggestedSpeed(){
    QVERIFY(wayPtr->getSuggestedSpeed()==0);
    wayPtr->setSuggestedSpeed(12.1);
    QVERIFY(!(wayPtr->getSuggestedSpeed()==0));
    QVERIFY(wayPtr->getSuggestedSpeed()==12.1);

}

void test::testGetSwitchPosition(){
    vector<bool> po = wayPtr->getBlockSwitchPosition();
    QVERIFY(po[0] == 0);
    QVERIFY(po[1] == 1);
    QVERIFY(po[2] == 0);
    QVERIFY(po[3] == 1);
    QVERIFY(po[4] == 0);
}



QTEST_MAIN(test)

#include "tst_test.moc"
