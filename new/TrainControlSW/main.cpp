#include "uiswtraincontroller.h"
#include "testui.h"
#include "SWTrainController.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Testui w;
    w.show();
    return a.exec();
}
