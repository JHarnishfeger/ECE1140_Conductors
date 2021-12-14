#include "hwtcinterface.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HWTCInterface w;
    w.show();
    return a.exec();
}
