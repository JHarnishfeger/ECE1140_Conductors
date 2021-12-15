#include "universaltimer.h"

UniversalTimer::UniversalTimer()
{
    timer = new QTimer();
    //connect(timer, SIGNAL(timeout()),this,SLOT(timerInst()));
    timer->start(1000);
}

QTimer *UniversalTimer::getTimer(){
    return timer;
}
