#-------------------------------------------------
#
# Project created by QtCreator 2017-10-26T20:36:35
#
#-------------------------------------------------


QT       += core gui sql serialbus serialport xml network
include(../commonconfig.pri)
include(../log4qt/log4qt.pri)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#QT_LOGGING_TO_CONSOLE = 1
DEFINES -= UNICODE
DEFINES += _REENTRANT

win32:
{
VERSION = 0.0.0.1
QMAKE_TARGET_COMPANY = Bogazici University
QMAKE_TARGET_PRODUCT = iBEX
QMAKE_TARGET_DESCRIPTION = "Software platform for medical x-ray equipments"
QMAKE_TARGET_COPYRIGHT = LGPL
}


TARGET = iBEX
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

#message( "Test if log4qt exists...." )
#exists($$DESTDIR/plugins/log4qt.lib){
#message( "Integrating Log4qt ..." )
#LIBS += ./plugins/log4qt.lib
#}

LIBS += $$PWD/../3rd-Party/ctk/lib/ctk-0.1/CTKCore.lib \
        $$PWD/../3rd-Party/ctk/lib/ctk-0.1/CTKDICOMCore.lib \
        $$PWD/../3rd-Party/ctk/lib/ctk-0.1/CTKDICOMWidgets.lib \
        $$PWD/../3rd-Party/ctk/lib/ctk-0.1/CTKVisualizationVTKCore.lib \
        $$PWD/../3rd-Party/ctk/lib/ctk-0.1/CTKVisualizationVTKWidgets.lib \
        $$PWD/../3rd-Party/ctk/lib/ctk-0.1/CTKVisualizationVTKWidgetsPlugins.lib \
        $$PWD/../3rd-Party/ctk/lib/ctk-0.1/CTKWidgets.lib \
        $$PWD/../3rd-Party/ctk/lib/ctk-0.1/CTKWidgetsPlugins.lib\
        $$PWD/../3rd-Party/ctk/lib/ctk-0.1/dcmtls.lib\
        $$PWD/../3rd-Party/ctk/lib/ctk-0.1/dcmnet.lib\
        $$PWD/../3rd-Party/ctk/lib/ctk-0.1/dcmdata.lib \
        $$PWD/../3rd-Party/ctk/lib/ctk-0.1/oflog.lib \
        $$PWD/../3rd-Party/ctk/lib/ctk-0.1/ofstd.lib \

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

win32{

LIBS+= WS2_32.Lib \
       netapi32.lib \
       wsock32.lib \
       kernel32.lib \
       user32.lib \
       gdi32.lib \
       winspool.lib \
       shell32.lib \
       ole32.lib \
       oleaut32.lib \
       uuid.lib \
       comdlg32.lib \
       advapi32.lib
}

INCLUDEPATH += ../3rd-Party/ctk/include/ctk-0.1 \
               ../3rd-Party/ctk/include \
               ../common/include \
               $$(VTK_DIR)/include/vtk-9.0



SOURCES += \
        main.cpp \
        Utils/logmgr.cpp \
        Utils/databasemgr.cpp \
        Utils/settingsprovider.cpp \
        Utils/dicomtools.cpp \
#        View/newpatientdialog.cpp \
#        View/bodypartselectionsquare.cpp \
#        Model/patientdata.cpp \
#        Model/anatomicregionelement.cpp\
        View/mainwindow.cpp \
    coreapplication.cpp

#        View/exposuredialog.cpp \
#        View/imageviewer.cpp \
#        View/pacsnodesettingsdialog.cpp \
#        View/loadstudydialog.cpp \
#        View/rs232connector.cpp \
#        View/modbusconnector.cpp \
#        View/worklistserversettingsdialog.cpp \
#        View/worklistdialog.cpp \
#        View/worklistmodel.cpp \
#        View/logindialog.cpp \
#         Utils/dicomwriter.cpp \
#        Model/databaseservice.cpp \
#        Controller/devicemgr.cpp \
#        Controller/loginmgr.cpp


HEADERS += \
        Utils/call_once.h \
        Utils/singleton.h \
        Utils/logmgr.h    \
        Utils/databasemgr.h \
        Utils/dicomtools.h \
        Utils/settingsprovider.h \
        View/mainwindow.h \
    coreapplication.h
#        View/newpatientdialog.h\
#        View/bodypartselectionsquare.h
#        Model/DICOM_ENUMS.h \
#        Model/patientdata.h \
#        Model/anatomicregionelement.h
#        View/exposuredialog.h \
#        View/imageviewer.h \
#        View/pacsnodesettingsdialog.h \
#        loadstudydialog.h\
#        ../common/include/idevice.h\
#        ../common/include/isettingsparser.h \
#        ../common/include/iconnector.h \
#        View/rs232connector.h \
#        View/modbusconnector.h \
#        View/worklistserversettingsdialog.h \
#        View/worklistdialog.h \
#        View/dicomtaglist.h \
#        View/worklistmodel.h \
#        View/logindialog.h \
#        Utils/dicomwriter.h \
#        Model/databaseservice.h \
#        Controller/devicemgr.h \
#        Controller/loginmgr.h


FORMS += \
         View/mainwindow.ui \
#         View/newpatientdialog.ui
#        View/exposuredialog.ui \
#        View/imageviewer.ui \
#        View/pacsnodesettingsdialog.ui \
#        View/loadstudydialog.ui \
#        View/worklistserversettingsdialog.ui \
#        View/worklistdialog.ui \
#        View/logindialog.ui


RESOURCES += \
    resources.qrc

DISTFILES += \
    notes

win32{
QMAKE_POST_LINK += $(COPY_DIR) $$system_path($$_PRO_FILE_PWD_/configs) $$system_path($$DESTDIR/configs)
QMAKE_PRE_LINK += $(COPY_DIR) $$system_path($$_PRO_FILE_PWD_/database) $$system_path($$DESTDIR/database)
}






