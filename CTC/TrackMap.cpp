#include "TrackMap.hpp"
#include <QGraphicsTextItem>

TrackMap::TrackMap(QObject* parent){
    //Graphics setup
    scene = new QGraphicsScene(parent);

    background = new QPixmap("track.png"); //Put track.png in the same directory as the executable please! Otherwise it won't load
    backgroundItem = scene->addPixmap(*background);

    int bgW = background->size().width();
    int bgH = background->size().height();

    QBrush greenBrush(Qt::green);
    QBrush yellowBrush(Qt::yellow);
    QPen blackPen(Qt::black);
    blackPen.setWidth(2);

    testRect = new QGraphicsRectItem*[26];
    for(int i = 0; i < 26; i++){
        testRect[i] = scene->addRect(0, 0, 25, 25, blackPen, greenBrush);
    }

    testRect[0]->setPos(QPointF(298,44));
    testRect[1]->setPos(QPointF(353,88));
    testRect[2]->setPos(QPointF(398,32));
    testRect[3]->setPos(QPointF(217,15));
    testRect[4]->setPos(QPointF(126,31));
    testRect[5]->setPos(QPointF(108,133));
    testRect[6]->setPos(QPointF(115,220));
    testRect[7]->setPos(QPointF(128,274));
    testRect[8]->setPos(QPointF(338,287));
    testRect[9]->setPos(QPointF(534,263));
    testRect[10]->setPos(QPointF(557,429));
    testRect[11]->setPos(QPointF(512,651));
    testRect[12]->setPos(QPointF(392,660));
    testRect[13]->setPos(QPointF(220,652));
    testRect[14]->setPos(QPointF(108,686));
    testRect[15]->setPos(QPointF(37,606));
    testRect[16]->setPos(QPointF(148,630));
    testRect[17]->setPos(QPointF(333,638));
    testRect[18]->setPos(QPointF(372,626));
    testRect[19]->setPos(QPointF(486,578));
    testRect[20]->setPos(QPointF(508,464));
    testRect[21]->setPos(QPointF(476,534));
    testRect[22]->setPos(QPointF(316,328));
    testRect[23]->setPos(QPointF(100,312));
    testRect[24]->setPos(QPointF(48,259));
    testRect[25]->setPos(QPointF(70,192));
}


TrackMap::~TrackMap(){
    delete[] testRect;
    delete scene;
    delete background;
    delete backgroundItem;
}

QGraphicsScene* TrackMap::getScene(){
    return scene;
}

int TrackMap::branchStringToIndex(std::string in){
    if(in == "YARD"){
        return 'J' - 'A';
    }
    return in[0] - 'A';
}

void TrackMap::setOccupiedBranches(std::list<std::string> occupiedList){
    QBrush greenBrush(Qt::green);
    QBrush transparentBrush(Qt::transparent);

    for(int i = 0; i < 26; i++){
        testRect[i]->setBrush(transparentBrush);
    }
    for(std::string item : occupiedList){
        int index = branchStringToIndex(item);
        testRect[index]->setBrush(greenBrush);
    }
}
