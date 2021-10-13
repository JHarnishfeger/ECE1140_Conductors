/********************************************************************************
** Form generated from reading UI file 'transitData.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSITDATA_H
#define UI_TRANSITDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_transitData
{
public:
    QPushButton *driverEmergencyBrake;
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
    QLabel *beacons;
    QLabel *incomingStationLabel;
    QLabel *incomingStation;
    QLabel *serviceBrakeLabel;
    QPushButton *serviceBrake;
    QHBoxLayout *horizontalLayout_5;
    QLabel *authority;
    QLabel *label_5;

    void setupUi(QDialog *transitData)
    {
        if (transitData->objectName().isEmpty())
            transitData->setObjectName(QString::fromUtf8("transitData"));
        transitData->resize(363, 516);
        driverEmergencyBrake = new QPushButton(transitData);
        driverEmergencyBrake->setObjectName(QString::fromUtf8("driverEmergencyBrake"));
        driverEmergencyBrake->setGeometry(QRect(10, 440, 321, 61));
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
        QFont font;
        font.setPointSize(28);
        driverEmergencyBrake->setFont(font);
        driverEmergencyBrake->setAcceptDrops(false);
        driverEmergencyBrake->setAutoFillBackground(false);
        driverEmergencyBrake->setCheckable(false);
        formLayoutWidget = new QWidget(transitData);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 321, 385));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(6);
        formLayout->setVerticalSpacing(24);
        formLayout->setContentsMargins(0, 0, 0, 0);
        commandedVelocityLabel = new QLabel(formLayoutWidget);
        commandedVelocityLabel->setObjectName(QString::fromUtf8("commandedVelocityLabel"));
        QFont font1;
        font1.setPointSize(12);
        commandedVelocityLabel->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, commandedVelocityLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        commandeVelocity = new QLineEdit(formLayoutWidget);
        commandeVelocity->setObjectName(QString::fromUtf8("commandeVelocity"));

        horizontalLayout->addWidget(commandeVelocity);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        horizontalLayout->addWidget(label);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        currentyVelcotyLabel = new QLabel(formLayoutWidget);
        currentyVelcotyLabel->setObjectName(QString::fromUtf8("currentyVelcotyLabel"));
        currentyVelcotyLabel->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, currentyVelcotyLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        currentVelocity = new QLabel(formLayoutWidget);
        currentVelocity->setObjectName(QString::fromUtf8("currentVelocity"));
        currentVelocity->setFont(font1);
        currentVelocity->setFrameShape(QFrame::WinPanel);

        horizontalLayout_2->addWidget(currentVelocity);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_2);

        suggestedVelocityLabel = new QLabel(formLayoutWidget);
        suggestedVelocityLabel->setObjectName(QString::fromUtf8("suggestedVelocityLabel"));
        suggestedVelocityLabel->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, suggestedVelocityLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        suggestedVelocity = new QLabel(formLayoutWidget);
        suggestedVelocity->setObjectName(QString::fromUtf8("suggestedVelocity"));
        suggestedVelocity->setFont(font1);
        suggestedVelocity->setFrameShape(QFrame::WinPanel);

        horizontalLayout_3->addWidget(suggestedVelocity);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_3);

        speedLimitLabel = new QLabel(formLayoutWidget);
        speedLimitLabel->setObjectName(QString::fromUtf8("speedLimitLabel"));
        speedLimitLabel->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, speedLimitLabel);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        speedLimit = new QLabel(formLayoutWidget);
        speedLimit->setObjectName(QString::fromUtf8("speedLimit"));
        speedLimit->setFont(font1);
        speedLimit->setFrameShape(QFrame::WinPanel);

        horizontalLayout_4->addWidget(speedLimit);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout_4->addWidget(label_4);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_4);

        authorityLabel = new QLabel(formLayoutWidget);
        authorityLabel->setObjectName(QString::fromUtf8("authorityLabel"));
        authorityLabel->setFont(font1);

        formLayout->setWidget(4, QFormLayout::LabelRole, authorityLabel);

        beaconLabel = new QLabel(formLayoutWidget);
        beaconLabel->setObjectName(QString::fromUtf8("beaconLabel"));
        beaconLabel->setFont(font1);

        formLayout->setWidget(5, QFormLayout::LabelRole, beaconLabel);

        beacons = new QLabel(formLayoutWidget);
        beacons->setObjectName(QString::fromUtf8("beacons"));
        beacons->setFont(font1);
        beacons->setFrameShape(QFrame::WinPanel);

        formLayout->setWidget(5, QFormLayout::FieldRole, beacons);

        incomingStationLabel = new QLabel(formLayoutWidget);
        incomingStationLabel->setObjectName(QString::fromUtf8("incomingStationLabel"));
        incomingStationLabel->setFont(font1);

        formLayout->setWidget(6, QFormLayout::LabelRole, incomingStationLabel);

        incomingStation = new QLabel(formLayoutWidget);
        incomingStation->setObjectName(QString::fromUtf8("incomingStation"));
        incomingStation->setFont(font1);
        incomingStation->setFrameShape(QFrame::WinPanel);

        formLayout->setWidget(6, QFormLayout::FieldRole, incomingStation);

        serviceBrakeLabel = new QLabel(formLayoutWidget);
        serviceBrakeLabel->setObjectName(QString::fromUtf8("serviceBrakeLabel"));
        serviceBrakeLabel->setFont(font1);

        formLayout->setWidget(7, QFormLayout::LabelRole, serviceBrakeLabel);

        serviceBrake = new QPushButton(formLayoutWidget);
        serviceBrake->setObjectName(QString::fromUtf8("serviceBrake"));
        serviceBrake->setFont(font1);

        formLayout->setWidget(7, QFormLayout::FieldRole, serviceBrake);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        authority = new QLabel(formLayoutWidget);
        authority->setObjectName(QString::fromUtf8("authority"));
        authority->setFont(font1);
        authority->setFrameShape(QFrame::WinPanel);

        horizontalLayout_5->addWidget(authority);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        horizontalLayout_5->addWidget(label_5);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_5);


        retranslateUi(transitData);

        QMetaObject::connectSlotsByName(transitData);
    } // setupUi

    void retranslateUi(QDialog *transitData)
    {
        transitData->setWindowTitle(QCoreApplication::translate("transitData", "Driver Window", nullptr));
        driverEmergencyBrake->setText(QCoreApplication::translate("transitData", "Emergency Brake", nullptr));
        commandedVelocityLabel->setText(QCoreApplication::translate("transitData", "Commanded Velocty", nullptr));
        commandeVelocity->setText(QString());
        label->setText(QCoreApplication::translate("transitData", "mph", nullptr));
        currentyVelcotyLabel->setText(QCoreApplication::translate("transitData", "Current Velocty", nullptr));
        currentVelocity->setText(QString());
        label_2->setText(QCoreApplication::translate("transitData", "mph", nullptr));
        suggestedVelocityLabel->setText(QCoreApplication::translate("transitData", "Suggested Velocty", nullptr));
        suggestedVelocity->setText(QString());
        label_3->setText(QCoreApplication::translate("transitData", "mph", nullptr));
        speedLimitLabel->setText(QCoreApplication::translate("transitData", "Speed Limit", nullptr));
        speedLimit->setText(QString());
        label_4->setText(QCoreApplication::translate("transitData", "mph", nullptr));
        authorityLabel->setText(QCoreApplication::translate("transitData", "Authority", nullptr));
        beaconLabel->setText(QCoreApplication::translate("transitData", "Beacons", nullptr));
        beacons->setText(QString());
        incomingStationLabel->setText(QCoreApplication::translate("transitData", "Incoming Station", nullptr));
        incomingStation->setText(QString());
        serviceBrakeLabel->setText(QCoreApplication::translate("transitData", "Service Brake", nullptr));
        serviceBrake->setText(QCoreApplication::translate("transitData", "Service Brake", nullptr));
        authority->setText(QString());
        label_5->setText(QCoreApplication::translate("transitData", "feet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class transitData: public Ui_transitData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSITDATA_H
