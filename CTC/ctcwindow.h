#ifndef CTCWINDOW_H
#define CTCWINDOW_H

#include <QMainWindow>
#include "CTC.hpp"
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class CTCWindow; }
QT_END_NAMESPACE

class CTCWindow : public QMainWindow
{
    Q_OBJECT

public:
    CTCWindow(std::vector<WayStruct>* sw_waystructs, WayStruct* hw_waystruct, QWidget *parent = nullptr);
    ~CTCWindow();

private slots:

    void on_button_chooseSchedule_clicked();

    void on_horizontalSlider_mode_sliderMoved(int position);

    void on_lineEdit_selectBlock_returnPressed();

    void on_pushButton_openCloseForMaintenecnce_clicked();

    void on_pushButton_selectBlockGo_clicked();

    void on_pushButton_dispatchTrain_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_openCloseSwitch_clicked();

private:
    Ui::CTCWindow *ui;
    CTC ctc;

    QGraphicsScene *scene;
    QGraphicsRectItem **testRect; //This is just to test the graphics for now
    QGraphicsTextItem *testText; //This is just to test the graphics for now
};
#endif // CTCWINDOW_H
