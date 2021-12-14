#ifndef TRACKMODEL_H
#define TRACKMODEL_H

#include <QMainWindow>
#include "Track.h"
#include "Block.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TrackModel; }
QT_END_NAMESPACE

class TrackModel : public QMainWindow
{
    Q_OBJECT

public:
    TrackModel(QWidget *parent = nullptr);
    ~TrackModel();

private slots:
    void on_loadTrackButton_clicked();

    void on_trackHeaterOnButton_clicked();

    void on_trackHeaterOffButton_clicked();

    void on_railStatusFixButton_clicked();

    void on_railStatusBreakButton_clicked();

    void on_circuitStatusFix_clicked();

    void on_circuitStatusBreak_clicked();

    void on_powerStatusFix_clicked();

    void on_powerStatusBreak_clicked();

    void on_selectBlockButton_clicked();

private:
    Ui::TrackModel *ui;
    Track t;
    bool greenCreated, redCreated;

signals:
    void giveTrack(vector<Block*> red, vector<Block*> green);
    void updateWaysides(vector<Block*> red, vector<Block*> green);
public slots:
    void updateFromWayside(vector<Block> wasysideBlocks);
};
#endif // TRACKMODEL_H
