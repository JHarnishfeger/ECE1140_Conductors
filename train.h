#ifndef TRAIN_H
#define TRAIN_H

#include <QMainWindow>
#include <string>
#include <QTimer>
#include "train_model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Train; }
QT_END_NAMESPACE

class Train : public QMainWindow
{
    Q_OBJECT

public:
    //Train Model
    Train_Model mainTrain;

    //Functions
    Train(QWidget *parent = nullptr);
    ~Train();

    //set functions
    QString setBFail(bool bf);
    QString setEFail(bool ef);
    QString setSFail(bool sf);

    //Timer variables
    QTimer *timer;
    void updateTestUI();

    //void setSpeed(double power);
    //void setPassengers(int n);
    //void setBrakes(bool b);
    //void setEbrakes(bool Eb);
    //bool getBfail();
    //bool getEfail();
    //bool getSfail();
    //void setAuthority(int mba);
    //void setLights(bool in,bool out);
    //void setDoors(bool l,bool r);
    //void setTemperature(double temp);

private slots:
    void on_EngineFail_clicked();
    void on_BrakeFail_clicked();
    void on_SignalFail_clicked();
    void on_lcdNumber_overflow();
    void on_pushButton_clicked();

private:

    //UI
    Ui::Train *ui;

    //all variables
    bool brakes;
    bool eBrakes;
    bool brakeFail,engineFail,signalFail;

    //double actualSpeed;
    //double acceleration;
    //double mass;
    //int numPassengers;
    //double modelMass = 4000;
    //int crewCount;
    //int authority;
    //double temperature;
    //bool interiorLight,exteriorLight;
    //bool leftDoor,rightDoor;
};

#endif // TRAIN_H
