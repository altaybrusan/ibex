#-------------------------------------------------
#
# Project created by QtCreator 2018-02-19T22:08:54
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_dcmtktesttest
CONFIG   += console
CONFIG   -= app_bundle


TEMPLATE = app
DEFINES -= UNICODE
DEFINES += _REENTRANT

QMAKE_CFLAGS_RELEASE -= -MD
QMAKE_CFLAGS_RELEASE = -MT
QMAKE_CFLAGS_DEBUG -= -MDd
QMAKE_CFLAGS_DEBUG = -MTd
QMAKE_CXXFLAGS_RELEASE -= -MD
QMAKE_CXXFLAGS_RELEASE += -MT
QMAKE_CXXFLAGS_DEBUG -= -MDd
QMAKE_CXXFLAGS_DEBUG += -MTd

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../../3rd-Party/ctk/include

SOURCES += \
    dcmtktesttest.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

LIBS += ../../3rd-Party/ctk/lib/ctk-0.1/dcmfg.lib \
        ../../3rd-Party/ctk/lib/ctk-0.1/dcmnet.lib \
        ../../3rd-Party/ctk/lib/ctk-0.1/dcmimage.lib \
        ../../3rd-Party/ctk/lib/ctk-0.1/dcmiod.lib \
        ../../3rd-Party/ctk/lib/ctk-0.1/ofstd.lib\
        ../../3rd-Party/ctk/lib/ctk-0.1/oflog.lib\
        ../../3rd-Party/ctk/lib/ctk-0.1/dcmdata.lib \

HEADERS += \
    testscu.h
