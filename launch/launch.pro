#-------------------------------------------------
#
# Project created by QtCreator 2017-10-26T20:36:35
#
#-------------------------------------------------


QT       += core gui
include(../commonconfig.pri)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = laucnh
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
TEST_IMAGE_REPO = $$PWD/test_images/

DEFINES += TEST_IMAGES_DIR=\\\"$$TEST_IMAGE_REPO\\\"

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += ../3rd-Party/ctk/lib/ctk-0.1/CTKCore.lib \
        ../3rd-Party/ctk/lib/ctk-0.1/CTKDICOMCore.lib \
        ../3rd-Party/ctk/lib/ctk-0.1/CTKDICOMWidgets.lib \
        ../3rd-Party/ctk/lib/ctk-0.1/CTKVisualizationVTKCore.lib \
        ../3rd-Party/ctk/lib/ctk-0.1/CTKVisualizationVTKWidgets.lib \
        ../3rd-Party/ctk/lib/ctk-0.1/CTKVisualizationVTKWidgetsPlugins.lib \
        ../3rd-Party/ctk/lib/ctk-0.1/CTKWidgets.lib \
        ../3rd-Party/ctk/lib/ctk-0.1/CTKWidgetsPlugins.lib\



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


INCLUDEPATH += ../3rd-Party/ctk/include/ctk-0.1 \
               $$(VTK_DIR)/include/vtk-9.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    newpatientdialog.cpp \
    bodypartselectionsquare.cpp \
    exposuredialog.cpp \
    imageviewer.cpp

HEADERS += \
        mainwindow.h \
    newpatientdialog.h \
    bodypart.h \
    bodypartselectionsquare.h \
    exposuredialog.h \
    imageviewer.h

FORMS += \
        mainwindow.ui \
    newpatientdialog.ui \
    exposuredialog.ui \
    imageviewer.ui

RESOURCES += \
    resources.qrc
