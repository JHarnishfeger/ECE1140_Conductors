#ifndef WAYSIDEWIN_H
#define WAYSIDEWIN_H

#include <QDialog>
#include <QWidgetList>
#include <QListWidgetItem>
#include "Wayside.h"

namespace Ui {
class WaysideWin;
}

class WaysideWin : public QDialog
{
    Q_OBJECT

public:
    explicit WaysideWin(QWidget *parent = nullptr);
    ~WaysideWin();
    void initialize(Wayside&,int);
    void fillLists();
    Wayside *way;
private slots:
    void on_SwitchList_itemClicked(QListWidgetItem *item);

    void on_CrossingList_itemClicked(QListWidgetItem *item);

    void on_SwitchLeft_clicked();

    void on_SwitchRight_clicked();

    void on_ImportPLC_clicked();

    void on_CrossingOn_clicked();

    void on_CrossingOff_clicked();

private:
    Ui::WaysideWin *ui;
    string type;
    int id;
};

#endif // WAYSIDEWIN_H
