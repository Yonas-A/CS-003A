TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt


#MAC
LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release):
LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release):
LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window


#MAC
INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"


SOURCES += \
    ../../!includes/Random/random.cpp \
    includes/Prey_Predator_Sfml/animate.cpp \
    includes/creature.cpp \
    includes/grid.cpp \
    includes/predator.cpp \
    includes/prey.cpp \
    includes/wall.cpp \
    main.cpp

#    Pred_Prey_work_report.h \
#    pred_prey_output.h

HEADERS += \
    ../../!includes/Random/random.h \
    includes/Prey_Predator_Sfml/animate.h \
    includes/Prey_Predator_Sfml/constants.h \
    includes/creature.h \
    includes/grid.h \
    includes/predator.h \
    includes/prey.h \
    includes/wall.h
