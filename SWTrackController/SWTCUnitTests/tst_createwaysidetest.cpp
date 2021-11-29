#include <QtTest>
#include <QtTest/QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "C:\Users\justi\Desktop\Files\Fall 2021\Train Class\Controller\TrackController\SWTrackController.h"

class createWaysideTest : public QObject
{
    Q_OBJECT

public:
    SWTrackController tc;

private slots:
    void createWayside();
    void designateHWWaysideTest();
    void switchTest();
};

void createWaysideTest::createWayside()
{
    Block a(10,"g","a","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block b(10,"g","a","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block c(10,"g","a","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block d(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block e(10,"g","b","crossing","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block f(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block g(10,"g","b","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block h(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block i(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block j(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block k(10,"g","c","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block l(10,"g","d","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block m(10,"g","d","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block n(10,"r","d","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block o(10,"r","d","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block p(10,"r","e","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block q(10,"r","e","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block r(10,"r","e","crossing","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block s(10,"r","f","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block t(10,"r","f","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);

    vector<Block> green{a,b,c,d,e,f,g,h,i,j,k,l,m};
    vector<Block> red{n,o,p,q,r,s,t};
    tc.initialize(red,green,0);
    tc.createWaysides(3);
    QVERIFY(tc.waysides[0].sector.size()==7);
}

void createWaysideTest::designateHWWaysideTest()
{
    Block a(10,"g","a","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block b(10,"g","a","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block c(10,"g","a","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block d(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block e(10,"g","b","crossing","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block f(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block g(10,"g","b","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block h(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block i(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block j(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block k(10,"g","c","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block l(10,"g","d","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block m(10,"g","d","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block n(10,"r","d","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block o(10,"r","d","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block p(10,"r","e","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block q(10,"r","e","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block r(10,"r","e","crossing","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block s(10,"r","f","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block t(10,"r","f","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);

    vector<Block> green{a,b,c,d,e,f,g,h,i,j,k,l,m};
    vector<Block> red{n,o,p,q,r,s,t};
    tc.initialize(red,green,0);
    tc.createWaysides(3);
    tc.setHardwareWayside(1);
    QVERIFY(tc.hwWay==1);
}

void createWaysideTest::switchTest()
{
    Block a(10,"g","a","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block b(10,"g","a","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block c(10,"g","a","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block d(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block e(10,"g","b","crossing","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block f(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block g(10,"g","b","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block h(10,"g","b","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block i(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block j(10,"g","c","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block k(10,"g","c","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block l(10,"g","d","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block m(10,"g","d","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block n(10,"r","d","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block o(10,"r","d","switch","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block p(10,"r","e","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block q(10,"r","e","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block r(10,"r","e","crossing","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);
    Block s(10,"r","f","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,1);
    Block t(10,"r","f","rail","north","bc",10.0,0,0,1,5,50,45,45,0,0,1,1,1,0,0,0);

    vector<Block> green{a,b,c,d,e,f,g,h,i,j,k,l,m};
    vector<Block> red{n,o,p,q,r,s,t};
    tc.initialize(red,green,0);
    tc.createWaysides(3);
    tc.waysides[1].importPLC("SwitchPLC");
    tc.update();
    QVERIFY(tc.waysides[1].sector[4].getSwitchStatus()==1);
}

QTEST_APPLESS_MAIN(createWaysideTest)

//#include "tst_createwaysidetest.moc"
