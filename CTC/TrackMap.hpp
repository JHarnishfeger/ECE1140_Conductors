#ifndef TRACKMAP_HPP
#define TRACKMAP_HPP
#include <QPixmap>
#include <QGraphicsScene>
#include <list>
#include <string>

class TrackMap{

private:

    QGraphicsScene* scene;
    QGraphicsRectItem **testRect;
    QPixmap* background;
    QGraphicsPixmapItem* backgroundItem; //background image

    //Converts a branch name into a branch index
    int branchStringToIndex(std::string in);

public:
    TrackMap(QObject* parent);

    ~TrackMap();

    QGraphicsScene* getScene();

    //Update the graphics to match the list of occupied branches
    void setOccupiedBranches(std::list<std::string> occupiedList);
};

#endif // TRACKMAP_HPP
