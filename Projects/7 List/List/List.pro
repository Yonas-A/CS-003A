TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


SOURCES += \
        main.cpp

HEADERS += \
    ../../!includes/Linked_List/linked_list.h \
    ../../!includes/List/list.h \
    ../../!includes/List/list_test.h \
    interface/list_interface.h
