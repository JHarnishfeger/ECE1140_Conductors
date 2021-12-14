#include "mbo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MBO w;
    w.show();
    return a.exec();
}
