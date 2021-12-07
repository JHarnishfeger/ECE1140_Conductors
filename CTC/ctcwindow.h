#ifndef CTCWINDOW_H
#define CTCWINDOW_H

#include <QMainWindow>
#include "CTC.hpp"
#include <QGraphicsScene>
#include "TrackMap.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class CTCWindow; }
QT_END_NAMESPACE

class CTCWindow : public QMainWindow
{
    Q_OBJECT

public:
    CTCWindow(std::vector<WayStruct>* sw_waystructs = nullptr, WayStruct* hw_waystruct = nullptr, QWidget *parent = nullptr);
    ~CTCWindow();
    void update();

public slots:

    void initializeWaystructs(std::vector<WayStruct>* sw_waystructs, WayStruct* hw_waystruct);

private slots:

    void on_button_chooseSchedule_clicked();

    void on_horizontalSlider_mode_sliderMoved(int position);

    void on_lineEdit_selectBlock_returnPressed();

    void on_pushButton_openCloseForMaintenecnce_clicked();

    void on_pushButton_selectBlockGo_clicked();

    void on_pushButton_dispatchTrain_clicked();

    void on_comboBox_activated();

    void on_pushButton_openCloseSwitch_clicked();

private:
    Ui::CTCWindow *ui;
    CTC ctc;

    TrackMap* trackMap;
};
#endif // CTCWINDOW_H
