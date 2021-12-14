QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_hwtraincontroller_testing.cpp \
    hwtraincontrollermoc.cpp \
    trainmodelmoc.cpp

HEADERS += \
    hwtraincontrollermoc.h \
    trainmodelmoc.h
