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

TARGET = ButterworthLowPassFilter

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += BUTTERWORTHLOWPASSFILTER_LIBRARY
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ../../3rd-Party/ctk/include/ctk-0.1 \
               ../../3rd-Party/ctk/include \
               ../../common/include \
               $$(VTK_DIR)/include/vtk-9.0

LIBS += $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/CTKCore.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/CTKDICOMCore.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/CTKDICOMWidgets.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/CTKVisualizationVTKCore.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/CTKVisualizationVTKWidgets.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/CTKVisualizationVTKWidgetsPlugins.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/CTKWidgets.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/CTKWidgetsPlugins.lib\
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/dcmtls.lib\
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/dcmnet.lib\
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/dcmdata.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/oflog.lib \
        $$PWD/../../3rd-Party/ctk/lib/ctk-0.1/ofstd.lib \

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
        $$(VTK_DIR)/lib/vtkImagingCore-9.0.lib\
        $$(VTK_DIR)/lib/vtkImagingGeneral-9.0.lib\
        $$(VTK_DIR)/lib/vtkImagingMath-9.0.lib\
        $$(VTK_DIR)/lib/vtkImagingColor-9.0.lib\
        $$(VTK_DIR)/lib/vtkImagingSources-9.0.lib\
        $$(VTK_DIR)/lib/vtkImagingFourier-9.0.lib

SOURCES += \
    butterworthlowpassfilterwidget.cpp \
    logfilter.cpp

HEADERS += \
    butterworthlowpassfilterwidget.h \
    butterworthlowpassfilter_global.h \
    ../../common/include/ialgorithm.h \
    butterworthlowpassfilter.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    logfilterwidget.ui
