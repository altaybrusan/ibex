# REM: blank space in path can make trubble for gmake
QT += core network
CONFIG += qt c++14
CONFIG += test
INCLUDEPATH += ../utilities/bin/include \
               ../utilities/bin/include/log4qt

include(../utilities/src/log4qt/build.pri)
include(../utilities/src/log4qt/g++.pri)

DEFINES += QT_DEPRECATED_WARNINGS

msvc {
    QMAKE_CXXFLAGS += -wd4267
}

LIBS += -L../utilities/bin/lib \
        -llog4qt


HEADERS += \
    src/platform.h \
    src/call_once.h \
    src/singleton.h \
    src/basiclogmanager.h \

SOURCES += \
    src/platform.cpp \
    src/main.cpp \
    src/basiclogmanager.cpp \
    test/testbasiclogmanager.cpp


test{
   message(Configuring test build...)




    QT += testlib
    QT -= gui

    TARGET = testbasiclogmanager
    CONFIG   += console
    CONFIG   -= app_bundle

    TEMPLATE = app
    # The following define makes your compiler emit warnings if you use
    # any feature of Qt which as been marked as deprecated (the exact warnings
    # depend on your compiler). Please consult the documentation of the
    # deprecated API in order to know how to port your code away from it.
    DEFINES += QT_DEPRECATED_WARNINGS

    # You can also make your code fail to compile if you use deprecated APIs.
    # In order to do so, uncomment the following line.
    # You can also select to disable deprecated APIs only up to a certain version of Qt.
    #DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

    SOURCES -= src/main.cpp
    SOURCES += \
        test/testbasiclogmanager.cpp

}
else{
    TEMPLATE = app
}

