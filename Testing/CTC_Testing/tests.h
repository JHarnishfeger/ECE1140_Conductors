#ifndef TESTS_H
#define TESTS_H
#include <QtTest/QtTest>
#include "WayStruct.h"
#include <vector>

struct WaystructInputs{
    std::vector<WayStruct> sw_waystructs;
    WayStruct hw_waystruct;
};

class Tests : public QObject
{
    Q_OBJECT

public:

    WaystructInputs getBasicTestInput();

private slots:

    void CTCWindowConstructor();

};

#endif // TESTS_H
