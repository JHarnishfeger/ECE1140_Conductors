#ifndef SWTCINTERFACE_H
#define SWTCINTERFACE_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QVector>
#include <vector>
#include <array>
using std::vector;
#include "SWTrackController.h"
#include "waysidewin.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SWTCInterface; }
QT_END_NAMESPACE

class SWTCInterface : public QMainWindow
{
    Q_OBJECT

public:
    SWTCInterface(QWidget *parent = nullptr);
    ~SWTCInterface();
    void fillLists();
    vector<Block> getHWTrack();
private slots:
    void on_CreateWaysides_clicked();

    void on_DesignateHWWayside_clicked();

    void on_WaysideList_itemClicked(QListWidgetItem *item);

private:
    Ui::SWTCInterface *ui;
    QVector<WaysideWin*> wui;
    SWTrackController tc;
    vector<Block> hwTrack;
    int selected;
    bool hwMade;
    bool waysidesMade;
};
#endif // SWTCINTERFACE_H
