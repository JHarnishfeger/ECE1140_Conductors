include "traincontrollermainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    TrainControllerMainWindow w;
    w.show();
    return a.exec();
}
