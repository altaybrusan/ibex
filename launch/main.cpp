#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)

#include <vtkObject.h>
#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    //vtkObject::GlobalWarningDisplayOff();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
