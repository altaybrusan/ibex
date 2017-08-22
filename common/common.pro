include(../utilities/log4qt/log4qt.pri)
TEMPLATE = app
#CONFIG+= staticlib
CONFIG += c++14
INCLUDEPATH += ../utilities/log4qt \
               ../utilities/log4qt/helpers \
               ../utilities/log4qt/spi \
               ../utilities/log4qt/varia

HEADERS += \
    platform.h \
    call_once.h \
    singleton.h \
    logmanager.h

SOURCES += \
    platform.cpp \
    main.cpp \
    logmanager.cpp

#LIBS += ../utilities/log4qt/log4qt.lib


