/********************************************************************************
** Form generated from reading UI file 'hwtcinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HWTCINTERFACE_H
#define UI_HWTCINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HWTCInterface
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QCheckBox *ModeBox;
    QFrame *line_2;
    QFrame *line;
    QLabel *label;
    QLineEdit *PLCtextBox;
    QPushButton *PLCButton;
    QListWidget *blockList;
    QFrame *line_3;
    QCheckBox *TrainPresentBox;
    QCheckBox *CrossingBox;
    QCheckBox *LeftBox;
    QCheckBox *RightBox;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCheckBox *HWConnection;
    QCheckBox *BrokenRailCheckBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HWTCInterface)
    {
        if (HWTCInterface->objectName().isEmpty())
            HWTCInterface->setObjectName(QString::fromUtf8("HWTCInterface"));
        HWTCInterface->resize(683, 520);
        centralwidget = new QWidget(HWTCInterface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(11, 27, 124, 33));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        ModeBox = new QCheckBox(centralwidget);
        ModeBox->setObjectName(QString::fromUtf8("ModeBox"));
        ModeBox->setGeometry(QRect(142, 29, 145, 28));
        ModeBox->setFont(font);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(290, 0, 16, 251));
        line_2->setFont(font);
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(11, 83, 671, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(11, 93, 261, 91));
        QFont font1;
        font1.setPointSize(24);
        label->setFont(font1);
        PLCtextBox = new QLineEdit(centralwidget);
        PLCtextBox->setObjectName(QString::fromUtf8("PLCtextBox"));
        PLCtextBox->setGeometry(QRect(350, 120, 291, 51));
        QFont font2;
        font2.setPointSize(10);
        PLCtextBox->setFont(font2);
        PLCButton = new QPushButton(centralwidget);
        PLCButton->setObjectName(QString::fromUtf8("PLCButton"));
        PLCButton->setGeometry(QRect(370, 180, 251, 51));
        PLCButton->setFont(font);
        blockList = new QListWidget(centralwidget);
        blockList->setObjectName(QString::fromUtf8("blockList"));
        blockList->setGeometry(QRect(11, 185, 251, 281));
        QFont font3;
        font3.setPointSize(11);
        blockList->setFont(font3);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(290, 240, 391, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        TrainPresentBox = new QCheckBox(centralwidget);
        TrainPresentBox->setObjectName(QString::fromUtf8("TrainPresentBox"));
        TrainPresentBox->setGeometry(QRect(297, 250, 146, 28));
        TrainPresentBox->setFont(font);
        CrossingBox = new QCheckBox(centralwidget);
        CrossingBox->setObjectName(QString::fromUtf8("CrossingBox"));
        CrossingBox->setGeometry(QRect(297, 285, 266, 28));
        CrossingBox->setFont(font);
        LeftBox = new QCheckBox(centralwidget);
        LeftBox->setObjectName(QString::fromUtf8("LeftBox"));
        LeftBox->setGeometry(QRect(297, 320, 125, 28));
        LeftBox->setFont(font);
        RightBox = new QCheckBox(centralwidget);
        RightBox->setObjectName(QString::fromUtf8("RightBox"));
        RightBox->setGeometry(QRect(450, 320, 137, 28));
        RightBox->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(270, 358, 402, 24));
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAutoFillBackground(false);
        label_2->setLineWidth(1);
        label_2->setMidLineWidth(0);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 390, 321, 71));
        pushButton_2->setFont(font1);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(370, 10, 217, 65));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        HWConnection = new QCheckBox(widget);
        HWConnection->setObjectName(QString::fromUtf8("HWConnection"));
        HWConnection->setFont(font);
        HWConnection->setMouseTracking(true);
        HWConnection->setCheckable(true);

        verticalLayout->addWidget(HWConnection);

        BrokenRailCheckBox = new QCheckBox(widget);
        BrokenRailCheckBox->setObjectName(QString::fromUtf8("BrokenRailCheckBox"));
        BrokenRailCheckBox->setFont(font);

        verticalLayout->addWidget(BrokenRailCheckBox);

        HWTCInterface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HWTCInterface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 683, 26));
        HWTCInterface->setMenuBar(menubar);
        statusbar = new QStatusBar(HWTCInterface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HWTCInterface->setStatusBar(statusbar);

        retranslateUi(HWTCInterface);

        QMetaObject::connectSlotsByName(HWTCInterface);
    } // setupUi

    void retranslateUi(QMainWindow *HWTCInterface)
    {
        HWTCInterface->setWindowTitle(QCoreApplication::translate("HWTCInterface", "HWTCInterface", nullptr));
        pushButton->setText(QCoreApplication::translate("HWTCInterface", "Toggle Mode", nullptr));
        ModeBox->setText(QCoreApplication::translate("HWTCInterface", "Manual Mode", nullptr));
        label->setText(QCoreApplication::translate("HWTCInterface", "Select a block:", nullptr));
        PLCtextBox->setText(QString());
        PLCButton->setText(QCoreApplication::translate("HWTCInterface", "Import PLC", nullptr));
        TrainPresentBox->setText(QCoreApplication::translate("HWTCInterface", "Train Present", nullptr));
        CrossingBox->setText(QCoreApplication::translate("HWTCInterface", "Railway Crossing Activated", nullptr));
        LeftBox->setText(QCoreApplication::translate("HWTCInterface", "Switch Left", nullptr));
        RightBox->setText(QCoreApplication::translate("HWTCInterface", "Switch Right", nullptr));
        label_2->setText(QCoreApplication::translate("HWTCInterface", "Click to update Switch and Crossing from HW", nullptr));
        pushButton_2->setText(QCoreApplication::translate("HWTCInterface", "UPDATE", nullptr));
        HWConnection->setText(QCoreApplication::translate("HWTCInterface", "Hardware Connected", nullptr));
        BrokenRailCheckBox->setText(QCoreApplication::translate("HWTCInterface", "Broken Rail Detected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HWTCInterface: public Ui_HWTCInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HWTCINTERFACE_H
