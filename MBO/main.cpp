#include "mbo.h"
#include "SMBA.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //SMBA s;
    //s.transferCoords(1,63,90);
    //s.transferCoords(1,64,70);
    //s.transferCoords(2,63,20);

    QApplication a(argc, argv);
    MBO w;
    w.show();
    return a.exec();


}
