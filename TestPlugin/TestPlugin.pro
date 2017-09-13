TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
TARGET          = testPlugin
DESTDIR         = ../plugins

INCLUDEPATH += ../common/src
HEADERS += \
    demoplugin.h

SOURCES += \
    demoplugin.cpp
