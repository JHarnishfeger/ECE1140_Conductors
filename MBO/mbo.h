#ifndef MBO_H
#define MBO_H

#include "drivers.h"
#include "TrackLayout.h"
#include <QMainWindow>

#include <string>
#include <vector>

using std::vector;
using std::ofstream;
using std::string;

QT_BEGIN_NAMESPACE
namespace Ui { class MBO; }
QT_END_NAMESPACE

class MBO : public QMainWindow
{
    Q_OBJECT

public:
    MBO(QWidget *parent = nullptr);
    ~MBO();

    int getThroughput(int i){return throughput[i];}
    const string getStartOfDay(){return startOfDay;}
    void setThroughput(int t){fill (throughput.begin(),throughput.begin()+24,t);}
    void setThroughput(int t, int index){throughput[index] = t;}
    void setStartOfDay(string s){startOfDay = s;}
    bool schedule();
    void exportSchedule();

private slots:
    void on_GenerateScheduleButton_clicked();
    void on_HourlyThroughputButton_clicked();
    void on_HireDriverButton_clicked();
    void on_FireDriverButton_clicked();
    void on_DayThroughputButton_clicked();
    void on_StartOfDayButton_clicked();
    void on_ExportScheduleButton_clicked();

private:
    Ui::MBO *ui;
    Drivers drivers;
    bool created;
    vector<vector<string>> generatedSchedule;
    vector<int> throughput;
    string startOfDay; // by hour
    int stations;
};
#endif // MBO_H
