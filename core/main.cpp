#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)

#include <vtkObject.h>
#include "View/mainwindow.h"
#include <QApplication>
#include <QSettings>
//#include <QDebug>
#include <Utils/logmgr.h>

//#include "dcmtk/config/osconfig.h"    /* make sure OS specific configuration is included first */
//#include "dcmtk/dcmdata/dcuid.h"
//#include "dcmtk/ofstd/ofstream.h"


int main(int argc, char *argv[])
{

//    char uid[100];
//    qDebug() << "Series Instance UID : " << dcmGenerateUniqueIdentifier(uid, SITE_SERIES_UID_ROOT);


    vtkObject::GlobalWarningDisplayOff();
    QSettings::setDefaultFormat(QSettings::IniFormat);
    QCoreApplication::setOrganizationName("Bogazici-University");
    QCoreApplication::setApplicationName("iBEX");
    QApplication a(argc, argv);

    LogMgr::instance()->Initialize();
    LogMgr::instance()->LogAppInfo("*** SYSTEM LOGIN");


    //MainWindow w;
    //w.show();
    return a.exec();

}
