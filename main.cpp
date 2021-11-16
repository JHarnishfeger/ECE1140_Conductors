#include "swtcinterface.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SWTCInterface w;
    w.show();
    return a.exec();
}
