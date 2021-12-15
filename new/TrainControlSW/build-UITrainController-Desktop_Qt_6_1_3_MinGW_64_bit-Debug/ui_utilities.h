/********************************************************************************
** Form generated from reading UI file 'utilities.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UTILITIES_H
#define UI_UTILITIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_utilities
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *commandedVelocityLabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QSlider *leftDoors;
    QLabel *label_8;
    QLabel *currentyVelcotyLabel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSlider *rightDoors;
    QLabel *label_7;
    QLabel *suggestedVelocityLabel;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *interiorLights;
    QLabel *label_4;
    QLabel *speedLimitLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *exteriorLights;
    QLabel *label_2;
    QLabel *authorityLabel;
    QLabel *beaconLabel;
    QLineEdit *stationAnnounce;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *temperature;
    QLabel *label_9;

    void setupUi(QDialog *utilities)
    {
        if (utilities->objectName().isEmpty())
            utilities->setObjectName(QString::fromUtf8("utilities"));
        utilities->resize(348, 414);
        formLayoutWidget = new QWidget(utilities);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 321, 371));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(6);
        formLayout->setVerticalSpacing(36);
        formLayout->setContentsMargins(0, 0, 0, 0);
        commandedVelocityLabel = new QLabel(formLayoutWidget);
        commandedVelocityLabel->setObjectName(QString::fromUtf8("commandedVelocityLabel"));
        QFont font;
        font.setPointSize(12);
        commandedVelocityLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, commandedVelocityLabel);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_6->setFont(font1);

        horizontalLayout_4->addWidget(label_6);

        leftDoors = new QSlider(formLayoutWidget);
        leftDoors->setObjectName(QString::fromUtf8("leftDoors"));
        leftDoors->setFont(font);
        leftDoors->setAutoFillBackground(false);
        leftDoors->setMaximum(1);
        leftDoors->setPageStep(1);
        leftDoors->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(leftDoors);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);

        horizontalLayout_4->addWidget(label_8);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_4);

        currentyVelcotyLabel = new QLabel(formLayoutWidget);
        currentyVelcotyLabel->setObjectName(QString::fromUtf8("currentyVelcotyLabel"));
        currentyVelcotyLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, currentyVelcotyLabel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        horizontalLayout_5->addWidget(label_5);

        rightDoors = new QSlider(formLayoutWidget);
        rightDoors->setObjectName(QString::fromUtf8("rightDoors"));
        rightDoors->setFont(font);
        rightDoors->setAutoFillBackground(false);
        rightDoors->setMaximum(1);
        rightDoors->setPageStep(1);
        rightDoors->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(rightDoors);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        horizontalLayout_5->addWidget(label_7);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_5);

        suggestedVelocityLabel = new QLabel(formLayoutWidget);
        suggestedVelocityLabel->setObjectName(QString::fromUtf8("suggestedVelocityLabel"));
        suggestedVelocityLabel->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, suggestedVelocityLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);

        interiorLights = new QSlider(formLayoutWidget);
        interiorLights->setObjectName(QString::fromUtf8("interiorLights"));
        interiorLights->setFont(font);
        interiorLights->setAutoFillBackground(false);
        interiorLights->setMaximum(1);
        interiorLights->setPageStep(1);
        interiorLights->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(interiorLights);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout_3->addWidget(label_4);


        horizontalLayout_2->addLayout(horizontalLayout_3);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_2);

        speedLimitLabel = new QLabel(formLayoutWidget);
        speedLimitLabel->setObjectName(QString::fromUtf8("speedLimitLabel"));
        speedLimitLabel->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, speedLimitLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        exteriorLights = new QSlider(formLayoutWidget);
        exteriorLights->setObjectName(QString::fromUtf8("exteriorLights"));
        exteriorLights->setFont(font);
        exteriorLights->setAutoFillBackground(false);
        exteriorLights->setMaximum(1);
        exteriorLights->setPageStep(1);
        exteriorLights->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(exteriorLights);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout);

        authorityLabel = new QLabel(formLayoutWidget);
        authorityLabel->setObjectName(QString::fromUtf8("authorityLabel"));
        authorityLabel->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, authorityLabel);

        beaconLabel = new QLabel(formLayoutWidget);
        beaconLabel->setObjectName(QString::fromUtf8("beaconLabel"));
        beaconLabel->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, beaconLabel);

        stationAnnounce = new QLineEdit(formLayoutWidget);
        stationAnnounce->setObjectName(QString::fromUtf8("stationAnnounce"));
        stationAnnounce->setFont(font);

        formLayout->setWidget(5, QFormLayout::FieldRole, stationAnnounce);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        temperature = new QSpinBox(formLayoutWidget);
        temperature->setObjectName(QString::fromUtf8("temperature"));
        temperature->setEnabled(true);
        temperature->setFont(font);
        temperature->setMinimum(60);
        temperature->setMaximum(90);

        horizontalLayout_6->addWidget(temperature);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        horizontalLayout_6->addWidget(label_9);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_6);


        retranslateUi(utilities);

        QMetaObject::connectSlotsByName(utilities);
    } // setupUi

    void retranslateUi(QDialog *utilities)
    {
        utilities->setWindowTitle(QCoreApplication::translate("utilities", "Driver Window", nullptr));
        commandedVelocityLabel->setText(QCoreApplication::translate("utilities", "Left Doors", nullptr));
        label_6->setText(QCoreApplication::translate("utilities", "CLOSED", nullptr));
        label_8->setText(QCoreApplication::translate("utilities", "OPEN", nullptr));
        currentyVelcotyLabel->setText(QCoreApplication::translate("utilities", "Right Doors", nullptr));
        label_5->setText(QCoreApplication::translate("utilities", "CLOSED", nullptr));
        label_7->setText(QCoreApplication::translate("utilities", "OPEN", nullptr));
        suggestedVelocityLabel->setText(QCoreApplication::translate("utilities", "Interior Lights", nullptr));
        label_3->setText(QCoreApplication::translate("utilities", "OFF", nullptr));
        label_4->setText(QCoreApplication::translate("utilities", "ON", nullptr));
        speedLimitLabel->setText(QCoreApplication::translate("utilities", "Exerior Lights", nullptr));
        label->setText(QCoreApplication::translate("utilities", "OFF", nullptr));
        label_2->setText(QCoreApplication::translate("utilities", "ON", nullptr));
        authorityLabel->setText(QCoreApplication::translate("utilities", "Temperature", nullptr));
        beaconLabel->setText(QCoreApplication::translate("utilities", "Announce Station", nullptr));
        label_9->setText(QCoreApplication::translate("utilities", "\302\260F", nullptr));
    } // retranslateUi

};

namespace Ui {
    class utilities: public Ui_utilities {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UTILITIES_H
