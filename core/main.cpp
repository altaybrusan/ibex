#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)

#include <vtkObject.h>
#include "View/mainwindow.h"
#include <QApplication>
//#include <QSettings>
#include <Utils/logmgr.h>
#include "coreapplication.h"
#include <QDebug>


int main(int argc, char *argv[])
{
    vtkObject::GlobalWarningDisplayOff();
    //QSettings::setDefaultFormat(QSettings::IniFormat);
    QCoreApplication::setOrganizationName("Bogazici-University");
    QCoreApplication::setApplicationName("iBEX");
    CoreApplication a(argc, argv);

    LogMgr::instance()->Initialize();
    LogMgr::instance()->LogAppInfo(QObject::tr("*** DEVICE STARTED..."));

    MainWindow w;
    qDebug()<<"Hi from here to you!!!";
    w.show();
    return a.exec();

}

