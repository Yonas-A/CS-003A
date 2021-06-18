TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    ../../!includes/List/iterated_list.h \
    ../../!includes/Linked_List/linked_list.h \
    interface/user_interface.h
