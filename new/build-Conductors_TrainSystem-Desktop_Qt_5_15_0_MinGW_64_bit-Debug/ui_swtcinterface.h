/********************************************************************************
** Form generated from reading UI file 'swtcinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWTCINTERFACE_H
#define UI_SWTCINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SWTCInterface
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *CreateWaysides;
    QSpinBox *WaysideNum;
    QPushButton *DesignateHWWayside;
    QCheckBox *autoMode;
    QLabel *label_13;
    QListWidget *WaysideList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SWTCInterface)
    {
        if (SWTCInterface->objectName().isEmpty())
            SWTCInterface->setObjectName(QString::fromUtf8("SWTCInterface"));
        SWTCInterface->resize(219, 305);
        centralwidget = new QWidget(SWTCInterface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CreateWaysides = new QPushButton(centralwidget);
        CreateWaysides->setObjectName(QString::fromUtf8("CreateWaysides"));

        gridLayout->addWidget(CreateWaysides, 0, 0, 1, 1);

        WaysideNum = new QSpinBox(centralwidget);
        WaysideNum->setObjectName(QString::fromUtf8("WaysideNum"));

        gridLayout->addWidget(WaysideNum, 0, 1, 1, 1);

        DesignateHWWayside = new QPushButton(centralwidget);
        DesignateHWWayside->setObjectName(QString::fromUtf8("DesignateHWWayside"));

        gridLayout->addWidget(DesignateHWWayside, 1, 0, 1, 2);

        autoMode = new QCheckBox(centralwidget);
        autoMode->setObjectName(QString::fromUtf8("autoMode"));

        gridLayout->addWidget(autoMode, 2, 0, 1, 1);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 3, 0, 1, 2);

        WaysideList = new QListWidget(centralwidget);
        WaysideList->setObjectName(QString::fromUtf8("WaysideList"));

        gridLayout->addWidget(WaysideList, 4, 0, 1, 2);

        SWTCInterface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SWTCInterface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 219, 19));
        SWTCInterface->setMenuBar(menubar);
        statusbar = new QStatusBar(SWTCInterface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SWTCInterface->setStatusBar(statusbar);

        retranslateUi(SWTCInterface);

        QMetaObject::connectSlotsByName(SWTCInterface);
    } // setupUi

    void retranslateUi(QMainWindow *SWTCInterface)
    {
        SWTCInterface->setWindowTitle(QCoreApplication::translate("SWTCInterface", "SWTCInterface", nullptr));
        CreateWaysides->setText(QCoreApplication::translate("SWTCInterface", "Create Waysides", nullptr));
        DesignateHWWayside->setText(QCoreApplication::translate("SWTCInterface", "Designate HW Wayside", nullptr));
        autoMode->setText(QCoreApplication::translate("SWTCInterface", "Automatic Mode", nullptr));
        label_13->setText(QCoreApplication::translate("SWTCInterface", "Waysides", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SWTCInterface: public Ui_SWTCInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWTCINTERFACE_H
