TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        includes/lab.cpp \
        includes/plane.cpp \
        main.cpp

HEADERS += \
    ../../!includes/Dynamic_Allocation/one_dimension.h \
    ../../!includes/Dynamic_Allocation/two_dimension.h \
    includes/lab.h \
    includes/plane.h
