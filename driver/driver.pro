TEMPLATE = app
CONFIG -= qt
CONFIG += console

INCLUDEPATH += ../logic/include

LIBS += -L../logic/debug -llogic

SOURCES += \
    main.cpp
