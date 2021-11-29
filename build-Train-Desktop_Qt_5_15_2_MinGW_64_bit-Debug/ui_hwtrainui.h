/********************************************************************************
** Form generated from reading UI file 'hwtrainui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HWTRAINUI_H
#define UI_HWTRAINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HWTrainUI
{
public:
    QWidget *centralwidget;
    QLabel *Kp;
    QLineEdit *KiText;
    QLabel *Engineer;
    QLineEdit *KpText;
    QPushButton *enterButton;
    QLabel *Ki;
    QComboBox *ports;
    QLineEdit *commandedSpeed;
    QFrame *line;
    QFrame *line_2;
    QPushButton *connectButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HWTrainUI)
    {
        if (HWTrainUI->objectName().isEmpty())
            HWTrainUI->setObjectName(QString::fromUtf8("HWTrainUI"));
        HWTrainUI->resize(751, 265);
        centralwidget = new QWidget(HWTrainUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Kp = new QLabel(centralwidget);
        Kp->setObjectName(QString::fromUtf8("Kp"));
        Kp->setGeometry(QRect(500, 100, 21, 16));
        KiText = new QLineEdit(centralwidget);
        KiText->setObjectName(QString::fromUtf8("KiText"));
        KiText->setGeometry(QRect(610, 120, 113, 20));
        Engineer = new QLabel(centralwidget);
        Engineer->setObjectName(QString::fromUtf8("Engineer"));
        Engineer->setGeometry(QRect(450, 0, 311, 81));
        Engineer->setScaledContents(false);
        KpText = new QLineEdit(centralwidget);
        KpText->setObjectName(QString::fromUtf8("KpText"));
        KpText->setGeometry(QRect(450, 120, 113, 20));
        enterButton = new QPushButton(centralwidget);
        enterButton->setObjectName(QString::fromUtf8("enterButton"));
        enterButton->setGeometry(QRect(550, 160, 75, 23));
        Ki = new QLabel(centralwidget);
        Ki->setObjectName(QString::fromUtf8("Ki"));
        Ki->setGeometry(QRect(660, 100, 16, 16));
        ports = new QComboBox(centralwidget);
        ports->setObjectName(QString::fromUtf8("ports"));
        ports->setGeometry(QRect(250, 150, 101, 22));
        commandedSpeed = new QLineEdit(centralwidget);
        commandedSpeed->setObjectName(QString::fromUtf8("commandedSpeed"));
        commandedSpeed->setGeometry(QRect(160, 40, 113, 20));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(417, 220, 381, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(410, 0, 20, 231));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(60, 140, 131, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 20, 101, 16));
        HWTrainUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HWTrainUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 751, 21));
        HWTrainUI->setMenuBar(menubar);
        statusbar = new QStatusBar(HWTrainUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HWTrainUI->setStatusBar(statusbar);

        retranslateUi(HWTrainUI);

        QMetaObject::connectSlotsByName(HWTrainUI);
    } // setupUi

    void retranslateUi(QMainWindow *HWTrainUI)
    {
        HWTrainUI->setWindowTitle(QCoreApplication::translate("HWTrainUI", "MainWindow", nullptr));
        Kp->setText(QCoreApplication::translate("HWTrainUI", "Kp", nullptr));
        KiText->setText(QCoreApplication::translate("HWTrainUI", "01000", nullptr));
        Engineer->setText(QCoreApplication::translate("HWTrainUI", "<html><head/><body><p><span style=\" font-size:36pt; font-weight:600;\">Engineer UI</span></p></body></html>", nullptr));
        KpText->setText(QCoreApplication::translate("HWTrainUI", "01000", nullptr));
        enterButton->setText(QCoreApplication::translate("HWTrainUI", "Enter", nullptr));
        Ki->setText(QCoreApplication::translate("HWTrainUI", "Ki", nullptr));
        connectButton->setText(QCoreApplication::translate("HWTrainUI", "Connect", nullptr));
        label->setText(QCoreApplication::translate("HWTrainUI", "Commanded Speed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HWTrainUI: public Ui_HWTrainUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HWTRAINUI_H
