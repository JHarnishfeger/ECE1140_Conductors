/********************************************************************************
** Form generated from reading UI file 'trainInformation.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAININFORMATION_H
#define UI_TRAININFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trainInformation
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *powerLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *power;
    QLabel *label;
    QLabel *lengthLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *length;
    QLabel *label_2;
    QLabel *heightLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *height;
    QLabel *label_3;
    QLabel *widthLabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *width;
    QLabel *label_4;
    QLabel *massLabel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *mass;
    QLabel *label_5;
    QLabel *accelerationLabel;
    QLabel *crewmembersLabel;
    QLabel *passengerLabel;
    QHBoxLayout *horizontalLayout_6;
    QLabel *acceleration;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *crewmembers;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *passengers;
    QLabel *label_8;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QFrame *line;
    QLabel *carNumber;

    void setupUi(QDialog *trainInformation)
    {
        if (trainInformation->objectName().isEmpty())
            trainInformation->setObjectName(QString::fromUtf8("trainInformation"));
        trainInformation->resize(317, 445);
        formLayoutWidget = new QWidget(trainInformation);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 301, 381));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(6);
        formLayout->setVerticalSpacing(24);
        formLayout->setContentsMargins(0, 0, 0, 0);
        powerLabel = new QLabel(formLayoutWidget);
        powerLabel->setObjectName(QString::fromUtf8("powerLabel"));
        QFont font;
        font.setPointSize(12);
        powerLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, powerLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        power = new QLabel(formLayoutWidget);
        power->setObjectName(QString::fromUtf8("power"));
        power->setFont(font);
        power->setFrameShape(QFrame::WinPanel);

        horizontalLayout->addWidget(power);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        lengthLabel = new QLabel(formLayoutWidget);
        lengthLabel->setObjectName(QString::fromUtf8("lengthLabel"));
        lengthLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, lengthLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        length = new QLabel(formLayoutWidget);
        length->setObjectName(QString::fromUtf8("length"));
        length->setFont(font);
        length->setFrameShape(QFrame::WinPanel);

        horizontalLayout_2->addWidget(length);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_2);

        heightLabel = new QLabel(formLayoutWidget);
        heightLabel->setObjectName(QString::fromUtf8("heightLabel"));
        heightLabel->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, heightLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        height = new QLabel(formLayoutWidget);
        height->setObjectName(QString::fromUtf8("height"));
        height->setFont(font);
        height->setFrameShape(QFrame::WinPanel);

        horizontalLayout_3->addWidget(height);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_3);

        widthLabel = new QLabel(formLayoutWidget);
        widthLabel->setObjectName(QString::fromUtf8("widthLabel"));
        widthLabel->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, widthLabel);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        width = new QLabel(formLayoutWidget);
        width->setObjectName(QString::fromUtf8("width"));
        width->setFont(font);
        width->setFrameShape(QFrame::WinPanel);

        horizontalLayout_4->addWidget(width);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_4);

        massLabel = new QLabel(formLayoutWidget);
        massLabel->setObjectName(QString::fromUtf8("massLabel"));
        massLabel->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, massLabel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        mass = new QLabel(formLayoutWidget);
        mass->setObjectName(QString::fromUtf8("mass"));
        mass->setFont(font);
        mass->setFrameShape(QFrame::WinPanel);

        horizontalLayout_5->addWidget(mass);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_5);

        accelerationLabel = new QLabel(formLayoutWidget);
        accelerationLabel->setObjectName(QString::fromUtf8("accelerationLabel"));
        accelerationLabel->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, accelerationLabel);

        crewmembersLabel = new QLabel(formLayoutWidget);
        crewmembersLabel->setObjectName(QString::fromUtf8("crewmembersLabel"));
        crewmembersLabel->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, crewmembersLabel);

        passengerLabel = new QLabel(formLayoutWidget);
        passengerLabel->setObjectName(QString::fromUtf8("passengerLabel"));
        passengerLabel->setFont(font);

        formLayout->setWidget(7, QFormLayout::LabelRole, passengerLabel);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        acceleration = new QLabel(formLayoutWidget);
        acceleration->setObjectName(QString::fromUtf8("acceleration"));
        acceleration->setFont(font);
        acceleration->setFrameShape(QFrame::WinPanel);

        horizontalLayout_6->addWidget(acceleration);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_6->addWidget(label_6);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        crewmembers = new QLabel(formLayoutWidget);
        crewmembers->setObjectName(QString::fromUtf8("crewmembers"));
        crewmembers->setFont(font);
        crewmembers->setFrameShape(QFrame::WinPanel);

        horizontalLayout_7->addWidget(crewmembers);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        horizontalLayout_7->addWidget(label_7);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        passengers = new QLabel(formLayoutWidget);
        passengers->setObjectName(QString::fromUtf8("passengers"));
        passengers->setFont(font);
        passengers->setFrameShape(QFrame::WinPanel);

        horizontalLayout_8->addWidget(passengers);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        horizontalLayout_8->addWidget(label_8);


        formLayout->setLayout(7, QFormLayout::FieldRole, horizontalLayout_8);

        horizontalLayoutWidget_4 = new QWidget(trainInformation);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(210, 410, 81, 31));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(horizontalLayoutWidget_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_9->setFont(font1);

        horizontalLayout_9->addWidget(label_9);

        line = new QFrame(horizontalLayoutWidget_4);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_9->addWidget(line);

        carNumber = new QLabel(horizontalLayoutWidget_4);
        carNumber->setObjectName(QString::fromUtf8("carNumber"));
        carNumber->setFont(font);

        horizontalLayout_9->addWidget(carNumber);


        retranslateUi(trainInformation);

        QMetaObject::connectSlotsByName(trainInformation);
    } // setupUi

    void retranslateUi(QDialog *trainInformation)
    {
        trainInformation->setWindowTitle(QCoreApplication::translate("trainInformation", "Driver Window", nullptr));
        powerLabel->setText(QCoreApplication::translate("trainInformation", "Power", nullptr));
        power->setText(QString());
        label->setText(QCoreApplication::translate("trainInformation", "W", nullptr));
        lengthLabel->setText(QCoreApplication::translate("trainInformation", "Length", nullptr));
        length->setText(QString());
        label_2->setText(QCoreApplication::translate("trainInformation", "ft", nullptr));
        heightLabel->setText(QCoreApplication::translate("trainInformation", "Height", nullptr));
        height->setText(QString());
        label_3->setText(QCoreApplication::translate("trainInformation", "ft", nullptr));
        widthLabel->setText(QCoreApplication::translate("trainInformation", "Width", nullptr));
        width->setText(QString());
        label_4->setText(QCoreApplication::translate("trainInformation", "ft", nullptr));
        massLabel->setText(QCoreApplication::translate("trainInformation", "Mass", nullptr));
        mass->setText(QString());
        label_5->setText(QCoreApplication::translate("trainInformation", "lbs", nullptr));
        accelerationLabel->setText(QCoreApplication::translate("trainInformation", "Acceleration", nullptr));
        crewmembersLabel->setText(QCoreApplication::translate("trainInformation", "Crewmembers", nullptr));
        passengerLabel->setText(QCoreApplication::translate("trainInformation", "Passengers", nullptr));
        acceleration->setText(QString());
        label_6->setText(QCoreApplication::translate("trainInformation", "mph\302\262", nullptr));
        crewmembers->setText(QString());
        label_7->setText(QCoreApplication::translate("trainInformation", "people", nullptr));
        passengers->setText(QString());
        label_8->setText(QCoreApplication::translate("trainInformation", "people", nullptr));
        label_9->setText(QCoreApplication::translate("trainInformation", "Car#", nullptr));
        carNumber->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class trainInformation: public Ui_trainInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAININFORMATION_H
