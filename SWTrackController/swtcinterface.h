#ifndef SWTCINTERFACE_H
#define SWTCINTERFACE_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <vector>
using std::vector;
#include "SWTrackController.cpp"

QT_BEGIN_NAMESPACE
namespace Ui { class SWTCInterface; }
QT_END_NAMESPACE

class SWTCInterface : public QMainWindow
{
    Q_OBJECT

public:
    SWTCInterface(QWidget *parent = nullptr);
    ~SWTCInterface();
    //void fillLists();
    //SWTrackController tc;
    //Block selected;

private slots:
    //void on_CrossingButton_clicked();

    //void on_SwitchButton_clicked();

    //void on_SwitchList_itemClicked(QListWidgetItem *item);

    //void on_CrossingList_itemClicked(QListWidgetItem *item);

private:
    Ui::SWTCInterface *ui;
};
#endif // SWTCINTERFACE_H
