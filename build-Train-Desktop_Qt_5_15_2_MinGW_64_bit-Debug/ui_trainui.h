/********************************************************************************
** Form generated from reading UI file 'trainui.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINUI_H
#define UI_TRAINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trainUI
{
public:
    QWidget *centralwidget;
    QLabel *label_16;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *BrakeFail;
    QLabel *label_2;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_17;
    QLCDNumber *lcdNumber_7;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_15;
    QLCDNumber *lcdNumber_6;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *EngineFail;
    QLabel *label;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLCDNumber *lcdNumber;
    QLabel *label_5;
    QLCDNumber *lcdNumber_2;
    QLabel *label_6;
    QLCDNumber *lcdNumber_3;
    QLabel *label_7;
    QLCDNumber *lcdNumber_4;
    QLabel *label_8;
    QLCDNumber *lcdNumber_5;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_9;
    QProgressBar *progressBar;
    QLabel *label_10;
    QProgressBar *progressBar_2;
    QLabel *label_11;
    QProgressBar *progressBar_3;
    QLabel *label_12;
    QProgressBar *progressBar_4;
    QLabel *label_13;
    QProgressBar *progressBar_5;
    QLabel *label_14;
    QProgressBar *progressBar_6;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *SignalFail;
    QLabel *label_3;
    QSlider *Temp_Change;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *trainUI)
    {
        if (trainUI->objectName().isEmpty())
            trainUI->setObjectName(QString::fromUtf8("trainUI"));
        trainUI->resize(800, 600);
        centralwidget = new QWidget(trainUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 190, 771, 161));
        label_16->setBaseSize(QSize(10, 10));
        QPalette palette;
        QBrush brush(QColor(242, 11, 0, 216));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(242, 11, 0, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        QBrush brush2(QColor(255, 255, 255, 63));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush3(QColor(255, 255, 255, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        label_16->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(50);
        font.setBold(true);
        font.setWeight(75);
        label_16->setFont(font);
        label_16->setLayoutDirection(Qt::LeftToRight);
        label_16->setAutoFillBackground(false);
        label_16->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(220, 364, 181, 61));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        BrakeFail = new QPushButton(verticalLayoutWidget_2);
        BrakeFail->setObjectName(QString::fromUtf8("BrakeFail"));

        verticalLayout_2->addWidget(BrakeFail);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 440, 771, 81));
        QPalette palette1;
        QBrush brush4(QColor(255, 0, 12, 216));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        pushButton->setPalette(palette1);
        QFont font1;
        font1.setPointSize(36);
        pushButton->setFont(font1);
        verticalLayoutWidget_7 = new QWidget(centralwidget);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(220, 200, 160, 80));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(verticalLayoutWidget_7);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_7->addWidget(label_17, 0, Qt::AlignHCenter);

        lcdNumber_7 = new QLCDNumber(verticalLayoutWidget_7);
        lcdNumber_7->setObjectName(QString::fromUtf8("lcdNumber_7"));

        verticalLayout_7->addWidget(lcdNumber_7);

        verticalLayoutWidget_6 = new QWidget(centralwidget);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(410, 200, 189, 80));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(verticalLayoutWidget_6);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_6->addWidget(label_15, 0, Qt::AlignHCenter);

        lcdNumber_6 = new QLCDNumber(verticalLayoutWidget_6);
        lcdNumber_6->setObjectName(QString::fromUtf8("lcdNumber_6"));

        verticalLayout_6->addWidget(lcdNumber_6);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 364, 191, 61));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        EngineFail = new QPushButton(verticalLayoutWidget);
        EngineFail->setObjectName(QString::fromUtf8("EngineFail"));

        verticalLayout->addWidget(EngineFail);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 0, 191, 352));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        lcdNumber = new QLCDNumber(verticalLayoutWidget_4);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        verticalLayout_4->addWidget(lcdNumber);

        label_5 = new QLabel(verticalLayoutWidget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5, 0, Qt::AlignHCenter);

        lcdNumber_2 = new QLCDNumber(verticalLayoutWidget_4);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));

        verticalLayout_4->addWidget(lcdNumber_2);

        label_6 = new QLabel(verticalLayoutWidget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_4->addWidget(label_6, 0, Qt::AlignHCenter);

        lcdNumber_3 = new QLCDNumber(verticalLayoutWidget_4);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));

        verticalLayout_4->addWidget(lcdNumber_3);

        label_7 = new QLabel(verticalLayoutWidget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_4->addWidget(label_7, 0, Qt::AlignHCenter);

        lcdNumber_4 = new QLCDNumber(verticalLayoutWidget_4);
        lcdNumber_4->setObjectName(QString::fromUtf8("lcdNumber_4"));

        verticalLayout_4->addWidget(lcdNumber_4);

        label_8 = new QLabel(verticalLayoutWidget_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8, 0, Qt::AlignHCenter);

        lcdNumber_5 = new QLCDNumber(verticalLayoutWidget_4);
        lcdNumber_5->setObjectName(QString::fromUtf8("lcdNumber_5"));

        verticalLayout_4->addWidget(lcdNumber_5);

        verticalLayoutWidget_5 = new QWidget(centralwidget);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(620, 10, 162, 421));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_5->addWidget(label_9);

        progressBar = new QProgressBar(verticalLayoutWidget_5);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout_5->addWidget(progressBar);

        label_10 = new QLabel(verticalLayoutWidget_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_5->addWidget(label_10, 0, Qt::AlignHCenter);

        progressBar_2 = new QProgressBar(verticalLayoutWidget_5);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setValue(24);

        verticalLayout_5->addWidget(progressBar_2);

        label_11 = new QLabel(verticalLayoutWidget_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_5->addWidget(label_11, 0, Qt::AlignHCenter);

        progressBar_3 = new QProgressBar(verticalLayoutWidget_5);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setMinimum(0);
        progressBar_3->setValue(25);

        verticalLayout_5->addWidget(progressBar_3);

        label_12 = new QLabel(verticalLayoutWidget_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_5->addWidget(label_12, 0, Qt::AlignHCenter);

        progressBar_4 = new QProgressBar(verticalLayoutWidget_5);
        progressBar_4->setObjectName(QString::fromUtf8("progressBar_4"));
        progressBar_4->setValue(24);

        verticalLayout_5->addWidget(progressBar_4);

        label_13 = new QLabel(verticalLayoutWidget_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_5->addWidget(label_13, 0, Qt::AlignHCenter);

        progressBar_5 = new QProgressBar(verticalLayoutWidget_5);
        progressBar_5->setObjectName(QString::fromUtf8("progressBar_5"));
        progressBar_5->setValue(24);

        verticalLayout_5->addWidget(progressBar_5);

        label_14 = new QLabel(verticalLayoutWidget_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_5->addWidget(label_14, 0, Qt::AlignHCenter);

        progressBar_6 = new QProgressBar(verticalLayoutWidget_5);
        progressBar_6->setObjectName(QString::fromUtf8("progressBar_6"));
        progressBar_6->setValue(24);

        verticalLayout_5->addWidget(progressBar_6);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(419, 364, 181, 61));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        SignalFail = new QPushButton(verticalLayoutWidget_3);
        SignalFail->setObjectName(QString::fromUtf8("SignalFail"));

        verticalLayout_3->addWidget(SignalFail);

        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3, 0, Qt::AlignHCenter);

        Temp_Change = new QSlider(centralwidget);
        Temp_Change->setObjectName(QString::fromUtf8("Temp_Change"));
        Temp_Change->setGeometry(QRect(420, 310, 160, 22));
        Temp_Change->setMinimum(60);
        Temp_Change->setMaximum(80);
        Temp_Change->setOrientation(Qt::Horizontal);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(220, 0, 371, 71));
        QFont font2;
        font2.setPointSize(36);
        font2.setBold(true);
        font2.setWeight(75);
        textBrowser->setFont(font2);
        textBrowser->setLayoutDirection(Qt::LeftToRight);
        textBrowser->setAutoFillBackground(true);
        trainUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(trainUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        trainUI->setMenuBar(menubar);
        statusbar = new QStatusBar(trainUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        trainUI->setStatusBar(statusbar);

        retranslateUi(trainUI);

        QMetaObject::connectSlotsByName(trainUI);
    } // setupUi

    void retranslateUi(QMainWindow *trainUI)
    {
        trainUI->setWindowTitle(QCoreApplication::translate("trainUI", "trainUI", nullptr));
        label_16->setText(QString());
        BrakeFail->setText(QCoreApplication::translate("trainUI", "Brake Fail", nullptr));
        label_2->setText(QCoreApplication::translate("trainUI", "No Failures", nullptr));
        pushButton->setText(QCoreApplication::translate("trainUI", "EMERGENCY BRAKE", nullptr));
        label_17->setText(QCoreApplication::translate("trainUI", "Power(W)", nullptr));
        label_15->setText(QCoreApplication::translate("trainUI", "Temperature(\302\260F)", nullptr));
        EngineFail->setText(QCoreApplication::translate("trainUI", "Engine Fail", nullptr));
        label->setText(QCoreApplication::translate("trainUI", "No Failures", nullptr));
        label_4->setText(QCoreApplication::translate("trainUI", "Speed(mph)", nullptr));
        label_5->setText(QCoreApplication::translate("trainUI", "Acceleration(mph^2)", nullptr));
        label_6->setText(QCoreApplication::translate("trainUI", "Authority(m)", nullptr));
        label_7->setText(QCoreApplication::translate("trainUI", "Number of Passengers", nullptr));
        label_8->setText(QCoreApplication::translate("trainUI", "Crew Size", nullptr));
        label_9->setText(QCoreApplication::translate("trainUI", "Off          Brakes           On", nullptr));
        label_10->setText(QCoreApplication::translate("trainUI", "Emergency Brakes", nullptr));
        label_11->setText(QCoreApplication::translate("trainUI", "Closed   Left Doors   Open", nullptr));
        label_12->setText(QCoreApplication::translate("trainUI", "Right Doors", nullptr));
        label_13->setText(QCoreApplication::translate("trainUI", "Off     Interior Lights    On", nullptr));
        label_14->setText(QCoreApplication::translate("trainUI", "Exterior Lights", nullptr));
        SignalFail->setText(QCoreApplication::translate("trainUI", "Signal Fail", nullptr));
        label_3->setText(QCoreApplication::translate("trainUI", "No Failures", nullptr));
    } // retranslateUi

};

namespace Ui {
    class trainUI: public Ui_trainUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINUI_H
