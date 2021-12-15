/********************************************************************************
** Form generated from reading UI file 'trackmodel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACKMODEL_H
#define UI_TRACKMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrackModel
{
public:
    QWidget *centralwidget;
    QGroupBox *trackLayoutGroupBox;
    QGroupBox *blockStatusGroupBox;
    QPushButton *railStatusFixButton;
    QPushButton *railStatusBreakButton;
    QLabel *railStatusLabel;
    QLineEdit *railStatusTextBox;
    QPushButton *circuitStatusFix;
    QLabel *circuitStatusLabel;
    QPushButton *circuitStatusBreak;
    QLineEdit *circuitStatusTextBox;
    QLineEdit *powerStatusTextBox;
    QPushButton *powerStatusBreak;
    QLabel *powerStatusLabel;
    QPushButton *powerStatusFix;
    QPushButton *loadTrackButton;
    QLineEdit *loadTrackTextBox;
    QLabel *currentBlockLabel;
    QLineEdit *currentBlockTextBoxLine;
    QComboBox *selectBlockDropdownBox;
    QGroupBox *trackHeaterGroupBox;
    QLabel *trackHeaterStatusLabel;
    QLineEdit *trackHeaterStatusTextBox;
    QLabel *trackHeaterTemperatureLabel;
    QLineEdit *trackHeaterTemperatureTextBox;
    QPushButton *trackHeaterOnButton;
    QPushButton *trackHeaterOffButton;
    QGroupBox *groupBox;
    QLabel *lineLabel;
    QLineEdit *lineTextBox;
    QLabel *branchLabel;
    QLineEdit *branchTextBox;
    QLabel *idLabel;
    QLineEdit *idTextBox;
    QLineEdit *typeTextBox;
    QLabel *typeLabel;
    QLineEdit *lengthTextBox;
    QLabel *lengthLabel;
    QLineEdit *gradeTextBox;
    QLabel *elevationLabel;
    QLabel *suggestedSpeedLabel;
    QLineEdit *suggestedSpeedTextBox;
    QLineEdit *elevationTextBox;
    QLineEdit *speedLimitTextBox;
    QLabel *speedLimitLabel;
    QLabel *gradeLabel;
    QLabel *crossingStatusLabel;
    QLabel *switchStatusLabel;
    QLineEdit *switchStatusTextBox;
    QLineEdit *passengersTextBox;
    QLineEdit *trainPresentTextBox;
    QLabel *trainPresentLabel;
    QLabel *passengersLabel;
    QLabel *stationNameLabel;
    QLineEdit *stationNameTextBox;
    QLabel *authorityLabel;
    QLineEdit *authorityTextBox;
    QLineEdit *crossingStatusTextBox;
    QLineEdit *trafficLightStatusTextBox;
    QLabel *trafficLightStatusLabel;
    QLabel *stationSideLabel;
    QLineEdit *stationSideTextBox;
    QLabel *beaconPresentLabel;
    QLineEdit *beaconPresentTextBox;
    QLineEdit *currentBlockTextBoxBranch;
    QLineEdit *currentBlockTextBoxId;
    QPushButton *selectBlockButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuTrackModel;

    void setupUi(QMainWindow *TrackModel)
    {
        if (TrackModel->objectName().isEmpty())
            TrackModel->setObjectName(QString::fromUtf8("TrackModel"));
        TrackModel->resize(922, 702);
        centralwidget = new QWidget(TrackModel);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        trackLayoutGroupBox = new QGroupBox(centralwidget);
        trackLayoutGroupBox->setObjectName(QString::fromUtf8("trackLayoutGroupBox"));
        trackLayoutGroupBox->setGeometry(QRect(10, 10, 901, 261));
        blockStatusGroupBox = new QGroupBox(centralwidget);
        blockStatusGroupBox->setObjectName(QString::fromUtf8("blockStatusGroupBox"));
        blockStatusGroupBox->setGeometry(QRect(10, 280, 201, 351));
        railStatusFixButton = new QPushButton(blockStatusGroupBox);
        railStatusFixButton->setObjectName(QString::fromUtf8("railStatusFixButton"));
        railStatusFixButton->setGeometry(QRect(10, 80, 81, 41));
        railStatusBreakButton = new QPushButton(blockStatusGroupBox);
        railStatusBreakButton->setObjectName(QString::fromUtf8("railStatusBreakButton"));
        railStatusBreakButton->setGeometry(QRect(100, 80, 81, 41));
        railStatusLabel = new QLabel(blockStatusGroupBox);
        railStatusLabel->setObjectName(QString::fromUtf8("railStatusLabel"));
        railStatusLabel->setGeometry(QRect(60, 20, 71, 16));
        railStatusTextBox = new QLineEdit(blockStatusGroupBox);
        railStatusTextBox->setObjectName(QString::fromUtf8("railStatusTextBox"));
        railStatusTextBox->setGeometry(QRect(10, 41, 171, 31));
        circuitStatusFix = new QPushButton(blockStatusGroupBox);
        circuitStatusFix->setObjectName(QString::fromUtf8("circuitStatusFix"));
        circuitStatusFix->setGeometry(QRect(10, 189, 81, 41));
        circuitStatusLabel = new QLabel(blockStatusGroupBox);
        circuitStatusLabel->setObjectName(QString::fromUtf8("circuitStatusLabel"));
        circuitStatusLabel->setGeometry(QRect(60, 129, 81, 16));
        circuitStatusBreak = new QPushButton(blockStatusGroupBox);
        circuitStatusBreak->setObjectName(QString::fromUtf8("circuitStatusBreak"));
        circuitStatusBreak->setGeometry(QRect(100, 189, 81, 41));
        circuitStatusTextBox = new QLineEdit(blockStatusGroupBox);
        circuitStatusTextBox->setObjectName(QString::fromUtf8("circuitStatusTextBox"));
        circuitStatusTextBox->setGeometry(QRect(10, 150, 171, 31));
        powerStatusTextBox = new QLineEdit(blockStatusGroupBox);
        powerStatusTextBox->setObjectName(QString::fromUtf8("powerStatusTextBox"));
        powerStatusTextBox->setGeometry(QRect(10, 260, 171, 31));
        powerStatusBreak = new QPushButton(blockStatusGroupBox);
        powerStatusBreak->setObjectName(QString::fromUtf8("powerStatusBreak"));
        powerStatusBreak->setGeometry(QRect(100, 299, 81, 41));
        powerStatusLabel = new QLabel(blockStatusGroupBox);
        powerStatusLabel->setObjectName(QString::fromUtf8("powerStatusLabel"));
        powerStatusLabel->setGeometry(QRect(60, 239, 81, 16));
        powerStatusFix = new QPushButton(blockStatusGroupBox);
        powerStatusFix->setObjectName(QString::fromUtf8("powerStatusFix"));
        powerStatusFix->setGeometry(QRect(10, 299, 81, 41));
        loadTrackButton = new QPushButton(centralwidget);
        loadTrackButton->setObjectName(QString::fromUtf8("loadTrackButton"));
        loadTrackButton->setGeometry(QRect(220, 290, 111, 31));
        loadTrackTextBox = new QLineEdit(centralwidget);
        loadTrackTextBox->setObjectName(QString::fromUtf8("loadTrackTextBox"));
        loadTrackTextBox->setGeometry(QRect(340, 290, 161, 31));
        currentBlockLabel = new QLabel(centralwidget);
        currentBlockLabel->setObjectName(QString::fromUtf8("currentBlockLabel"));
        currentBlockLabel->setGeometry(QRect(310, 330, 141, 16));
        currentBlockTextBoxLine = new QLineEdit(centralwidget);
        currentBlockTextBoxLine->setObjectName(QString::fromUtf8("currentBlockTextBoxLine"));
        currentBlockTextBoxLine->setGeometry(QRect(230, 350, 81, 31));
        selectBlockDropdownBox = new QComboBox(centralwidget);
        selectBlockDropdownBox->setObjectName(QString::fromUtf8("selectBlockDropdownBox"));
        selectBlockDropdownBox->setGeometry(QRect(340, 400, 161, 31));
        trackHeaterGroupBox = new QGroupBox(centralwidget);
        trackHeaterGroupBox->setObjectName(QString::fromUtf8("trackHeaterGroupBox"));
        trackHeaterGroupBox->setGeometry(QRect(220, 460, 281, 171));
        trackHeaterStatusLabel = new QLabel(trackHeaterGroupBox);
        trackHeaterStatusLabel->setObjectName(QString::fromUtf8("trackHeaterStatusLabel"));
        trackHeaterStatusLabel->setGeometry(QRect(70, 20, 121, 16));
        trackHeaterStatusTextBox = new QLineEdit(trackHeaterGroupBox);
        trackHeaterStatusTextBox->setObjectName(QString::fromUtf8("trackHeaterStatusTextBox"));
        trackHeaterStatusTextBox->setGeometry(QRect(40, 40, 181, 31));
        trackHeaterTemperatureLabel = new QLabel(trackHeaterGroupBox);
        trackHeaterTemperatureLabel->setObjectName(QString::fromUtf8("trackHeaterTemperatureLabel"));
        trackHeaterTemperatureLabel->setGeometry(QRect(90, 80, 121, 16));
        trackHeaterTemperatureTextBox = new QLineEdit(trackHeaterGroupBox);
        trackHeaterTemperatureTextBox->setObjectName(QString::fromUtf8("trackHeaterTemperatureTextBox"));
        trackHeaterTemperatureTextBox->setGeometry(QRect(40, 100, 181, 31));
        trackHeaterOnButton = new QPushButton(trackHeaterGroupBox);
        trackHeaterOnButton->setObjectName(QString::fromUtf8("trackHeaterOnButton"));
        trackHeaterOnButton->setGeometry(QRect(20, 140, 101, 28));
        trackHeaterOffButton = new QPushButton(trackHeaterGroupBox);
        trackHeaterOffButton->setObjectName(QString::fromUtf8("trackHeaterOffButton"));
        trackHeaterOffButton->setGeometry(QRect(142, 140, 111, 28));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(510, 280, 401, 351));
        lineLabel = new QLabel(groupBox);
        lineLabel->setObjectName(QString::fromUtf8("lineLabel"));
        lineLabel->setGeometry(QRect(10, 30, 55, 21));
        lineTextBox = new QLineEdit(groupBox);
        lineTextBox->setObjectName(QString::fromUtf8("lineTextBox"));
        lineTextBox->setGeometry(QRect(10, 50, 113, 22));
        branchLabel = new QLabel(groupBox);
        branchLabel->setObjectName(QString::fromUtf8("branchLabel"));
        branchLabel->setGeometry(QRect(10, 80, 55, 21));
        branchTextBox = new QLineEdit(groupBox);
        branchTextBox->setObjectName(QString::fromUtf8("branchTextBox"));
        branchTextBox->setGeometry(QRect(10, 100, 113, 22));
        idLabel = new QLabel(groupBox);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));
        idLabel->setGeometry(QRect(10, 130, 55, 21));
        idTextBox = new QLineEdit(groupBox);
        idTextBox->setObjectName(QString::fromUtf8("idTextBox"));
        idTextBox->setGeometry(QRect(10, 150, 113, 22));
        typeTextBox = new QLineEdit(groupBox);
        typeTextBox->setObjectName(QString::fromUtf8("typeTextBox"));
        typeTextBox->setGeometry(QRect(10, 200, 113, 22));
        typeLabel = new QLabel(groupBox);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));
        typeLabel->setGeometry(QRect(10, 180, 55, 21));
        lengthTextBox = new QLineEdit(groupBox);
        lengthTextBox->setObjectName(QString::fromUtf8("lengthTextBox"));
        lengthTextBox->setGeometry(QRect(10, 300, 113, 22));
        lengthLabel = new QLabel(groupBox);
        lengthLabel->setObjectName(QString::fromUtf8("lengthLabel"));
        lengthLabel->setGeometry(QRect(10, 280, 55, 21));
        gradeTextBox = new QLineEdit(groupBox);
        gradeTextBox->setObjectName(QString::fromUtf8("gradeTextBox"));
        gradeTextBox->setGeometry(QRect(140, 150, 113, 22));
        elevationLabel = new QLabel(groupBox);
        elevationLabel->setObjectName(QString::fromUtf8("elevationLabel"));
        elevationLabel->setGeometry(QRect(140, 180, 55, 21));
        suggestedSpeedLabel = new QLabel(groupBox);
        suggestedSpeedLabel->setObjectName(QString::fromUtf8("suggestedSpeedLabel"));
        suggestedSpeedLabel->setGeometry(QRect(140, 280, 111, 21));
        suggestedSpeedTextBox = new QLineEdit(groupBox);
        suggestedSpeedTextBox->setObjectName(QString::fromUtf8("suggestedSpeedTextBox"));
        suggestedSpeedTextBox->setGeometry(QRect(140, 300, 113, 22));
        elevationTextBox = new QLineEdit(groupBox);
        elevationTextBox->setObjectName(QString::fromUtf8("elevationTextBox"));
        elevationTextBox->setGeometry(QRect(140, 200, 113, 22));
        speedLimitTextBox = new QLineEdit(groupBox);
        speedLimitTextBox->setObjectName(QString::fromUtf8("speedLimitTextBox"));
        speedLimitTextBox->setGeometry(QRect(10, 250, 113, 22));
        speedLimitLabel = new QLabel(groupBox);
        speedLimitLabel->setObjectName(QString::fromUtf8("speedLimitLabel"));
        speedLimitLabel->setGeometry(QRect(10, 230, 81, 21));
        gradeLabel = new QLabel(groupBox);
        gradeLabel->setObjectName(QString::fromUtf8("gradeLabel"));
        gradeLabel->setGeometry(QRect(140, 130, 55, 21));
        crossingStatusLabel = new QLabel(groupBox);
        crossingStatusLabel->setObjectName(QString::fromUtf8("crossingStatusLabel"));
        crossingStatusLabel->setGeometry(QRect(270, 130, 111, 21));
        switchStatusLabel = new QLabel(groupBox);
        switchStatusLabel->setObjectName(QString::fromUtf8("switchStatusLabel"));
        switchStatusLabel->setGeometry(QRect(270, 180, 111, 21));
        switchStatusTextBox = new QLineEdit(groupBox);
        switchStatusTextBox->setObjectName(QString::fromUtf8("switchStatusTextBox"));
        switchStatusTextBox->setGeometry(QRect(270, 200, 113, 22));
        passengersTextBox = new QLineEdit(groupBox);
        passengersTextBox->setObjectName(QString::fromUtf8("passengersTextBox"));
        passengersTextBox->setGeometry(QRect(140, 250, 113, 22));
        trainPresentTextBox = new QLineEdit(groupBox);
        trainPresentTextBox->setObjectName(QString::fromUtf8("trainPresentTextBox"));
        trainPresentTextBox->setGeometry(QRect(270, 250, 113, 22));
        trainPresentLabel = new QLabel(groupBox);
        trainPresentLabel->setObjectName(QString::fromUtf8("trainPresentLabel"));
        trainPresentLabel->setGeometry(QRect(270, 230, 111, 21));
        passengersLabel = new QLabel(groupBox);
        passengersLabel->setObjectName(QString::fromUtf8("passengersLabel"));
        passengersLabel->setGeometry(QRect(140, 230, 101, 21));
        stationNameLabel = new QLabel(groupBox);
        stationNameLabel->setObjectName(QString::fromUtf8("stationNameLabel"));
        stationNameLabel->setGeometry(QRect(140, 30, 101, 21));
        stationNameTextBox = new QLineEdit(groupBox);
        stationNameTextBox->setObjectName(QString::fromUtf8("stationNameTextBox"));
        stationNameTextBox->setGeometry(QRect(140, 50, 113, 22));
        authorityLabel = new QLabel(groupBox);
        authorityLabel->setObjectName(QString::fromUtf8("authorityLabel"));
        authorityLabel->setGeometry(QRect(140, 80, 55, 21));
        authorityTextBox = new QLineEdit(groupBox);
        authorityTextBox->setObjectName(QString::fromUtf8("authorityTextBox"));
        authorityTextBox->setGeometry(QRect(140, 100, 113, 22));
        crossingStatusTextBox = new QLineEdit(groupBox);
        crossingStatusTextBox->setObjectName(QString::fromUtf8("crossingStatusTextBox"));
        crossingStatusTextBox->setGeometry(QRect(270, 150, 113, 22));
        trafficLightStatusTextBox = new QLineEdit(groupBox);
        trafficLightStatusTextBox->setObjectName(QString::fromUtf8("trafficLightStatusTextBox"));
        trafficLightStatusTextBox->setGeometry(QRect(270, 100, 113, 22));
        trafficLightStatusLabel = new QLabel(groupBox);
        trafficLightStatusLabel->setObjectName(QString::fromUtf8("trafficLightStatusLabel"));
        trafficLightStatusLabel->setGeometry(QRect(270, 80, 111, 21));
        stationSideLabel = new QLabel(groupBox);
        stationSideLabel->setObjectName(QString::fromUtf8("stationSideLabel"));
        stationSideLabel->setGeometry(QRect(270, 30, 111, 21));
        stationSideTextBox = new QLineEdit(groupBox);
        stationSideTextBox->setObjectName(QString::fromUtf8("stationSideTextBox"));
        stationSideTextBox->setGeometry(QRect(270, 50, 113, 22));
        beaconPresentLabel = new QLabel(groupBox);
        beaconPresentLabel->setObjectName(QString::fromUtf8("beaconPresentLabel"));
        beaconPresentLabel->setGeometry(QRect(270, 280, 111, 21));
        beaconPresentTextBox = new QLineEdit(groupBox);
        beaconPresentTextBox->setObjectName(QString::fromUtf8("beaconPresentTextBox"));
        beaconPresentTextBox->setGeometry(QRect(270, 300, 113, 22));
        currentBlockTextBoxBranch = new QLineEdit(centralwidget);
        currentBlockTextBoxBranch->setObjectName(QString::fromUtf8("currentBlockTextBoxBranch"));
        currentBlockTextBoxBranch->setGeometry(QRect(320, 350, 81, 31));
        currentBlockTextBoxId = new QLineEdit(centralwidget);
        currentBlockTextBoxId->setObjectName(QString::fromUtf8("currentBlockTextBoxId"));
        currentBlockTextBoxId->setGeometry(QRect(410, 350, 81, 31));
        selectBlockButton = new QPushButton(centralwidget);
        selectBlockButton->setObjectName(QString::fromUtf8("selectBlockButton"));
        selectBlockButton->setGeometry(QRect(220, 390, 111, 61));
        TrackModel->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TrackModel);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TrackModel->setStatusBar(statusbar);
        menubar = new QMenuBar(TrackModel);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 922, 19));
        menuTrackModel = new QMenu(menubar);
        menuTrackModel->setObjectName(QString::fromUtf8("menuTrackModel"));
        TrackModel->setMenuBar(menubar);

        menubar->addAction(menuTrackModel->menuAction());

        retranslateUi(TrackModel);

        QMetaObject::connectSlotsByName(TrackModel);
    } // setupUi

    void retranslateUi(QMainWindow *TrackModel)
    {
        TrackModel->setWindowTitle(QCoreApplication::translate("TrackModel", "TrackModel", nullptr));
        trackLayoutGroupBox->setTitle(QCoreApplication::translate("TrackModel", "Track Layout", nullptr));
        blockStatusGroupBox->setTitle(QCoreApplication::translate("TrackModel", "Block Status", nullptr));
        railStatusFixButton->setText(QCoreApplication::translate("TrackModel", "Fix", nullptr));
        railStatusBreakButton->setText(QCoreApplication::translate("TrackModel", "Break", nullptr));
        railStatusLabel->setText(QCoreApplication::translate("TrackModel", "Rail Status", nullptr));
        railStatusTextBox->setText(QString());
        circuitStatusFix->setText(QCoreApplication::translate("TrackModel", "Fix", nullptr));
        circuitStatusLabel->setText(QCoreApplication::translate("TrackModel", "Circuit Status", nullptr));
        circuitStatusBreak->setText(QCoreApplication::translate("TrackModel", "Break", nullptr));
        circuitStatusTextBox->setText(QString());
        powerStatusTextBox->setText(QString());
        powerStatusBreak->setText(QCoreApplication::translate("TrackModel", "Break", nullptr));
        powerStatusLabel->setText(QCoreApplication::translate("TrackModel", "Power Status", nullptr));
        powerStatusFix->setText(QCoreApplication::translate("TrackModel", "Fix", nullptr));
        loadTrackButton->setText(QCoreApplication::translate("TrackModel", "Load Track", nullptr));
        loadTrackTextBox->setText(QCoreApplication::translate("TrackModel", "Enter filename.txt", nullptr));
        currentBlockLabel->setText(QCoreApplication::translate("TrackModel", "Current Block:", nullptr));
        currentBlockTextBoxLine->setText(QCoreApplication::translate("TrackModel", "line", nullptr));
        trackHeaterGroupBox->setTitle(QCoreApplication::translate("TrackModel", "Track Heater", nullptr));
        trackHeaterStatusLabel->setText(QCoreApplication::translate("TrackModel", "Track Heater Status", nullptr));
        trackHeaterStatusTextBox->setText(QString());
        trackHeaterTemperatureLabel->setText(QCoreApplication::translate("TrackModel", "Temperature", nullptr));
        trackHeaterTemperatureTextBox->setText(QString());
        trackHeaterOnButton->setText(QCoreApplication::translate("TrackModel", "On", nullptr));
        trackHeaterOffButton->setText(QCoreApplication::translate("TrackModel", "Off", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TrackModel", "Block Stats", nullptr));
        lineLabel->setText(QCoreApplication::translate("TrackModel", "Line:", nullptr));
        branchLabel->setText(QCoreApplication::translate("TrackModel", "Branch:", nullptr));
        idLabel->setText(QCoreApplication::translate("TrackModel", "Number:", nullptr));
        typeLabel->setText(QCoreApplication::translate("TrackModel", "Type:", nullptr));
        lengthLabel->setText(QCoreApplication::translate("TrackModel", "Length:", nullptr));
        elevationLabel->setText(QCoreApplication::translate("TrackModel", "Elevation:", nullptr));
        suggestedSpeedLabel->setText(QCoreApplication::translate("TrackModel", "Suggested Speed:", nullptr));
        speedLimitLabel->setText(QCoreApplication::translate("TrackModel", "Speed Limit:", nullptr));
        gradeLabel->setText(QCoreApplication::translate("TrackModel", "Grade:", nullptr));
        crossingStatusLabel->setText(QCoreApplication::translate("TrackModel", "Crossing Status:", nullptr));
        switchStatusLabel->setText(QCoreApplication::translate("TrackModel", "Switch Status:", nullptr));
        trainPresentLabel->setText(QCoreApplication::translate("TrackModel", "Train Present:", nullptr));
        passengersLabel->setText(QCoreApplication::translate("TrackModel", "Passengers:", nullptr));
        stationNameLabel->setText(QCoreApplication::translate("TrackModel", "Station Name:", nullptr));
        authorityLabel->setText(QCoreApplication::translate("TrackModel", "Authority:", nullptr));
        trafficLightStatusLabel->setText(QCoreApplication::translate("TrackModel", "Traffic Light:", nullptr));
        stationSideLabel->setText(QCoreApplication::translate("TrackModel", "Station Side:", nullptr));
        beaconPresentLabel->setText(QCoreApplication::translate("TrackModel", "Beacon Present:", nullptr));
        currentBlockTextBoxBranch->setText(QCoreApplication::translate("TrackModel", "branch", nullptr));
        currentBlockTextBoxId->setText(QCoreApplication::translate("TrackModel", "num", nullptr));
        selectBlockButton->setText(QCoreApplication::translate("TrackModel", "Select Block:", nullptr));
        menuTrackModel->setTitle(QCoreApplication::translate("TrackModel", "TrackModel Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrackModel: public Ui_TrackModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACKMODEL_H
