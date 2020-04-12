TEMPLATE = lib
CONFIG -= qt

INCLUDEPATH += include
INCLUDEPATH += interface

HEADERS += \
    include/cmdnum.h \
    include/cmdparse.h \
    include/command.h \
    include/data.h \
    include/engine.h \
    include/entry.h \
    include/followcmdhandle.h \
    include/logic.h \
    include/publishcmdhandle.h \
    include/subs.h \
    include/timelinecmdhandle.h \
    include/utilfunc.h \
    include/wallcmdhandle.h \
    interface/cmdhandleinterface.h \
    interface/cmdparseinterface.h \
    interface/datainterface.h \
    interface/subsinterface.h

SOURCES += \
    src/cmdparse.cpp \
    src/data.cpp \
    src/engine.cpp \
    src/followcmdhandle.cpp \
    src/logic.cpp \
    src/publishcmdhandle.cpp \
    src/subs.cpp \
    src/timelinecmdhandle.cpp \
    src/utilfunc.cpp \
    src/wallcmdhandle.cpp
