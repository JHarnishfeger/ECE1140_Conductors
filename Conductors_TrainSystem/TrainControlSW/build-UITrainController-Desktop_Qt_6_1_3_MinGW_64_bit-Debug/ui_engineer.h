/********************************************************************************
** Form generated from reading UI file 'engineer.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENGINEER_H
#define UI_ENGINEER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_engineer
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLabel *label_7;
    QLineEdit *kp;
    QLineEdit *ki;

    void setupUi(QDialog *engineer)
    {
        if (engineer->objectName().isEmpty())
            engineer->setObjectName(QString::fromUtf8("engineer"));
        engineer->resize(286, 117);
        formLayoutWidget = new QWidget(engineer);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 30, 231, 66));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(12);
        formLayout->setVerticalSpacing(24);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_4->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_7);

        kp = new QLineEdit(formLayoutWidget);
        kp->setObjectName(QString::fromUtf8("kp"));

        formLayout->setWidget(0, QFormLayout::FieldRole, kp);

        ki = new QLineEdit(formLayoutWidget);
        ki->setObjectName(QString::fromUtf8("ki"));

        formLayout->setWidget(1, QFormLayout::FieldRole, ki);


        retranslateUi(engineer);

        QMetaObject::connectSlotsByName(engineer);
    } // setupUi

    void retranslateUi(QDialog *engineer)
    {
        engineer->setWindowTitle(QCoreApplication::translate("engineer", "Driver Window", nullptr));
        label_4->setText(QCoreApplication::translate("engineer", "KP", nullptr));
        label_7->setText(QCoreApplication::translate("engineer", "KI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class engineer: public Ui_engineer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGINEER_H
