#ifndef UNIVERSALTIMER_H
#define UNIVERSALTIMER_H

#include <QObject>
#include <QTimer>

class UniversalTimer
{
public:
    UniversalTimer();
    QTimer *timer;
    QTimer *getTimer();
};

#endif // UNIVERSALTIMER_H
