#include "ctcwindow.h"
#include <vector>
#include "WayStruct.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CTCWindow w(nullptr, nullptr);
    w.show();
    return a.exec();
}
