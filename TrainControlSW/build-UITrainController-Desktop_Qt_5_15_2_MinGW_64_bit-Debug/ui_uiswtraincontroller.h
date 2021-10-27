/********************************************************************************
** Form generated from reading UI file 'uiswtraincontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UISWTRAINCONTROLLER_H
#define UI_UISWTRAINCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UISWTrainController
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *commandedVelocityLabel;
    QHBoxLayout *horizontalLayout;
    QLineEdit *commandeVelocity;
    QLabel *label;
    QLabel *currentyVelcotyLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *currentVelocity;
    QLabel *label_2;
    QLabel *suggestedVelocityLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *suggestedVelocity;
    QLabel *label_3;
    QLabel *speedLimitLabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *speedLimit;
    QLabel *label_4;
    QLabel *authorityLabel;
    QLabel *beaconLabel;
    QLabel *incomingStationLabel;
    QLabel *incomingStation;
    QLabel *serviceBrakeLabel;
    QPushButton *serviceBrake;
    QHBoxLayout *horizontalLayout_5;
    QLabel *authority;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_13;
    QLabel *power;
    QLabel *label_16;
    QPushButton *driverEmergencyBrake;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *commandedVelocityLabel_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSlider *leftDoors;
    QLabel *label_8;
    QLabel *currentyVelcotyLabel_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSlider *rightDoors;
    QLabel *label_9;
    QLabel *suggestedVelocityLabel_2;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QSlider *interiorLights;
    QLabel *label_11;
    QLabel *speedLimitLabel_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_12;
    QSlider *exteriorLights;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_11;
    QLabel *nxtStation;
    QPushButton *announceStation;
    QLabel *beaconLabel_2;
    QLabel *label_24;
    QLabel *label_25;
    QFrame *line_2;
    QLabel *label_36;
    QLabel *label_37;
    QSlider *modeswitch;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *kp;
    QLabel *label_28;
    QLineEdit *ki;
    QLabel *label_27;
    QMenuBar *menubar;
    QMenu *menuSWTrainControllerUI;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UISWTrainController)
    {
        if (UISWTrainController->objectName().isEmpty())
            UISWTrainController->setObjectName(QString::fromUtf8("UISWTrainController"));
        UISWTrainController->resize(1232, 753);
        centralwidget = new QWidget(UISWTrainController);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 174, 374, 371));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setHorizontalSpacing(6);
        formLayout->setVerticalSpacing(24);
        formLayout->setContentsMargins(0, 0, 0, 0);
        commandedVelocityLabel = new QLabel(formLayoutWidget);
        commandedVelocityLabel->setObjectName(QString::fromUtf8("commandedVelocityLabel"));
        QFont font;
        font.setPointSize(12);
        commandedVelocityLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, commandedVelocityLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 80, -1);
        commandeVelocity = new QLineEdit(formLayoutWidget);
        commandeVelocity->setObjectName(QString::fromUtf8("commandeVelocity"));

        horizontalLayout->addWidget(commandeVelocity);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        currentyVelcotyLabel = new QLabel(formLayoutWidget);
        currentyVelcotyLabel->setObjectName(QString::fromUtf8("currentyVelcotyLabel"));
        currentyVelcotyLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, currentyVelcotyLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        currentVelocity = new QLabel(formLayoutWidget);
        currentVelocity->setObjectName(QString::fromUtf8("currentVelocity"));
        currentVelocity->setFont(font);
        currentVelocity->setFrameShape(QFrame::Box);

        horizontalLayout_2->addWidget(currentVelocity);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_2);

        suggestedVelocityLabel = new QLabel(formLayoutWidget);
        suggestedVelocityLabel->setObjectName(QString::fromUtf8("suggestedVelocityLabel"));
        suggestedVelocityLabel->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, suggestedVelocityLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        suggestedVelocity = new QLabel(formLayoutWidget);
        suggestedVelocity->setObjectName(QString::fromUtf8("suggestedVelocity"));
        suggestedVelocity->setFont(font);
        suggestedVelocity->setFrameShape(QFrame::Box);

        horizontalLayout_3->addWidget(suggestedVelocity);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_3);

        speedLimitLabel = new QLabel(formLayoutWidget);
        speedLimitLabel->setObjectName(QString::fromUtf8("speedLimitLabel"));
        speedLimitLabel->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, speedLimitLabel);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        speedLimit = new QLabel(formLayoutWidget);
        speedLimit->setObjectName(QString::fromUtf8("speedLimit"));
        speedLimit->setFont(font);
        speedLimit->setFrameShape(QFrame::Box);

        horizontalLayout_4->addWidget(speedLimit);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_4);

        authorityLabel = new QLabel(formLayoutWidget);
        authorityLabel->setObjectName(QString::fromUtf8("authorityLabel"));
        authorityLabel->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, authorityLabel);

        beaconLabel = new QLabel(formLayoutWidget);
        beaconLabel->setObjectName(QString::fromUtf8("beaconLabel"));
        beaconLabel->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, beaconLabel);

        incomingStationLabel = new QLabel(formLayoutWidget);
        incomingStationLabel->setObjectName(QString::fromUtf8("incomingStationLabel"));
        incomingStationLabel->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, incomingStationLabel);

        incomingStation = new QLabel(formLayoutWidget);
        incomingStation->setObjectName(QString::fromUtf8("incomingStation"));
        incomingStation->setFont(font);
        incomingStation->setFrameShape(QFrame::Box);

        formLayout->setWidget(6, QFormLayout::FieldRole, incomingStation);

        serviceBrakeLabel = new QLabel(formLayoutWidget);
        serviceBrakeLabel->setObjectName(QString::fromUtf8("serviceBrakeLabel"));
        serviceBrakeLabel->setFont(font);

        formLayout->setWidget(7, QFormLayout::LabelRole, serviceBrakeLabel);

        serviceBrake = new QPushButton(formLayoutWidget);
        serviceBrake->setObjectName(QString::fromUtf8("serviceBrake"));
        serviceBrake->setFont(font);

        formLayout->setWidget(7, QFormLayout::FieldRole, serviceBrake);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        authority = new QLabel(formLayoutWidget);
        authority->setObjectName(QString::fromUtf8("authority"));
        authority->setFont(font);
        authority->setFrameShape(QFrame::Box);

        horizontalLayout_5->addWidget(authority);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_5);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        power = new QLabel(formLayoutWidget);
        power->setObjectName(QString::fromUtf8("power"));
        power->setFont(font);
        power->setFrameShape(QFrame::Box);

        horizontalLayout_13->addWidget(power);

        label_16 = new QLabel(formLayoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);

        horizontalLayout_13->addWidget(label_16);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout_13);

        driverEmergencyBrake = new QPushButton(centralwidget);
        driverEmergencyBrake->setObjectName(QString::fromUtf8("driverEmergencyBrake"));
        driverEmergencyBrake->setGeometry(QRect(20, 580, 321, 61));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(170, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(127, 127, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(170, 170, 170, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush5(QColor(255, 255, 220, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush6(QColor(0, 0, 0, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        QBrush brush7(QColor(244, 244, 244, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        driverEmergencyBrake->setPalette(palette);
        QFont font1;
        font1.setPointSize(28);
        driverEmergencyBrake->setFont(font1);
        driverEmergencyBrake->setAcceptDrops(false);
        driverEmergencyBrake->setAutoFillBackground(false);
        driverEmergencyBrake->setCheckable(false);
        formLayoutWidget_2 = new QWidget(centralwidget);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(410, 260, 321, 305));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_2->setHorizontalSpacing(6);
        formLayout_2->setVerticalSpacing(36);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        commandedVelocityLabel_2 = new QLabel(formLayoutWidget_2);
        commandedVelocityLabel_2->setObjectName(QString::fromUtf8("commandedVelocityLabel_2"));
        commandedVelocityLabel_2->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, commandedVelocityLabel_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(8);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(formLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_6->setFont(font2);

        horizontalLayout_6->addWidget(label_6);

        leftDoors = new QSlider(formLayoutWidget_2);
        leftDoors->setObjectName(QString::fromUtf8("leftDoors"));
        leftDoors->setFont(font);
        leftDoors->setAutoFillBackground(false);
        leftDoors->setMaximum(1);
        leftDoors->setPageStep(1);
        leftDoors->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(leftDoors);

        label_8 = new QLabel(formLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);

        horizontalLayout_6->addWidget(label_8);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, horizontalLayout_6);

        currentyVelcotyLabel_2 = new QLabel(formLayoutWidget_2);
        currentyVelcotyLabel_2->setObjectName(QString::fromUtf8("currentyVelcotyLabel_2"));
        currentyVelcotyLabel_2->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, currentyVelcotyLabel_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(8);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(formLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);

        horizontalLayout_7->addWidget(label_7);

        rightDoors = new QSlider(formLayoutWidget_2);
        rightDoors->setObjectName(QString::fromUtf8("rightDoors"));
        rightDoors->setFont(font);
        rightDoors->setAutoFillBackground(false);
        rightDoors->setMaximum(1);
        rightDoors->setPageStep(1);
        rightDoors->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(rightDoors);

        label_9 = new QLabel(formLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);

        horizontalLayout_7->addWidget(label_9);


        formLayout_2->setLayout(1, QFormLayout::FieldRole, horizontalLayout_7);

        suggestedVelocityLabel_2 = new QLabel(formLayoutWidget_2);
        suggestedVelocityLabel_2->setObjectName(QString::fromUtf8("suggestedVelocityLabel_2"));
        suggestedVelocityLabel_2->setFont(font);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, suggestedVelocityLabel_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(24);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_10 = new QLabel(formLayoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font2);

        horizontalLayout_9->addWidget(label_10);

        interiorLights = new QSlider(formLayoutWidget_2);
        interiorLights->setObjectName(QString::fromUtf8("interiorLights"));
        interiorLights->setFont(font);
        interiorLights->setAutoFillBackground(false);
        interiorLights->setMaximum(1);
        interiorLights->setPageStep(1);
        interiorLights->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(interiorLights);

        label_11 = new QLabel(formLayoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font2);

        horizontalLayout_9->addWidget(label_11);


        horizontalLayout_8->addLayout(horizontalLayout_9);


        formLayout_2->setLayout(2, QFormLayout::FieldRole, horizontalLayout_8);

        speedLimitLabel_2 = new QLabel(formLayoutWidget_2);
        speedLimitLabel_2->setObjectName(QString::fromUtf8("speedLimitLabel_2"));
        speedLimitLabel_2->setFont(font);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, speedLimitLabel_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(24);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_12 = new QLabel(formLayoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font2);

        horizontalLayout_10->addWidget(label_12);

        exteriorLights = new QSlider(formLayoutWidget_2);
        exteriorLights->setObjectName(QString::fromUtf8("exteriorLights"));
        exteriorLights->setFont(font);
        exteriorLights->setAutoFillBackground(false);
        exteriorLights->setMaximum(1);
        exteriorLights->setPageStep(1);
        exteriorLights->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(exteriorLights);

        label_13 = new QLabel(formLayoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font2);

        horizontalLayout_10->addWidget(label_13);


        formLayout_2->setLayout(3, QFormLayout::FieldRole, horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        nxtStation = new QLabel(formLayoutWidget_2);
        nxtStation->setObjectName(QString::fromUtf8("nxtStation"));
        nxtStation->setFont(font);
        nxtStation->setFrameShape(QFrame::Box);

        horizontalLayout_11->addWidget(nxtStation);

        announceStation = new QPushButton(formLayoutWidget_2);
        announceStation->setObjectName(QString::fromUtf8("announceStation"));
        announceStation->setFont(font);

        horizontalLayout_11->addWidget(announceStation);


        formLayout_2->setLayout(4, QFormLayout::FieldRole, horizontalLayout_11);

        beaconLabel_2 = new QLabel(formLayoutWidget_2);
        beaconLabel_2->setObjectName(QString::fromUtf8("beaconLabel_2"));
        beaconLabel_2->setFont(font);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, beaconLabel_2);

        label_24 = new QLabel(centralwidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(30, 90, 301, 51));
        QFont font3;
        font3.setPointSize(36);
        font3.setBold(true);
        font3.setUnderline(true);
        font3.setWeight(75);
        label_24->setFont(font3);
        label_25 = new QLabel(centralwidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(470, 190, 191, 51));
        label_25->setFont(font3);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(750, 0, 16, 751));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_36 = new QLabel(centralwidget);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(419, 150, 61, 22));
        label_36->setFont(font2);
        label_37 = new QLabel(centralwidget);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(610, 150, 101, 22));
        label_37->setFont(font2);
        modeswitch = new QSlider(centralwidget);
        modeswitch->setObjectName(QString::fromUtf8("modeswitch"));
        modeswitch->setGeometry(QRect(486, 150, 118, 22));
        modeswitch->setFont(font);
        modeswitch->setAutoFillBackground(false);
        modeswitch->setMaximum(1);
        modeswitch->setPageStep(1);
        modeswitch->setOrientation(Qt::Horizontal);
        label_38 = new QLabel(centralwidget);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(420, 90, 281, 51));
        QFont font4;
        font4.setPointSize(26);
        font4.setBold(true);
        font4.setUnderline(true);
        font4.setWeight(75);
        label_38->setFont(font4);
        label_39 = new QLabel(centralwidget);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(130, 20, 511, 61));
        QFont font5;
        font5.setPointSize(48);
        font5.setBold(true);
        font5.setUnderline(false);
        font5.setWeight(75);
        label_39->setFont(font5);
        label_39->setFrameShape(QFrame::StyledPanel);
        label_39->setFrameShadow(QFrame::Raised);
        label_40 = new QLabel(centralwidget);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(780, 10, 411, 91));
        label_40->setFont(font5);
        label_40->setAutoFillBackground(true);
        label_40->setFrameShape(QFrame::StyledPanel);
        label_40->setFrameShadow(QFrame::Raised);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(910, 150, 191, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        kp = new QLineEdit(gridLayoutWidget);
        kp->setObjectName(QString::fromUtf8("kp"));

        gridLayout->addWidget(kp, 0, 1, 1, 1);

        label_28 = new QLabel(gridLayoutWidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font);

        gridLayout->addWidget(label_28, 1, 0, 1, 1);

        ki = new QLineEdit(gridLayoutWidget);
        ki->setObjectName(QString::fromUtf8("ki"));

        gridLayout->addWidget(ki, 1, 1, 1, 1);

        label_27 = new QLabel(gridLayoutWidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setFont(font);

        gridLayout->addWidget(label_27, 0, 0, 1, 1);

        UISWTrainController->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UISWTrainController);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1232, 21));
        menuSWTrainControllerUI = new QMenu(menubar);
        menuSWTrainControllerUI->setObjectName(QString::fromUtf8("menuSWTrainControllerUI"));
        UISWTrainController->setMenuBar(menubar);
        statusbar = new QStatusBar(UISWTrainController);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UISWTrainController->setStatusBar(statusbar);

        menubar->addAction(menuSWTrainControllerUI->menuAction());

        retranslateUi(UISWTrainController);

        QMetaObject::connectSlotsByName(UISWTrainController);
    } // setupUi

    void retranslateUi(QMainWindow *UISWTrainController)
    {
        UISWTrainController->setWindowTitle(QCoreApplication::translate("UISWTrainController", "UISWTrainController", nullptr));
        commandedVelocityLabel->setText(QCoreApplication::translate("UISWTrainController", "Commanded Velocty", nullptr));
        commandeVelocity->setText(QString());
        label->setText(QCoreApplication::translate("UISWTrainController", "mph", nullptr));
        currentyVelcotyLabel->setText(QCoreApplication::translate("UISWTrainController", "Current Velocty", nullptr));
        currentVelocity->setText(QString());
        label_2->setText(QCoreApplication::translate("UISWTrainController", "mph", nullptr));
        suggestedVelocityLabel->setText(QCoreApplication::translate("UISWTrainController", "Suggested Velocty", nullptr));
        suggestedVelocity->setText(QString());
        label_3->setText(QCoreApplication::translate("UISWTrainController", "mph", nullptr));
        speedLimitLabel->setText(QCoreApplication::translate("UISWTrainController", "Speed Limit", nullptr));
        speedLimit->setText(QString());
        label_4->setText(QCoreApplication::translate("UISWTrainController", "mph", nullptr));
        authorityLabel->setText(QCoreApplication::translate("UISWTrainController", "Authority", nullptr));
        beaconLabel->setText(QCoreApplication::translate("UISWTrainController", "Power", nullptr));
        incomingStationLabel->setText(QCoreApplication::translate("UISWTrainController", "Incoming Station", nullptr));
        incomingStation->setText(QString());
        serviceBrakeLabel->setText(QCoreApplication::translate("UISWTrainController", "Service Brake", nullptr));
        serviceBrake->setText(QCoreApplication::translate("UISWTrainController", "Service Brake", nullptr));
        authority->setText(QString());
        label_5->setText(QCoreApplication::translate("UISWTrainController", "feet", nullptr));
        power->setText(QString());
        label_16->setText(QCoreApplication::translate("UISWTrainController", "W", nullptr));
        driverEmergencyBrake->setText(QCoreApplication::translate("UISWTrainController", "Emergency Brake", nullptr));
        commandedVelocityLabel_2->setText(QCoreApplication::translate("UISWTrainController", "Left Doors", nullptr));
        label_6->setText(QCoreApplication::translate("UISWTrainController", "CLOSED", nullptr));
        label_8->setText(QCoreApplication::translate("UISWTrainController", "OPEN", nullptr));
        currentyVelcotyLabel_2->setText(QCoreApplication::translate("UISWTrainController", "Right Doors", nullptr));
        label_7->setText(QCoreApplication::translate("UISWTrainController", "CLOSED", nullptr));
        label_9->setText(QCoreApplication::translate("UISWTrainController", "OPEN", nullptr));
        suggestedVelocityLabel_2->setText(QCoreApplication::translate("UISWTrainController", "Interior Lights", nullptr));
        label_10->setText(QCoreApplication::translate("UISWTrainController", "OFF", nullptr));
        label_11->setText(QCoreApplication::translate("UISWTrainController", "ON", nullptr));
        speedLimitLabel_2->setText(QCoreApplication::translate("UISWTrainController", "Exerior Lights", nullptr));
        label_12->setText(QCoreApplication::translate("UISWTrainController", "OFF", nullptr));
        label_13->setText(QCoreApplication::translate("UISWTrainController", "ON", nullptr));
        nxtStation->setText(QString());
        announceStation->setText(QCoreApplication::translate("UISWTrainController", "Announce", nullptr));
        beaconLabel_2->setText(QCoreApplication::translate("UISWTrainController", "Announce Station", nullptr));
        label_24->setText(QCoreApplication::translate("UISWTrainController", "Transit Data", nullptr));
        label_25->setText(QCoreApplication::translate("UISWTrainController", "Utilities", nullptr));
        label_36->setText(QCoreApplication::translate("UISWTrainController", "Manual", nullptr));
        label_37->setText(QCoreApplication::translate("UISWTrainController", "Automatic", nullptr));
        label_38->setText(QCoreApplication::translate("UISWTrainController", "Operation Mode", nullptr));
        label_39->setText(QCoreApplication::translate("UISWTrainController", "Train Driver UI", nullptr));
        label_40->setText(QCoreApplication::translate("UISWTrainController", "Engineer UI", nullptr));
        kp->setText(QString());
        label_28->setText(QCoreApplication::translate("UISWTrainController", "Ki", nullptr));
        ki->setText(QString());
        label_27->setText(QCoreApplication::translate("UISWTrainController", "Kp", nullptr));
        menuSWTrainControllerUI->setTitle(QCoreApplication::translate("UISWTrainController", "SWTrainControllerUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UISWTrainController: public Ui_UISWTrainController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UISWTRAINCONTROLLER_H
