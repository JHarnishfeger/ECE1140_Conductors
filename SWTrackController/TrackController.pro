QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Block.cpp \
    CTC/CTC.cpp \
    CTC/ScheduleManager.cpp \
    CTC/TrackMap.cpp \
    CTC/TrackNodes.cpp \
    CTC/WaysideManager.cpp \
    CTC/ctcwindow.cpp \
    CTC/string_utils.cpp \
    PLCController.cpp \
    SWTrackController.cpp \
    Wayside.cpp \
    main.cpp \
    swtcinterface.cpp \
    waysidewin.cpp

HEADERS += \
    Authority.h \
    Block.h \
    CTC/Branch.h \
    CTC/CTC.hpp \
    CTC/Node.hpp \
    CTC/ScheduleManager.h \
    CTC/TrackMap.hpp \
    CTC/TrackNodes.h \
    CTC/WaysideManager.h \
    CTC/ctcwindow.h \
    CTC/string_utils.hpp \
    PLCController.h \
    SWTrackController.h \
    WayStruct.h \
    Wayside.h \
    swtcinterface.h \
    waysidewin.h

FORMS += \
    CTC/ctcwindow.ui \
    swtcinterface.ui \
    waysidewin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
