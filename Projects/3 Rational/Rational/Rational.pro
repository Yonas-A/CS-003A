TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        includes/rational.cpp \
        main.cpp

HEADERS += \
    includes/rational.h \
    includes/rational_test.h \
    output.h \
    work_report.h
