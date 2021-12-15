#ifndef UISWTRAINCONTROLLER_H
#define UISWTRAINCONTROLLER_H

#include <QMainWindow>
#include <QTimer>
#include "SWTrainController.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UISWTrainController; }
QT_END_NAMESPACE

class UISWTrainController : public QMainWindow
{
    Q_OBJECT

public:
    SWTrainController* swtraincontroller;
    UISWTrainController(QWidget *parent = nullptr);
    ~UISWTrainController();

    QTimer *timer;

private slots:

    void timerInst();

    void on_driverEmergencyBrake_clicked();

    void on_leftDoors_valueChanged(int value);

    void on_rightDoors_valueChanged(int value);

    void on_interiorLights_valueChanged(int value);

    void on_exteriorLights_valueChanged(int value);

    void on_serviceBrake_clicked();

    void on_modeswitch_valueChanged(int value);

    void on_announceStation_clicked();

    void on_commandeVelocity_returnPressed();

    void on_kp_returnPressed();

    void on_ki_returnPressed();

private:
    Ui::UISWTrainController *ui;

};
#endif // UISWTRAINCONTROLLER_H
