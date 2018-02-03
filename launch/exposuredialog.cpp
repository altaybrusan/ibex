#include "exposuredialog.h"
#include "ui_exposuredialog.h"
#include "imageviewer.h"
#include <QPluginLoader>
#include <QDebug>
#include <QDir>
#include <QCoreApplication>
#include "idevice.h"

ExposureDialog::ExposureDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExposureDialog)
{
    ui->setupUi(this);

    auto _viewer=new ImageViewer(this);
    ui->displayFrame->layout()->addWidget(_viewer);

    QDir pluginsDir(QDir::currentPath());
//#if defined(Q_OS_WIN)
//    if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
//        pluginsDir.cdUp();
//#elif defined(Q_OS_MAC)
//    if (pluginsDir.dirName() == "MacOS") {
//        pluginsDir.cdUp();
//        pluginsDir.cdUp();
//        pluginsDir.cdUp();
//    }
//#endif

    IDevice* device;
    qDebug()<<"I am at: "<<pluginsDir.currentPath();
    pluginsDir.cd("plugins");
    qDebug()<<"Now, I am at: "<<pluginsDir.currentPath();
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();

        qDebug()<<"I am processing: "<<fileName;
        if (plugin) {

            device = qobject_cast<IDevice *>(plugin);
            if (device)
            {
                    qDebug()<<"... The loaded plugin is:"<<device->GetDeviceType();
                    device->UpdateParentWidget(ui->protocolFrame);


            }

        }
    }

//    QString FullFileName= QString(TEST_IMAGES_DIR) + "circle-test.tiff";
//    _viewer->DisplayImage(FullFileName);
//    FullFileName= QString(TEST_IMAGES_DIR) + "hand-test.tiff";
//    _viewer->DisplayImage(FullFileName);

}

ExposureDialog::~ExposureDialog()
{
    delete ui;
}
