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
        HWTrainController/hw_TrainController/serialport.cpp \
        HWTrainController/hw_TrainController/traincontroller.cpp \
        MBO/SMBA.cpp \
        MBO/TrackLayout.cpp \
        MBO/drivers.cpp \
        MBO/mbo.cpp \
        PLCController.cpp \
        SWTrackController.cpp \
        ScheduleManager.cpp \
        SerialPortTrack.cpp \
        Track.cpp \
        TrackMap.cpp \
        TrackNodes.cpp \
        TrainControlSW/SWTrainController.cpp \
        TrainControlSW/uiswtraincontroller.cpp \
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
        waysidewin.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    HWTrainController/hw_TrainController/hwtrainui.ui \
    MBO/mbo.ui \
    TrainControlSW/uiswtraincontroller.ui \
    TrainModel/trainui.ui \
    ctcwindow.ui \
    hwtcinterface.ui \
    swtcinterface.ui \
    trackmodel.ui \
    waysidewin.ui

DISTFILES += \
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
    HWTrainController/hw_TrainController/hwtrainui.h \
    HWTrainController/hw_TrainController/serialport.h \
    HWTrainController/hw_TrainController/traincontroller.h \
    MBO/SMBA.h \
    MBO/TrackLayout.h \
    MBO/drivers.h \
    MBO/mbo.h \
    Node.hpp \
    PLCController.h \
    SWTrackController.h \
    ScheduleManager.h \
    SerialPortTrack.h \
    Track.h \
    TrackMap.hpp \
    TrackNodes.h \
    TrainControlSW/SWTrainController.h \
    TrainControlSW/uiswtraincontroller.h \
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
