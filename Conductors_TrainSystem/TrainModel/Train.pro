QT       += core gui serialport

QT    += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../HWTrainController/hw_TrainController/hwtrainui.cpp \
    ../HWTrainController/hw_TrainController/serialport.cpp \
    ../HWTrainController/hw_TrainController/traincontroller.cpp \
    ../TrainControlSW/SWTrainController.cpp \
    ../TrainControlSW/uiswtraincontroller.cpp \
    main.cpp \
    trainmaker.cpp \
    trainmodel.cpp \
    trainui.cpp

HEADERS += \
    ../HWTrainController/hw_TrainController/hwtrainui.h \
    ../HWTrainController/hw_TrainController/serialport.h \
    ../HWTrainController/hw_TrainController/traincontroller.h \
    ../TrainControlSW/SWTrainController.h \
    ../TrainControlSW/uiswtraincontroller.h \
    trainmaker.h \
    trainmodel.h \
    trainui.h

FORMS += \
    ../HWTrainController/hw_TrainController/hwtrainui.ui \
    ../TrainControlSW/uiswtraincontroller.ui \
    trainui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
