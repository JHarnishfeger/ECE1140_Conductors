QT -= gui
QT += widgets serialport

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Block.cpp \
        CTC.cpp \
        ConductorsMain.cpp \
        HWTrackController.cpp \
        HWTrainController/hw_TrainController/hwtrainui.cpp \
        HWTrainController/hw_TrainController/hwtrainui.cpp \
        HWTrainController/hw_TrainController/main.cpp \
        HWTrainController/hw_TrainController/serialport.cpp \
        HWTrainController/hw_TrainController/serialport.cpp \
        HWTrainController/hw_TrainController/traincontroller.cpp \
        HWTrainController/hw_TrainController/traincontroller.cpp \
        HWTrainController/hw_TrainController/traincontrollermainwindow.cpp \
        HWTrainController/hw_TrainController/traincontrollermainwindow.cpp \
        MBO/SMBA.cpp \
        MBO/TrackLayout.cpp \
        MBO/drivers.cpp \
        MBO/main.cpp \
        MBO/mbo.cpp \
        PLCController.cpp \
        SWTrackController.cpp \
        ScheduleManager.cpp \
        SerialPort.cpp \
        SerialPortTrack.cpp \
        Track.cpp \
        TrackMap.cpp \
        TrackNodes.cpp \
        TrainControlSW/SWTrainController.cpp \
        TrainControlSW/TrainControllerSignalHandler.cpp \
        TrainControlSW/UITrainController/SWTrainController.cpp \
        TrainControlSW/UITrainController/TrainControllerSignalHandler.cpp \
        TrainControlSW/UITrainController/main.cpp \
        TrainControlSW/UITrainController/uiswtraincontroller.cpp \
        TrainControlSW/build-UITrainController-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/debug/moc_uiswtraincontroller.cpp \
        TrainControlSW/build-UITrainController-Desktop_Qt_6_1_3_MinGW_64_bit-Debug/debug/moc_uiswtraincontroller.cpp \
        TrainControlSW/main.cpp \
        TrainControlSW/uiswtraincontroller.cpp \
        TrainControlSW/universaltimer.cpp \
        TrainModel/main.cpp \
        TrainModel/trainmaker.cpp \
        TrainModel/trainmodel.cpp \
        TrainModel/trainui.cpp \
        TrainTracker.cpp \
        Wayside.cpp \
        WaysideManager.cpp \
        Wayside_HW.cpp \
        ctcwindow.cpp \
        hwtcinterface.cpp \
        string_utils.cpp \
        swtcinterface.cpp \
        trackmodel.cpp \
        waysidewin.cpp \
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    HWTrainController/hw_TrainController/hwtrainui.ui \
    HWTrainController/hw_TrainController/hwtrainui.ui \
    HWTrainController/hw_TrainController/traincontrollermainwindow.ui \
    HWTrainController/hw_TrainController/traincontrollermainwindow.ui \
    MBO/mbo.ui \
    TrainControlSW/UITrainController/uiswtraincontroller.ui \
    TrainControlSW/uiswtraincontroller.ui \
    TrainModel/trainui.ui \
    ctcwindow.ui \
    hwtcinterface.ui \
    swtcinterface.ui \
    trackmodel.ui \
    waysidewin.ui

DISTFILES += \
    CTCPLC.txt.txt \
    HWTrainController/HWTrainControllerMain_Arduino/Conversion2Float.ino \
    HWTrainController/HWTrainControllerMain_Arduino/Joystick.ino \
    HWTrainController/HWTrainControllerMain_Arduino/Power.ino \
    HWTrainController/HWTrainControllerMain_Arduino/Receiver.ino \
    HWTrainController/HWTrainControllerMain_Arduino/Transmitter.ino \
    MBO/GPS_mapping.txt \
    MBO/greenline_v2.csv \
    MBO/redline_v2.csv \
    MBO/sample.txt \
    MBO/schedule.csv \
    TrainControlSW/build-UITrainController-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/.qmake.stash \
    TrainControlSW/build-UITrainController-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/debug/UITrainController.exe \
    TrainControlSW/build-UITrainController-Desktop_Qt_6_1_3_MinGW_64_bit-Debug/debug/UITrainController.exe \
    greenLine.txt \
    redLine.txt \
    testschedule.csv \
    track.png

HEADERS += \
    Authority.h \
    Block.h \
    Branch.h \
    CTC.hpp \
    Clock.h \
    HWTrackController.h \
    HWTrainController/HWTrainControllerMain_Arduino/HWTrainControllerMain_Arduino.ino \
    HWTrainController/hw_TrainController/hwtrainui.h \
    HWTrainController/hw_TrainController/hwtrainui.h \
    HWTrainController/hw_TrainController/serialport.h \
    HWTrainController/hw_TrainController/serialport.h \
    HWTrainController/hw_TrainController/traincontroller.h \
    HWTrainController/hw_TrainController/traincontroller.h \
    HWTrainController/hw_TrainController/traincontrollermainwindow.h \
    HWTrainController/hw_TrainController/traincontrollermainwindow.h \
    MBO/SMBA.h \
    MBO/TrackLayout.h \
    MBO/drivers.h \
    MBO/mbo.h \
    Node.hpp \
    PLCController.h \
    SWTrackController.h \
    ScheduleManager.h \
    SerialPort.h \
    SerialPortTrack.h \
    Track.h \
    TrackMap.hpp \
    TrackNodes.h \
    TrainControlSW/SWTrainController.h \
    TrainControlSW/TrainControllerSignalHandler.h \
    TrainControlSW/UITrainController/SWTrainController.h \
    TrainControlSW/UITrainController/TrainControllerSignalHandler.h \
    TrainControlSW/UITrainController/uiswtraincontroller.h \
    TrainControlSW/build-UITrainController-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/debug/moc_predefs.h \
    TrainControlSW/build-UITrainController-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/ui_uiswtraincontroller.h \
    TrainControlSW/build-UITrainController-Desktop_Qt_6_1_3_MinGW_64_bit-Debug/debug/moc_predefs.h \
    TrainControlSW/build-UITrainController-Desktop_Qt_6_1_3_MinGW_64_bit-Debug/ui_engineer.h \
    TrainControlSW/build-UITrainController-Desktop_Qt_6_1_3_MinGW_64_bit-Debug/ui_trainInformation.h \
    TrainControlSW/build-UITrainController-Desktop_Qt_6_1_3_MinGW_64_bit-Debug/ui_transitData.h \
    TrainControlSW/build-UITrainController-Desktop_Qt_6_1_3_MinGW_64_bit-Debug/ui_uiswtraincontroller.h \
    TrainControlSW/build-UITrainController-Desktop_Qt_6_1_3_MinGW_64_bit-Debug/ui_utilities.h \
    TrainControlSW/uiswtraincontroller.h \
    TrainControlSW/universaltimer.h \
    TrainModel/trainmaker.h \
    TrainModel/trainmodel.h \
    TrainModel/trainui.h \
    TrainTracker.h \
    WayStruct.h \
    Wayside.h \
    WaysideManager.h \
    Wayside_HW.h \
    ctcwindow.h \
    hwtcinterface.h \
    string_utils.hpp \
    swtcinterface.h \
    trackmodel.h \
    waysidewin.h
SUBDIRS += \
    HWTrainController/hw_TrainController/hw_TrainController.pro \
    MBO/MBO.pro \
    TrainControlSW/UITrainController.pro \
    TrainControlSW/UITrainController/UITrainController.pro \
    TrainModel/Train.pro
