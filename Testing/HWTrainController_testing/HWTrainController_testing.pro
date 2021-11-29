QT += testlib
QT += gui serialport
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_hwtraincontroller_testing.cpp \
    hwtraincontrollermoc.cpp \
    serialportmoc.cpp \
    trainmodelmoc.cpp

HEADERS += \
    hwtraincontrollermoc.h \
    serialportmoc.h \
    trainmodelmoc.h
