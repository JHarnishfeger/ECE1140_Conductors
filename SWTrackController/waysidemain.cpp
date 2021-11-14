#include "waysidewin.h"

#include <QApplication>

int winmain(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WaysideWin w;
    w.show();
    return a.exec();
}
