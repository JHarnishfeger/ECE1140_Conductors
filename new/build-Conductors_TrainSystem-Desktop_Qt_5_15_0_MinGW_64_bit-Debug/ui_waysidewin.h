/********************************************************************************
** Form generated from reading UI file 'waysidewin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAYSIDEWIN_H
#define UI_WAYSIDEWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaysideWin
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QFrame *line;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *SwitchLeft;
    QPushButton *SwitchRight;
    QListWidget *SwitchList;
    QListWidget *CrossingList;
    QFrame *line_2;
    QLabel *label_2;
    QPushButton *CrossingOff;
    QPushButton *CrossingOn;
    QFrame *line_3;
    QLineEdit *PLCFile;
    QPushButton *ImportPLC;
    QLabel *label_9;
    QLabel *label_10;
    QFrame *line_4;
    QLabel *label_13;
    QListWidget *TrainList;
    QListWidget *BrokenRailList;
    QListWidget *AlertList;

    void setupUi(QWidget *WaysideWin)
    {
        if (WaysideWin->objectName().isEmpty())
            WaysideWin->setObjectName(QString::fromUtf8("WaysideWin"));
        WaysideWin->resize(450, 467);
        gridLayout = new QGridLayout(WaysideWin);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(WaysideWin);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 2);

        line = new QFrame(WaysideWin);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 5, 2, 1);

        label_7 = new QLabel(WaysideWin);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 6, 1, 1);

        label_8 = new QLabel(WaysideWin);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 7, 1, 1);

        SwitchLeft = new QPushButton(WaysideWin);
        SwitchLeft->setObjectName(QString::fromUtf8("SwitchLeft"));

        gridLayout->addWidget(SwitchLeft, 1, 1, 1, 2);

        SwitchRight = new QPushButton(WaysideWin);
        SwitchRight->setObjectName(QString::fromUtf8("SwitchRight"));

        gridLayout->addWidget(SwitchRight, 1, 3, 1, 2);

        SwitchList = new QListWidget(WaysideWin);
        SwitchList->setObjectName(QString::fromUtf8("SwitchList"));

        gridLayout->addWidget(SwitchList, 1, 6, 6, 1);

        CrossingList = new QListWidget(WaysideWin);
        CrossingList->setObjectName(QString::fromUtf8("CrossingList"));

        gridLayout->addWidget(CrossingList, 1, 7, 6, 1);

        line_2 = new QFrame(WaysideWin);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 2, 0, 1, 6);

        label_2 = new QLabel(WaysideWin);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 1, 1, 2);

        CrossingOff = new QPushButton(WaysideWin);
        CrossingOff->setObjectName(QString::fromUtf8("CrossingOff"));

        gridLayout->addWidget(CrossingOff, 4, 1, 1, 2);

        CrossingOn = new QPushButton(WaysideWin);
        CrossingOn->setObjectName(QString::fromUtf8("CrossingOn"));

        gridLayout->addWidget(CrossingOn, 4, 3, 1, 2);

        line_3 = new QFrame(WaysideWin);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 5, 0, 1, 6);

        PLCFile = new QLineEdit(WaysideWin);
        PLCFile->setObjectName(QString::fromUtf8("PLCFile"));

        gridLayout->addWidget(PLCFile, 6, 2, 1, 2);

        ImportPLC = new QPushButton(WaysideWin);
        ImportPLC->setObjectName(QString::fromUtf8("ImportPLC"));

        gridLayout->addWidget(ImportPLC, 7, 2, 2, 2);

        label_9 = new QLabel(WaysideWin);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 7, 6, 2, 1);

        label_10 = new QLabel(WaysideWin);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 7, 7, 2, 1);

        line_4 = new QFrame(WaysideWin);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 8, 0, 2, 2);

        label_13 = new QLabel(WaysideWin);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 9, 1, 2, 3);

        TrainList = new QListWidget(WaysideWin);
        TrainList->setObjectName(QString::fromUtf8("TrainList"));

        gridLayout->addWidget(TrainList, 9, 6, 3, 1);

        BrokenRailList = new QListWidget(WaysideWin);
        BrokenRailList->setObjectName(QString::fromUtf8("BrokenRailList"));

        gridLayout->addWidget(BrokenRailList, 9, 7, 3, 1);

        AlertList = new QListWidget(WaysideWin);
        AlertList->setObjectName(QString::fromUtf8("AlertList"));

        gridLayout->addWidget(AlertList, 11, 1, 1, 3);


        retranslateUi(WaysideWin);

        QMetaObject::connectSlotsByName(WaysideWin);
    } // setupUi

    void retranslateUi(QWidget *WaysideWin)
    {
        WaysideWin->setWindowTitle(QCoreApplication::translate("WaysideWin", "Form", nullptr));
        label->setText(QCoreApplication::translate("WaysideWin", "Switch", nullptr));
        label_7->setText(QCoreApplication::translate("WaysideWin", "Switches", nullptr));
        label_8->setText(QCoreApplication::translate("WaysideWin", "Crossings", nullptr));
        SwitchLeft->setText(QCoreApplication::translate("WaysideWin", "Left", nullptr));
        SwitchRight->setText(QCoreApplication::translate("WaysideWin", "Right", nullptr));
        label_2->setText(QCoreApplication::translate("WaysideWin", "Crossing", nullptr));
        CrossingOff->setText(QCoreApplication::translate("WaysideWin", "Off", nullptr));
        CrossingOn->setText(QCoreApplication::translate("WaysideWin", "On", nullptr));
        ImportPLC->setText(QCoreApplication::translate("WaysideWin", "Import PLC Program", nullptr));
        label_9->setText(QCoreApplication::translate("WaysideWin", "Trains", nullptr));
        label_10->setText(QCoreApplication::translate("WaysideWin", "Broken Rails", nullptr));
        label_13->setText(QCoreApplication::translate("WaysideWin", "Alerts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WaysideWin: public Ui_WaysideWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAYSIDEWIN_H
