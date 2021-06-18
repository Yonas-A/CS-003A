TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        includes/poly.cpp \
        includes/term.cpp \
        main.cpp

HEADERS += \
    includes/poly.h \
    Poly_output.h \
    includes/term.h \
    includes/polynomial_test.h
