TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../!includes/RPN/rpn.cpp \
        ../../!includes/Token/function.cpp \
        ../../!includes/Token/left_paren.cpp \
        ../../!includes/Token/number.cpp \
        ../../!includes/Token/operator.cpp \
        ../../!includes/Token/right_paren.cpp \
        ../../!includes/Token/token.cpp \
        ../../!includes/Token/variable.cpp \
        main.cpp

HEADERS += \
    ../../!includes/RPN/rpn_test.h \
    ../../!includes/RPN_/rpn.h \
    ../../!includes/Token/function.h \
    ../../!includes/Token/left_paren.h \
    ../../!includes/Token/number.h \
    ../../!includes/Token/operator.h \
    ../../!includes/Token/right_paren.h \
    ../../!includes/Token/token.h \
    ../../!includes/Token/variable.h
