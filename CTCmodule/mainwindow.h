#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "CTC.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    CTC ctc;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem **testRect; //This is just to test the graphics for now
    QGraphicsTextItem *testText; //This is just to test the graphics for now
};
#endif // MAINWINDOW_H
