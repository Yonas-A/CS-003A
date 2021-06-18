
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
        ../../!includes/Graph/animate.cpp \
        ../../!includes/Graph/plot.cpp \
        ../../!includes/Graph/sidebar.cpp \
        ../../!includes/Graph/system.cpp \
        ../../!includes/RPN/rpn.cpp \
        ../../!includes/Random/random.cpp \
        ../../!includes/Shunting_Yard/shunting_yard.cpp \
        ../../!includes/Token/function.cpp \
        ../../!includes/Token/left_paren.cpp \
        ../../!includes/Token/number.cpp \
        ../../!includes/Token/operator.cpp \
        ../../!includes/Token/right_paren.cpp \
        ../../!includes/Token/token.cpp \
        ../../!includes/Token/variable.cpp \
        ../../!includes/Tokenize_String/tokenize.cpp \
        main.cpp

HEADERS += \
    ../../!includes/Graph/animate.h \
    ../../!includes/Graph/constants.h \
    ../../!includes/Graph/graph_info.h \
    ../../!includes/Graph/plot.h \
    ../../!includes/Graph/sidebar.h \
    ../../!includes/Graph/system.h \
    ../../!includes/Queue/queue.h \
    ../../!includes/RPN/rpn.h \
    ../../!includes/Random/random.h \
    ../../!includes/Shunting_Yard/shunting_yard.h \
    ../../!includes/Stack/stack.h \
    ../../!includes/Token/function.h \
    ../../!includes/Token/left_paren.h \
    ../../!includes/Token/number.h \
    ../../!includes/Token/operator.h \
    ../../!includes/Token/right_paren.h \
    ../../!includes/Token/token.h \
    ../../!includes/Token/variable.h \
    ../../!includes/Tokenize_String/constants.h \
    ../../!includes/Tokenize_String/tokenize.h
