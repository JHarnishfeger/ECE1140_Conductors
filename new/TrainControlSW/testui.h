#ifndef TESTUI_H
#define TESTUI_H

#include <QDialog>
#include <QTimer>
#include "uiswtraincontroller.h"

namespace Ui {
class Testui;
}

class Testui : public QDialog
{
    Q_OBJECT

public:
    explicit Testui(QWidget *parent = nullptr);
    ~Testui();

    UISWTrainController s;
    QTimer *timer;

private slots:

    void updateTestUI();

    void on_makeTrain_clicked();

    void on_SendBeaconData_clicked();

    void on_EngineFailure_clicked();

    void on_SignalPickupFailure_clicked();

    void on_BrakeFailure_clicked();

    void on_passengerEmergencyBrake_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_currentVelocity_returnPressed();

    void on_pushButton_clicked();

    void on_sendTackCircuit_clicked();

private:
    Ui::Testui *ui;
};

#endif // TESTUI_H
