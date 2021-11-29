QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Block.cpp \
    CTC.cpp \
    ScheduleManager.cpp \
    TrackMap.cpp \
    TrackNodes.cpp \
    WaysideManager.cpp \
    main.cpp \
    ctcwindow.cpp \
    string_utils.cpp \
    tests.cpp
    CTC.cpp
    ScheduleManager.cpp
    TrackMap.cpp
    TrackNodes.cpp
    WaysideManager.cpp
    string_utils.cpp
    string_utils.hpp

HEADERS += \
    Authority.h \
    Block.h \
    Branch.h \
    CTC.hpp \
    Node.hpp \
    ScheduleManager.h \
    TrackMap.hpp \
    TrackNodes.h \
    WayStruct.h \
    WaysideManager.h \
    ctcwindow.h \
    string_utils.hpp \
    tests.h
    WaysideManager.h
    Branch.h
    Block.h
    Authority.h
    WayStruct.h
    TrackNodes.h
    TrackMap.hpp
    ScheduleManager.h
    Node.hpp
    CTC.hpp

FORMS += \
    ctcwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
