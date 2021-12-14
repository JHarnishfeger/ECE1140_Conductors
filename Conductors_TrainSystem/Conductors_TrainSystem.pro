QT -= gui
QT += widgets

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
        PLCController.cpp \
        SWTrackController.cpp \
        ScheduleManager.cpp \
        SerialPort.cpp \
        Track.cpp \
        TrackMap.cpp \
        TrackNodes.cpp \
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
    HWTrackController.h \
    Node.hpp \
    PLCController.h \
    SWTrackController.h \
    ScheduleManager.h \
    SerialPort.h \
    Track.h \
    TrackMap.hpp \
    TrackNodes.h \
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
