#ifndef CLOCK_H
#define CLOCK_H
#include <QtCore/QObject>
#include <QTimer>

class Clock : public QObject
{
    Q_OBJECT
public:
    Clock()
    {
        clk = new QTimer(this);
        connect(clk,SIGNAL(timeout()),this,SLOT(ClockTick()));
        clk->start(1000);
    }
    QTimer* clk;
signals:
    void tick();
public slots:
    void ClockTick()
    {
        emit tick();
    }
};

#endif // CLOCK_H
