TEMPLATE = app
CONFIG -= qt
CONFIG += console

GOOGLETESTROOT = C:\Users\jonthom\Documents\Work\googletest

INCLUDEPATH += $${GOOGLETESTROOT}/googletest/include
INCLUDEPATH += $${GOOGLETESTROOT}/googlemock/include
INCLUDEPATH += $${GOOGLETESTROOT}/googletest
INCLUDEPATH += $${GOOGLETESTROOT}/googlemock

INCLUDEPATH += mock
INCLUDEPATH += ../logic/include
INCLUDEPATH += ../logic/interface

LIBS += -L../logic/debug -llogic

SOURCES += \
    ../../googletest/googlemock/src/gmock-all.cc \
    ../../googletest/googletest/src/gtest-all.cc \
    cmdparsetest.cpp \
    datatest.cpp \
    enginetest.cpp \
    main.cpp \
    publishcmdhandletest.cpp \
    substest.cpp \
    timelinecmdhandletest.cpp

HEADERS += \
    mock/mockcmdhandle.h \
    mock/mockcmdparse.h \
    mock/mockdata.h

