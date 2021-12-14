#include "hwtcinterface.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HWTCInterface w;

    vector<int> i0;
    i0.push_back(0);
    i0.push_back(4);

    Block b0("Green","A","RAIL","","DA",i0,1,50,0,1,50,0,0,0,50,1.1,1,1,1,0,0,0,0,0,0,0,0);
    Block b1("Green","A","SWITCH","","DA",i0,2,50,0,1,50,0,0,0,50,1.1,1,1,1,0,0,0,0,1,0,0,0);
    Block b2("Green","A","CROSSING","","DA",i0,3,50,0,1,50,0,0,0,50,1.1,1,1,1,0,0,0,0,0,0,0,0);
    Block b3("Green","B","SWITCH","","DA",i0,4,50,0,1,50,0,0,0,50,1.1,1,1,1,0,0,0,0,0,0,0,0);
    Block b4("Green","B","CROSSING","","DA",i0,5,50,0,1,50,0,0,0,50,1.1,1,1,1,0,0,0,0,0,0,0,0);
    Block b5("Green","B","RAIL","","DA",i0,6,50,0,1,50,0,0,0,50,1.1,1,1,1,0,0,0,0,0,0,0,0);

    vector<Block> tk{b0,b1,b2,b3,b4,b5};
    w.setHWTrack(tk);
    w.show();
    return a.exec();
}
