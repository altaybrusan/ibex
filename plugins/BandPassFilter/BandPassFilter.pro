#-------------------------------------------------
#
# Project created by QtCreator 2018-10-16T12:53:33
#
#-------------------------------------------------

include(../../common/build/build.pri)
include(../../common/build/g++.pri)
include(../../commonconfig.pri)
include(../pluginconfiguration.pri)


TEMPLATE = lib
CONFIG  += plugin
QT      += widgets

TARGET = BandPassFilter

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += BANDPASSFILTER_LIBRARY
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH +=  ../../common/include \
                 $$(VTK_DIR)/include/vtk-9.0
LIBS += $$(VTK_DIR)/lib/QVTKWidgetPlugin.lib \
        $$(VTK_DIR)/lib/vtkInteractionStyle-9.0.lib\
        $$(VTK_DIR)/lib/vtkCommonCore-9.0.lib \
        $$(VTK_DIR)/lib/vtkRenderingOpenGL2-9.0.lib \
        $$(VTK_DIR)/lib/vtkViewsCore-9.0.lib \
        $$(VTK_DIR)/lib/vtkGUISupportQt-9.0.lib \
        $$(VTK_DIR)/lib/vtkRenderingCore-9.0.lib \
        $$(VTK_DIR)/lib/vtkInteractionImage-9.0.lib \
        $$(VTK_DIR)/lib/vtkRenderingImage-9.0.lib \
        $$(VTK_DIR)/lib/vtkIOImage-9.0.lib\
        $$(VTK_DIR)/lib/vtkCommonExecutionModel-9.0.lib\
        $$(VTK_DIR)/lib/vtkInteractionWidgets-9.0.lib\
        $$(VTK_DIR)/lib/vtkRenderingAnnotation-9.0.lib\
        $$(VTK_DIR)/lib/vtkCommonDataModel-9.0.lib\
        $$(VTK_DIR)/lib/vtkImagingCore-9.0.lib

SOURCES += \
        bandpassfilter.cpp

HEADERS += \
        bandpassfilter.h \
    bandpassfilter_global.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
