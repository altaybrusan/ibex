#-------------------------------------------------
#
# Project created by QtCreator 2018-02-07T16:00:58
#
#-------------------------------------------------

include(../../common/build/build.pri)
include(../../common/build/g++.pri)
include(../../commonconfig.pri)
include(../pluginconfiguration.pri)


TEMPLATE = lib
CONFIG  += plugin
QT      += widgets

TARGET = DeltaB2MotorDriver
DEFINES += DELTAB2MOTORDRIVER_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH +=  ../../common/include \
                ../../3rd-Party/ctk/include/ctk-0.1

SOURCES += \
        deltab2motordriver.cpp \
    speedcontrolwidget.cpp \
    speedcontrolwidget.cpp

HEADERS += \
        deltab2motordriver.h \
        deltab2motordriver_global.h \ 
    speedcontrolwidget.h \
    speedcontrolwidget.h

LIBS += ../../3rd-Party/ctk/lib/ctk-0.1/CTKCore.lib \
        ../../3rd-Party/ctk/lib/ctk-0.1/CTKDICOMCore.lib \
        ../../3rd-Party/ctk/lib/ctk-0.1/CTKDICOMWidgets.lib \
        ../../3rd-Party/ctk/lib/ctk-0.1/CTKVisualizationVTKCore.lib \
        ../../3rd-Party/ctk/lib/ctk-0.1/CTKVisualizationVTKWidgets.lib \
        ../../3rd-Party/ctk/lib/ctk-0.1/CTKVisualizationVTKWidgetsPlugins.lib \
        ../../3rd-Party/ctk/lib/ctk-0.1/CTKWidgets.lib \
        ../../3rd-Party/ctk/lib/ctk-0.1/CTKWidgetsPlugins.lib\

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    speedcontrolwidget.ui



