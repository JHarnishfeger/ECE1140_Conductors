/********************************************************************************
** Form generated from reading UI file 'testui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTUI_H
#define UI_TESTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Testui
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *GPS;
    QLabel *Power;
    QLabel *NextStation;
    QLabel *InteriorLights;
    QLabel *ExteriorLights;
    QLabel *LeftDoors;
    QLabel *RightDoors;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *SendBeaconData;
    QPushButton *EngineFailure;
    QPushButton *SignalPickupFailure;
    QPushButton *BrakeFailure;
    QPushButton *passengerEmergencyBrake;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QLineEdit *currentVelocity;
    QPushButton *makeTrain;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QSpinBox *spinBox;

    void setupUi(QDialog *Testui)
    {
        if (Testui->objectName().isEmpty())
            Testui->setObjectName(QString::fromUtf8("Testui"));
        Testui->resize(747, 381);
        QFont font;
        font.setPointSize(16);
        Testui->setFont(font);
        formLayoutWidget = new QWidget(Testui);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(390, 100, 331, 231));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_8);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        GPS = new QLabel(formLayoutWidget);
        GPS->setObjectName(QString::fromUtf8("GPS"));
        QFont font1;
        font1.setPointSize(12);
        GPS->setFont(font1);
        GPS->setFrameShape(QFrame::Box);

        formLayout->setWidget(0, QFormLayout::FieldRole, GPS);

        Power = new QLabel(formLayoutWidget);
        Power->setObjectName(QString::fromUtf8("Power"));
        Power->setFont(font1);
        Power->setFrameShape(QFrame::Box);

        formLayout->setWidget(1, QFormLayout::FieldRole, Power);

        NextStation = new QLabel(formLayoutWidget);
        NextStation->setObjectName(QString::fromUtf8("NextStation"));
        NextStation->setFont(font1);
        NextStation->setFrameShape(QFrame::Box);

        formLayout->setWidget(2, QFormLayout::FieldRole, NextStation);

        InteriorLights = new QLabel(formLayoutWidget);
        InteriorLights->setObjectName(QString::fromUtf8("InteriorLights"));
        InteriorLights->setFont(font1);
        InteriorLights->setFrameShape(QFrame::Box);

        formLayout->setWidget(3, QFormLayout::FieldRole, InteriorLights);

        ExteriorLights = new QLabel(formLayoutWidget);
        ExteriorLights->setObjectName(QString::fromUtf8("ExteriorLights"));
        ExteriorLights->setFont(font1);
        ExteriorLights->setFrameShape(QFrame::Box);

        formLayout->setWidget(4, QFormLayout::FieldRole, ExteriorLights);

        LeftDoors = new QLabel(formLayoutWidget);
        LeftDoors->setObjectName(QString::fromUtf8("LeftDoors"));
        LeftDoors->setFont(font1);
        LeftDoors->setFrameShape(QFrame::Box);

        formLayout->setWidget(5, QFormLayout::FieldRole, LeftDoors);

        RightDoors = new QLabel(formLayoutWidget);
        RightDoors->setObjectName(QString::fromUtf8("RightDoors"));
        RightDoors->setFont(font1);
        RightDoors->setFrameShape(QFrame::Box);

        formLayout->setWidget(6, QFormLayout::FieldRole, RightDoors);

        verticalLayoutWidget = new QWidget(Testui);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 80, 281, 251));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        SendBeaconData = new QPushButton(verticalLayoutWidget);
        SendBeaconData->setObjectName(QString::fromUtf8("SendBeaconData"));

        verticalLayout->addWidget(SendBeaconData);

        EngineFailure = new QPushButton(verticalLayoutWidget);
        EngineFailure->setObjectName(QString::fromUtf8("EngineFailure"));

        verticalLayout->addWidget(EngineFailure);

        SignalPickupFailure = new QPushButton(verticalLayoutWidget);
        SignalPickupFailure->setObjectName(QString::fromUtf8("SignalPickupFailure"));

        verticalLayout->addWidget(SignalPickupFailure);

        BrakeFailure = new QPushButton(verticalLayoutWidget);
        BrakeFailure->setObjectName(QString::fromUtf8("BrakeFailure"));

        verticalLayout->addWidget(BrakeFailure);

        passengerEmergencyBrake = new QPushButton(verticalLayoutWidget);
        passengerEmergencyBrake->setObjectName(QString::fromUtf8("passengerEmergencyBrake"));

        verticalLayout->addWidget(passengerEmergencyBrake);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout->addWidget(label_9);

        currentVelocity = new QLineEdit(verticalLayoutWidget);
        currentVelocity->setObjectName(QString::fromUtf8("currentVelocity"));

        horizontalLayout->addWidget(currentVelocity);


        verticalLayout->addLayout(horizontalLayout);

        makeTrain = new QPushButton(Testui);
        makeTrain->setObjectName(QString::fromUtf8("makeTrain"));
        makeTrain->setGeometry(QRect(150, 10, 491, 61));
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
        makeTrain->setPalette(palette);
        QFont font2;
        font2.setPointSize(28);
        makeTrain->setFont(font2);
        makeTrain->setAcceptDrops(false);
        makeTrain->setAutoFillBackground(false);
        makeTrain->setCheckable(false);
        verticalLayoutWidget_2 = new QWidget(Testui);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(679, 10, 51, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        spinBox = new QSpinBox(verticalLayoutWidget_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);

        verticalLayout_2->addWidget(spinBox);


        retranslateUi(Testui);

        QMetaObject::connectSlotsByName(Testui);
    } // setupUi

    void retranslateUi(QDialog *Testui)
    {
        Testui->setWindowTitle(QCoreApplication::translate("Testui", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Testui", "GPS", nullptr));
        label_2->setText(QCoreApplication::translate("Testui", "Power", nullptr));
        label_8->setText(QCoreApplication::translate("Testui", "Next Station", nullptr));
        label_3->setText(QCoreApplication::translate("Testui", "Interior Lights", nullptr));
        label_4->setText(QCoreApplication::translate("Testui", "Exterior Lights", nullptr));
        label_5->setText(QCoreApplication::translate("Testui", "Left Doors", nullptr));
        label_6->setText(QCoreApplication::translate("Testui", "Right Doors", nullptr));
        GPS->setText(QString());
        Power->setText(QString());
        NextStation->setText(QString());
        InteriorLights->setText(QString());
        ExteriorLights->setText(QString());
        LeftDoors->setText(QString());
        RightDoors->setText(QString());
        SendBeaconData->setText(QCoreApplication::translate("Testui", "Send Beacon Data", nullptr));
        EngineFailure->setText(QCoreApplication::translate("Testui", "Engine Failure", nullptr));
        SignalPickupFailure->setText(QCoreApplication::translate("Testui", "Signal Pickup Failure", nullptr));
        BrakeFailure->setText(QCoreApplication::translate("Testui", "Brake Failure", nullptr));
        passengerEmergencyBrake->setText(QCoreApplication::translate("Testui", "Passenger Emergency Brake", nullptr));
        label_9->setText(QCoreApplication::translate("Testui", "CurrentVelocity", nullptr));
        makeTrain->setText(QCoreApplication::translate("Testui", "Create Train", nullptr));
        label_7->setText(QCoreApplication::translate("Testui", "Train", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Testui: public Ui_Testui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTUI_H
