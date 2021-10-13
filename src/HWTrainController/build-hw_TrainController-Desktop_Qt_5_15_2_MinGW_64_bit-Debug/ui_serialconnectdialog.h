/********************************************************************************
** Form generated from reading UI file 'serialconnectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALCONNECTDIALOG_H
#define UI_SERIALCONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialConnectDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *connectButton;
    QComboBox *trainPortsCombo;

    void setupUi(QDialog *SerialConnectDialog)
    {
        if (SerialConnectDialog->objectName().isEmpty())
            SerialConnectDialog->setObjectName(QString::fromUtf8("SerialConnectDialog"));
        SerialConnectDialog->resize(243, 144);
        layoutWidget = new QWidget(SerialConnectDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 60, 152, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        connectButton = new QPushButton(layoutWidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        horizontalLayout->addWidget(connectButton);

        trainPortsCombo = new QComboBox(layoutWidget);
        trainPortsCombo->setObjectName(QString::fromUtf8("trainPortsCombo"));

        horizontalLayout->addWidget(trainPortsCombo);


        retranslateUi(SerialConnectDialog);

        QMetaObject::connectSlotsByName(SerialConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *SerialConnectDialog)
    {
        SerialConnectDialog->setWindowTitle(QCoreApplication::translate("SerialConnectDialog", "Dialog", nullptr));
        connectButton->setText(QCoreApplication::translate("SerialConnectDialog", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerialConnectDialog: public Ui_SerialConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALCONNECTDIALOG_H
