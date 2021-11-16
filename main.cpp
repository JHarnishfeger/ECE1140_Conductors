#include "trainui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    trainUI w;
    w.mainTrain.setDoors(false,true);
    w.mainTrain.setCrew(20);
    w.mainTrain.setCars(25);
    w.mainTrain.setID(5);
    w.show();
    return a.exec();
}
