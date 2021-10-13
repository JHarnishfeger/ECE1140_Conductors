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

 /*
    //MAY IMPLIMENT THIS INTO SIGNAL HANDLER NEED TO CHECK IF VALID
    QApplication a(argc, argv);
    UISWTrainController *w = new UISWTrainController();
    SWTrainController *swtc = new SWTrainController();
    w->swtraincontroller = swtc;
    w->show();
    return a.exec();
*/
}
