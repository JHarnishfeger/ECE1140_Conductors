/********************************************************************************
** Form generated from reading UI file 'traincontrollermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINCONTROLLERMAINWINDOW_H
#define UI_TRAINCONTROLLERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainControllerMainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Engineer;
    QFrame *line;
    QFrame *line_2;
    QLineEdit *KpText;
    QLineEdit *KiText;
    QLabel *Kp;
    QLabel *Ki;
    QLabel *Utilities;
    QPushButton *enterButton;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *commandedSpeed;
    QLineEdit *currentSpeed;
    QLineEdit *suggestedSpeed;
    QLineEdit *speedLimit;
    QLineEdit *authority;
    QTextBrowser *box;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QPushButton *testButton;
    QLabel *powerLabel;
    QLabel *label_14;
    QLineEdit *nextStation;
    QLineEdit *mode;
    QLabel *label_15;
    QCheckBox *stationApproachingCB;
    QLabel *StationApproaching;
    QPushButton *announceButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *LeftDoorsCB;
    QCheckBox *RightDoorsCB;
    QCheckBox *InteriorLightsCB;
    QCheckBox *ExteriorLightsCB;
    QCheckBox *ServiceBreakCB;
    QCheckBox *EmergencyBreakCB;
    QCheckBox *PassengerBreakCB;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *LeftDoors;
    QLabel *RightDoors;
    QLabel *InteriorLights;
    QLabel *ExteriorLights;
    QLabel *ServiceBreak;
    QLabel *EmergencyBreak;
    QLabel *PassengerBreak;
    QPushButton *ConnectButton;
    QComboBox *connectionComboBox;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *TrainControllerMainWindow)
    {
        if (TrainControllerMainWindow->objectName().isEmpty())
            TrainControllerMainWindow->setObjectName(QString::fromUtf8("TrainControllerMainWindow"));
        TrainControllerMainWindow->resize(1033, 629);
        centralwidget = new QWidget(TrainControllerMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Engineer = new QLabel(centralwidget);
        Engineer->setObjectName(QString::fromUtf8("Engineer"));
        Engineer->setGeometry(QRect(640, 10, 311, 81));
        Engineer->setScaledContents(false);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(563, 10, 20, 561));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(570, 220, 421, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        KpText = new QLineEdit(centralwidget);
        KpText->setObjectName(QString::fromUtf8("KpText"));
        KpText->setGeometry(QRect(640, 130, 113, 20));
        KiText = new QLineEdit(centralwidget);
        KiText->setObjectName(QString::fromUtf8("KiText"));
        KiText->setGeometry(QRect(800, 130, 113, 20));
        Kp = new QLabel(centralwidget);
        Kp->setObjectName(QString::fromUtf8("Kp"));
        Kp->setGeometry(QRect(690, 110, 21, 16));
        Ki = new QLabel(centralwidget);
        Ki->setObjectName(QString::fromUtf8("Ki"));
        Ki->setGeometry(QRect(850, 110, 16, 16));
        Utilities = new QLabel(centralwidget);
        Utilities->setObjectName(QString::fromUtf8("Utilities"));
        Utilities->setGeometry(QRect(690, 230, 201, 81));
        Utilities->setScaledContents(false);
        enterButton = new QPushButton(centralwidget);
        enterButton->setObjectName(QString::fromUtf8("enterButton"));
        enterButton->setGeometry(QRect(740, 170, 75, 23));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(260, 120, 47, 13));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(260, 190, 47, 13));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(260, 270, 47, 13));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(260, 350, 47, 13));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(260, 420, 47, 13));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(260, 500, 47, 13));
        commandedSpeed = new QLineEdit(centralwidget);
        commandedSpeed->setObjectName(QString::fromUtf8("commandedSpeed"));
        commandedSpeed->setGeometry(QRect(140, 120, 113, 20));
        currentSpeed = new QLineEdit(centralwidget);
        currentSpeed->setObjectName(QString::fromUtf8("currentSpeed"));
        currentSpeed->setGeometry(QRect(140, 190, 113, 20));
        suggestedSpeed = new QLineEdit(centralwidget);
        suggestedSpeed->setObjectName(QString::fromUtf8("suggestedSpeed"));
        suggestedSpeed->setGeometry(QRect(140, 270, 113, 20));
        speedLimit = new QLineEdit(centralwidget);
        speedLimit->setObjectName(QString::fromUtf8("speedLimit"));
        speedLimit->setGeometry(QRect(140, 350, 113, 20));
        authority = new QLineEdit(centralwidget);
        authority->setObjectName(QString::fromUtf8("authority"));
        authority->setGeometry(QRect(140, 420, 113, 20));
        box = new QTextBrowser(centralwidget);
        box->setObjectName(QString::fromUtf8("box"));
        box->setGeometry(QRect(140, 490, 114, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 500, 36, 16));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 120, 99, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 190, 77, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 350, 67, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 420, 51, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 270, 91, 16));
        testButton = new QPushButton(centralwidget);
        testButton->setObjectName(QString::fromUtf8("testButton"));
        testButton->setGeometry(QRect(190, 50, 75, 23));
        powerLabel = new QLabel(centralwidget);
        powerLabel->setObjectName(QString::fromUtf8("powerLabel"));
        powerLabel->setGeometry(QRect(150, 500, 47, 13));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(370, 100, 99, 16));
        nextStation = new QLineEdit(centralwidget);
        nextStation->setObjectName(QString::fromUtf8("nextStation"));
        nextStation->setGeometry(QRect(360, 120, 113, 20));
        mode = new QLineEdit(centralwidget);
        mode->setObjectName(QString::fromUtf8("mode"));
        mode->setGeometry(QRect(850, 320, 113, 20));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(860, 300, 99, 16));
        stationApproachingCB = new QCheckBox(centralwidget);
        stationApproachingCB->setObjectName(QString::fromUtf8("stationApproachingCB"));
        stationApproachingCB->setGeometry(QRect(430, 160, 70, 17));
        StationApproaching = new QLabel(centralwidget);
        StationApproaching->setObjectName(QString::fromUtf8("StationApproaching"));
        StationApproaching->setGeometry(QRect(310, 150, 101, 41));
        announceButton = new QPushButton(centralwidget);
        announceButton->setObjectName(QString::fromUtf8("announceButton"));
        announceButton->setGeometry(QRect(380, 180, 75, 23));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(730, 300, 16, 281));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        LeftDoorsCB = new QCheckBox(layoutWidget);
        LeftDoorsCB->setObjectName(QString::fromUtf8("LeftDoorsCB"));

        verticalLayout->addWidget(LeftDoorsCB);

        RightDoorsCB = new QCheckBox(layoutWidget);
        RightDoorsCB->setObjectName(QString::fromUtf8("RightDoorsCB"));

        verticalLayout->addWidget(RightDoorsCB);

        InteriorLightsCB = new QCheckBox(layoutWidget);
        InteriorLightsCB->setObjectName(QString::fromUtf8("InteriorLightsCB"));

        verticalLayout->addWidget(InteriorLightsCB);

        ExteriorLightsCB = new QCheckBox(layoutWidget);
        ExteriorLightsCB->setObjectName(QString::fromUtf8("ExteriorLightsCB"));

        verticalLayout->addWidget(ExteriorLightsCB);

        ServiceBreakCB = new QCheckBox(layoutWidget);
        ServiceBreakCB->setObjectName(QString::fromUtf8("ServiceBreakCB"));

        verticalLayout->addWidget(ServiceBreakCB);

        EmergencyBreakCB = new QCheckBox(layoutWidget);
        EmergencyBreakCB->setObjectName(QString::fromUtf8("EmergencyBreakCB"));

        verticalLayout->addWidget(EmergencyBreakCB);

        PassengerBreakCB = new QCheckBox(layoutWidget);
        PassengerBreakCB->setObjectName(QString::fromUtf8("PassengerBreakCB"));

        verticalLayout->addWidget(PassengerBreakCB);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(640, 310, 85, 261));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        LeftDoors = new QLabel(layoutWidget1);
        LeftDoors->setObjectName(QString::fromUtf8("LeftDoors"));

        verticalLayout_2->addWidget(LeftDoors);

        RightDoors = new QLabel(layoutWidget1);
        RightDoors->setObjectName(QString::fromUtf8("RightDoors"));

        verticalLayout_2->addWidget(RightDoors);

        InteriorLights = new QLabel(layoutWidget1);
        InteriorLights->setObjectName(QString::fromUtf8("InteriorLights"));

        verticalLayout_2->addWidget(InteriorLights);

        ExteriorLights = new QLabel(layoutWidget1);
        ExteriorLights->setObjectName(QString::fromUtf8("ExteriorLights"));

        verticalLayout_2->addWidget(ExteriorLights);

        ServiceBreak = new QLabel(layoutWidget1);
        ServiceBreak->setObjectName(QString::fromUtf8("ServiceBreak"));

        verticalLayout_2->addWidget(ServiceBreak);

        EmergencyBreak = new QLabel(layoutWidget1);
        EmergencyBreak->setObjectName(QString::fromUtf8("EmergencyBreak"));

        verticalLayout_2->addWidget(EmergencyBreak);

        PassengerBreak = new QLabel(layoutWidget1);
        PassengerBreak->setObjectName(QString::fromUtf8("PassengerBreak"));

        verticalLayout_2->addWidget(PassengerBreak);

        ConnectButton = new QPushButton(centralwidget);
        ConnectButton->setObjectName(QString::fromUtf8("ConnectButton"));
        ConnectButton->setGeometry(QRect(340, 380, 101, 41));
        connectionComboBox = new QComboBox(centralwidget);
        connectionComboBox->setObjectName(QString::fromUtf8("connectionComboBox"));
        connectionComboBox->setGeometry(QRect(470, 390, 69, 22));
        TrainControllerMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TrainControllerMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TrainControllerMainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(TrainControllerMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1033, 21));
        menubar->setDefaultUp(false);
        TrainControllerMainWindow->setMenuBar(menubar);

        retranslateUi(TrainControllerMainWindow);

        QMetaObject::connectSlotsByName(TrainControllerMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TrainControllerMainWindow)
    {
        TrainControllerMainWindow->setWindowTitle(QCoreApplication::translate("TrainControllerMainWindow", "TrainControllerMainWindow", nullptr));
        Engineer->setText(QCoreApplication::translate("TrainControllerMainWindow", "<html><head/><body><p><span style=\" font-size:36pt; font-weight:600;\">Engineer UI</span></p></body></html>", nullptr));
        KpText->setText(QCoreApplication::translate("TrainControllerMainWindow", "1000", nullptr));
        KiText->setText(QCoreApplication::translate("TrainControllerMainWindow", "1000", nullptr));
        Kp->setText(QCoreApplication::translate("TrainControllerMainWindow", "Kp", nullptr));
        Ki->setText(QCoreApplication::translate("TrainControllerMainWindow", "Ki", nullptr));
        Utilities->setText(QCoreApplication::translate("TrainControllerMainWindow", "<html><head/><body><p><span style=\" font-size:36pt; font-weight:600;\">Utilities</span></p></body></html>", nullptr));
        enterButton->setText(QCoreApplication::translate("TrainControllerMainWindow", "Enter", nullptr));
        label_7->setText(QCoreApplication::translate("TrainControllerMainWindow", "mph", nullptr));
        label_8->setText(QCoreApplication::translate("TrainControllerMainWindow", "mph", nullptr));
        label_9->setText(QCoreApplication::translate("TrainControllerMainWindow", "mph", nullptr));
        label_10->setText(QCoreApplication::translate("TrainControllerMainWindow", "mph", nullptr));
        label_11->setText(QCoreApplication::translate("TrainControllerMainWindow", "feet", nullptr));
        label_12->setText(QCoreApplication::translate("TrainControllerMainWindow", "W", nullptr));
        commandedSpeed->setText(QCoreApplication::translate("TrainControllerMainWindow", "60.00", nullptr));
        currentSpeed->setText(QCoreApplication::translate("TrainControllerMainWindow", "00.00", nullptr));
        suggestedSpeed->setText(QCoreApplication::translate("TrainControllerMainWindow", "10.00", nullptr));
        speedLimit->setText(QCoreApplication::translate("TrainControllerMainWindow", "80.00", nullptr));
        authority->setText(QCoreApplication::translate("TrainControllerMainWindow", "99.99", nullptr));
        box->setHtml(QCoreApplication::translate("TrainControllerMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("TrainControllerMainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Power</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("TrainControllerMainWindow", "Commanded Speed", nullptr));
        label_2->setText(QCoreApplication::translate("TrainControllerMainWindow", "Current Speed", nullptr));
        label_4->setText(QCoreApplication::translate("TrainControllerMainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Speed Limit</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("TrainControllerMainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Authority</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("TrainControllerMainWindow", "Suggested Speed", nullptr));
        testButton->setText(QCoreApplication::translate("TrainControllerMainWindow", "Test", nullptr));
        powerLabel->setText(QCoreApplication::translate("TrainControllerMainWindow", "00000", nullptr));
        label_14->setText(QCoreApplication::translate("TrainControllerMainWindow", "Next Station", nullptr));
        nextStation->setText(QCoreApplication::translate("TrainControllerMainWindow", "Yard", nullptr));
        mode->setText(QCoreApplication::translate("TrainControllerMainWindow", "manual", nullptr));
        label_15->setText(QCoreApplication::translate("TrainControllerMainWindow", "Mode", nullptr));
        stationApproachingCB->setText(QString());
        StationApproaching->setText(QCoreApplication::translate("TrainControllerMainWindow", "Station Approaching", nullptr));
        announceButton->setText(QCoreApplication::translate("TrainControllerMainWindow", "Announce", nullptr));
        LeftDoorsCB->setText(QString());
        RightDoorsCB->setText(QString());
        InteriorLightsCB->setText(QString());
        ExteriorLightsCB->setText(QString());
        ServiceBreakCB->setText(QString());
        EmergencyBreakCB->setText(QString());
        PassengerBreakCB->setText(QString());
        LeftDoors->setText(QCoreApplication::translate("TrainControllerMainWindow", "Left Doors", nullptr));
        RightDoors->setText(QCoreApplication::translate("TrainControllerMainWindow", "Right Doors", nullptr));
        InteriorLights->setText(QCoreApplication::translate("TrainControllerMainWindow", "Interior Lights", nullptr));
        ExteriorLights->setText(QCoreApplication::translate("TrainControllerMainWindow", "Exterior Lights", nullptr));
        ServiceBreak->setText(QCoreApplication::translate("TrainControllerMainWindow", "Service Break", nullptr));
        EmergencyBreak->setText(QCoreApplication::translate("TrainControllerMainWindow", "Emergency Break", nullptr));
        PassengerBreak->setText(QCoreApplication::translate("TrainControllerMainWindow", "Passenger Break", nullptr));
        ConnectButton->setText(QCoreApplication::translate("TrainControllerMainWindow", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrainControllerMainWindow: public Ui_TrainControllerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINCONTROLLERMAINWINDOW_H
