TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    ../../!includes/Sorted_List/sorted.h \
    ../../!includes/Sorted_List/sorted_output.h \
    ../../!includes/Sorted_List/sorted_test.h \
    ../../!includes/Linked_List_Sorted/linked_list_sorted.h \
    ../../!includes/Linked_List_Sorted/linked_list_sorted_test.h
