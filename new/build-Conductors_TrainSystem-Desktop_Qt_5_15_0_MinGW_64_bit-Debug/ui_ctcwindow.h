/********************************************************************************
** Form generated from reading UI file 'ctcwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTCWINDOW_H
#define UI_CTCWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CTCWindow
{
public:
    QAction *actionChoose_Schedule_File;
    QWidget *centralwidget;
    QPushButton *button_chooseSchedule;
    QLabel *label_upcomingSchedule;
    QSlider *horizontalSlider_mode;
    QLabel *label_ctcDispatchMode;
    QLabel *label_autoDispatchMode;
    QLabel *label_manualDispatchMode;
    QTextBrowser *textBrowser_schedule;
    QLabel *label_manualDispatchGroup;
    QLabel *label_manualDispatchtrain;
    QLabel *label_manualDispatchTo;
    QLabel *label_manualDispatchToTime;
    QLineEdit *lineEdit_dispatchTrain;
    QLineEdit *lineEdit_dispatchTo;
    QLineEdit *lineEdit_dispatchTime;
    QPushButton *pushButton_dispatchTrain;
    QLabel *label_selectBlock;
    QLineEdit *lineEdit_selectBlock;
    QLabel *label_blockProperties;
    QLabel *label_blockPropertiesId;
    QTextBrowser *textBrowser_blockPropertiesId;
    QLabel *label_blockPropertiesMaintenence;
    QTextBrowser *textBrowser_blockPropertiesMaintenence;
    QLabel *label_blockPropertiestrainPresent;
    QTextBrowser *textBrowser_blockPropertiesTrainPresent;
    QLabel *label_blockPropertiesThroughput;
    QTextBrowser *textBrowser_blockPropertiesThroughput;
    QPushButton *pushButton_openCloseForMaintenecnce;
    QPushButton *pushButton_selectBlockGo;
    QGraphicsView *graphicsView;
    QLabel *label_selectSwitch;
    QComboBox *comboBox;
    QLabel *label_switchProperties;
    QLabel *label_switchPropertiesId;
    QTextBrowser *textBrowser_switchId;
    QLabel *label_switchDirection;
    QTextBrowser *textBrowser_switchDirection;
    QPushButton *pushButton_openCloseSwitch;
    QLabel *label_trackMap;
    QPushButton *pushButton_dispatchTrain_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CTCWindow)
    {
        if (CTCWindow->objectName().isEmpty())
            CTCWindow->setObjectName(QString::fromUtf8("CTCWindow"));
        CTCWindow->resize(849, 669);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CTCWindow->sizePolicy().hasHeightForWidth());
        CTCWindow->setSizePolicy(sizePolicy);
        CTCWindow->setMinimumSize(QSize(0, 0));
        CTCWindow->setMaximumSize(QSize(9999, 9999));
        actionChoose_Schedule_File = new QAction(CTCWindow);
        actionChoose_Schedule_File->setObjectName(QString::fromUtf8("actionChoose_Schedule_File"));
        centralwidget = new QWidget(CTCWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        button_chooseSchedule = new QPushButton(centralwidget);
        button_chooseSchedule->setObjectName(QString::fromUtf8("button_chooseSchedule"));
        button_chooseSchedule->setGeometry(QRect(80, 310, 181, 34));
        label_upcomingSchedule = new QLabel(centralwidget);
        label_upcomingSchedule->setObjectName(QString::fromUtf8("label_upcomingSchedule"));
        label_upcomingSchedule->setGeometry(QRect(110, 70, 151, 22));
        QFont font;
        font.setBold(true);
        label_upcomingSchedule->setFont(font);
        horizontalSlider_mode = new QSlider(centralwidget);
        horizontalSlider_mode->setObjectName(QString::fromUtf8("horizontalSlider_mode"));
        horizontalSlider_mode->setGeometry(QRect(160, 40, 51, 20));
        horizontalSlider_mode->setMaximum(1);
        horizontalSlider_mode->setValue(1);
        horizontalSlider_mode->setOrientation(Qt::Horizontal);
        label_ctcDispatchMode = new QLabel(centralwidget);
        label_ctcDispatchMode->setObjectName(QString::fromUtf8("label_ctcDispatchMode"));
        label_ctcDispatchMode->setGeometry(QRect(110, 10, 151, 22));
        label_ctcDispatchMode->setFont(font);
        label_autoDispatchMode = new QLabel(centralwidget);
        label_autoDispatchMode->setObjectName(QString::fromUtf8("label_autoDispatchMode"));
        label_autoDispatchMode->setGeometry(QRect(240, 40, 41, 22));
        QFont font1;
        font1.setBold(false);
        label_autoDispatchMode->setFont(font1);
        label_manualDispatchMode = new QLabel(centralwidget);
        label_manualDispatchMode->setObjectName(QString::fromUtf8("label_manualDispatchMode"));
        label_manualDispatchMode->setGeometry(QRect(90, 40, 61, 22));
        label_manualDispatchMode->setFont(font1);
        textBrowser_schedule = new QTextBrowser(centralwidget);
        textBrowser_schedule->setObjectName(QString::fromUtf8("textBrowser_schedule"));
        textBrowser_schedule->setGeometry(QRect(10, 100, 331, 201));
        label_manualDispatchGroup = new QLabel(centralwidget);
        label_manualDispatchGroup->setObjectName(QString::fromUtf8("label_manualDispatchGroup"));
        label_manualDispatchGroup->setGeometry(QRect(140, 360, 131, 22));
        label_manualDispatchGroup->setFont(font);
        label_manualDispatchtrain = new QLabel(centralwidget);
        label_manualDispatchtrain->setObjectName(QString::fromUtf8("label_manualDispatchtrain"));
        label_manualDispatchtrain->setGeometry(QRect(10, 410, 41, 22));
        label_manualDispatchtrain->setFont(font1);
        label_manualDispatchTo = new QLabel(centralwidget);
        label_manualDispatchTo->setObjectName(QString::fromUtf8("label_manualDispatchTo"));
        label_manualDispatchTo->setGeometry(QRect(10, 460, 81, 22));
        label_manualDispatchTo->setFont(font1);
        label_manualDispatchToTime = new QLabel(centralwidget);
        label_manualDispatchToTime->setObjectName(QString::fromUtf8("label_manualDispatchToTime"));
        label_manualDispatchToTime->setGeometry(QRect(10, 510, 41, 22));
        label_manualDispatchToTime->setFont(font1);
        lineEdit_dispatchTrain = new QLineEdit(centralwidget);
        lineEdit_dispatchTrain->setObjectName(QString::fromUtf8("lineEdit_dispatchTrain"));
        lineEdit_dispatchTrain->setGeometry(QRect(110, 400, 181, 34));
        lineEdit_dispatchTo = new QLineEdit(centralwidget);
        lineEdit_dispatchTo->setObjectName(QString::fromUtf8("lineEdit_dispatchTo"));
        lineEdit_dispatchTo->setGeometry(QRect(110, 450, 181, 34));
        lineEdit_dispatchTime = new QLineEdit(centralwidget);
        lineEdit_dispatchTime->setObjectName(QString::fromUtf8("lineEdit_dispatchTime"));
        lineEdit_dispatchTime->setGeometry(QRect(110, 500, 181, 34));
        pushButton_dispatchTrain = new QPushButton(centralwidget);
        pushButton_dispatchTrain->setObjectName(QString::fromUtf8("pushButton_dispatchTrain"));
        pushButton_dispatchTrain->setGeometry(QRect(10, 550, 151, 34));
        pushButton_dispatchTrain->setFont(font);
        label_selectBlock = new QLabel(centralwidget);
        label_selectBlock->setObjectName(QString::fromUtf8("label_selectBlock"));
        label_selectBlock->setGeometry(QRect(410, 10, 91, 22));
        label_selectBlock->setFont(font);
        lineEdit_selectBlock = new QLineEdit(centralwidget);
        lineEdit_selectBlock->setObjectName(QString::fromUtf8("lineEdit_selectBlock"));
        lineEdit_selectBlock->setGeometry(QRect(360, 40, 121, 34));
        label_blockProperties = new QLabel(centralwidget);
        label_blockProperties->setObjectName(QString::fromUtf8("label_blockProperties"));
        label_blockProperties->setGeometry(QRect(400, 80, 131, 22));
        label_blockProperties->setFont(font);
        label_blockPropertiesId = new QLabel(centralwidget);
        label_blockPropertiesId->setObjectName(QString::fromUtf8("label_blockPropertiesId"));
        label_blockPropertiesId->setGeometry(QRect(360, 120, 67, 22));
        textBrowser_blockPropertiesId = new QTextBrowser(centralwidget);
        textBrowser_blockPropertiesId->setObjectName(QString::fromUtf8("textBrowser_blockPropertiesId"));
        textBrowser_blockPropertiesId->setGeometry(QRect(470, 110, 111, 41));
        label_blockPropertiesMaintenence = new QLabel(centralwidget);
        label_blockPropertiesMaintenence->setObjectName(QString::fromUtf8("label_blockPropertiesMaintenence"));
        label_blockPropertiesMaintenence->setGeometry(QRect(360, 170, 101, 22));
        textBrowser_blockPropertiesMaintenence = new QTextBrowser(centralwidget);
        textBrowser_blockPropertiesMaintenence->setObjectName(QString::fromUtf8("textBrowser_blockPropertiesMaintenence"));
        textBrowser_blockPropertiesMaintenence->setGeometry(QRect(470, 160, 111, 41));
        label_blockPropertiestrainPresent = new QLabel(centralwidget);
        label_blockPropertiestrainPresent->setObjectName(QString::fromUtf8("label_blockPropertiestrainPresent"));
        label_blockPropertiestrainPresent->setGeometry(QRect(360, 220, 101, 22));
        textBrowser_blockPropertiesTrainPresent = new QTextBrowser(centralwidget);
        textBrowser_blockPropertiesTrainPresent->setObjectName(QString::fromUtf8("textBrowser_blockPropertiesTrainPresent"));
        textBrowser_blockPropertiesTrainPresent->setGeometry(QRect(470, 210, 111, 41));
        label_blockPropertiesThroughput = new QLabel(centralwidget);
        label_blockPropertiesThroughput->setObjectName(QString::fromUtf8("label_blockPropertiesThroughput"));
        label_blockPropertiesThroughput->setGeometry(QRect(360, 270, 101, 22));
        textBrowser_blockPropertiesThroughput = new QTextBrowser(centralwidget);
        textBrowser_blockPropertiesThroughput->setObjectName(QString::fromUtf8("textBrowser_blockPropertiesThroughput"));
        textBrowser_blockPropertiesThroughput->setGeometry(QRect(470, 260, 111, 41));
        pushButton_openCloseForMaintenecnce = new QPushButton(centralwidget);
        pushButton_openCloseForMaintenecnce->setObjectName(QString::fromUtf8("pushButton_openCloseForMaintenecnce"));
        pushButton_openCloseForMaintenecnce->setGeometry(QRect(360, 310, 221, 34));
        pushButton_selectBlockGo = new QPushButton(centralwidget);
        pushButton_selectBlockGo->setObjectName(QString::fromUtf8("pushButton_selectBlockGo"));
        pushButton_selectBlockGo->setGeometry(QRect(490, 40, 91, 34));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(340, 401, 491, 211));
        graphicsView->setInteractive(true);
        label_selectSwitch = new QLabel(centralwidget);
        label_selectSwitch->setObjectName(QString::fromUtf8("label_selectSwitch"));
        label_selectSwitch->setGeometry(QRect(680, 10, 101, 22));
        label_selectSwitch->setFont(font);
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(620, 40, 211, 34));
        label_switchProperties = new QLabel(centralwidget);
        label_switchProperties->setObjectName(QString::fromUtf8("label_switchProperties"));
        label_switchProperties->setGeometry(QRect(670, 80, 131, 22));
        label_switchProperties->setFont(font);
        label_switchPropertiesId = new QLabel(centralwidget);
        label_switchPropertiesId->setObjectName(QString::fromUtf8("label_switchPropertiesId"));
        label_switchPropertiesId->setGeometry(QRect(620, 120, 67, 22));
        textBrowser_switchId = new QTextBrowser(centralwidget);
        textBrowser_switchId->setObjectName(QString::fromUtf8("textBrowser_switchId"));
        textBrowser_switchId->setGeometry(QRect(720, 110, 111, 41));
        label_switchDirection = new QLabel(centralwidget);
        label_switchDirection->setObjectName(QString::fromUtf8("label_switchDirection"));
        label_switchDirection->setGeometry(QRect(620, 170, 67, 22));
        textBrowser_switchDirection = new QTextBrowser(centralwidget);
        textBrowser_switchDirection->setObjectName(QString::fromUtf8("textBrowser_switchDirection"));
        textBrowser_switchDirection->setGeometry(QRect(720, 160, 111, 41));
        pushButton_openCloseSwitch = new QPushButton(centralwidget);
        pushButton_openCloseSwitch->setObjectName(QString::fromUtf8("pushButton_openCloseSwitch"));
        pushButton_openCloseSwitch->setGeometry(QRect(610, 210, 221, 34));
        label_trackMap = new QLabel(centralwidget);
        label_trackMap->setObjectName(QString::fromUtf8("label_trackMap"));
        label_trackMap->setGeometry(QRect(560, 360, 81, 22));
        label_trackMap->setFont(font);
        pushButton_dispatchTrain_2 = new QPushButton(centralwidget);
        pushButton_dispatchTrain_2->setObjectName(QString::fromUtf8("pushButton_dispatchTrain_2"));
        pushButton_dispatchTrain_2->setGeometry(QRect(170, 550, 161, 34));
        pushButton_dispatchTrain_2->setFont(font);
        CTCWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CTCWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 849, 26));
        CTCWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CTCWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CTCWindow->setStatusBar(statusbar);

        retranslateUi(CTCWindow);

        QMetaObject::connectSlotsByName(CTCWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CTCWindow)
    {
        CTCWindow->setWindowTitle(QCoreApplication::translate("CTCWindow", "CTC Module", nullptr));
        actionChoose_Schedule_File->setText(QCoreApplication::translate("CTCWindow", "Choose Schedule File...", nullptr));
        button_chooseSchedule->setText(QCoreApplication::translate("CTCWindow", "Choose Schedule File...", nullptr));
        label_upcomingSchedule->setText(QCoreApplication::translate("CTCWindow", "Upcoming Schedule", nullptr));
        label_ctcDispatchMode->setText(QCoreApplication::translate("CTCWindow", "CTC Dispatch Mode", nullptr));
        label_autoDispatchMode->setText(QCoreApplication::translate("CTCWindow", "Auto", nullptr));
        label_manualDispatchMode->setText(QCoreApplication::translate("CTCWindow", "Manual", nullptr));
        label_manualDispatchGroup->setText(QCoreApplication::translate("CTCWindow", "Manual Dispatch", nullptr));
        label_manualDispatchtrain->setText(QCoreApplication::translate("CTCWindow", "Train", nullptr));
        label_manualDispatchTo->setText(QCoreApplication::translate("CTCWindow", "Destination", nullptr));
        label_manualDispatchToTime->setText(QCoreApplication::translate("CTCWindow", "Time", nullptr));
        pushButton_dispatchTrain->setText(QCoreApplication::translate("CTCWindow", "Dispatch SW Train", nullptr));
        label_selectBlock->setText(QCoreApplication::translate("CTCWindow", "Select Block", nullptr));
        label_blockProperties->setText(QCoreApplication::translate("CTCWindow", "Block Properties", nullptr));
        label_blockPropertiesId->setText(QCoreApplication::translate("CTCWindow", "Block #:", nullptr));
        label_blockPropertiesMaintenence->setText(QCoreApplication::translate("CTCWindow", "Maintenence:", nullptr));
        label_blockPropertiestrainPresent->setText(QCoreApplication::translate("CTCWindow", "Train Present:", nullptr));
        label_blockPropertiesThroughput->setText(QCoreApplication::translate("CTCWindow", "Throughput:", nullptr));
        pushButton_openCloseForMaintenecnce->setText(QCoreApplication::translate("CTCWindow", "Open/Close for Maintenence", nullptr));
        pushButton_selectBlockGo->setText(QCoreApplication::translate("CTCWindow", "Select", nullptr));
        label_selectSwitch->setText(QCoreApplication::translate("CTCWindow", "Select Switch", nullptr));
        label_switchProperties->setText(QCoreApplication::translate("CTCWindow", "Switch Properties", nullptr));
        label_switchPropertiesId->setText(QCoreApplication::translate("CTCWindow", "Block #:", nullptr));
        label_switchDirection->setText(QCoreApplication::translate("CTCWindow", "Direction", nullptr));
        pushButton_openCloseSwitch->setText(QCoreApplication::translate("CTCWindow", "Open/Close Switch", nullptr));
        label_trackMap->setText(QCoreApplication::translate("CTCWindow", "Track Map", nullptr));
        pushButton_dispatchTrain_2->setText(QCoreApplication::translate("CTCWindow", "Dispatch HW Train", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CTCWindow: public Ui_CTCWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTCWINDOW_H
