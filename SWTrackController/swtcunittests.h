#ifndef SWTCUNITTESTS_H
#define SWTCUNITTESTS_H

#include <QtTest/QtTest>
#include "SWTrackController.h"

class SWTCUnitTests: public QObject
{
    Q_OBJECT
private slots:
    void createWaysides();
};

#endif // SWTCUNITTESTS_H
