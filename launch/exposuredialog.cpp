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

    QDir pluginsDir(qApp->applicationDirPath());


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
    QVBoxLayout *layout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    QList<QWidget*>  pluginsWidgetList;

    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        qDebug()<<"I am processing the plugin : "<<fileName;
        if (plugin) {
            device = qobject_cast<IDevice *>(plugin);
            if (device)
            {
                // There must be a mechanis to order the loaded widgets.
                int device_type=device->GetDeviceType();
                qDebug()<<"... The loaded plugin is:"<<device_type;
                pluginsWidgetList.append(device->GetWidget());
                layout->addWidget(device->GetWidget());
                QFrame *line=new QFrame(this);
                line->setObjectName("line"+QString::number(device_type));
                line->setGeometry(QRect(50, 160, 118, 3));
                line->setFrameShape(QFrame::HLine);
                line->setFrameShadow(QFrame::Sunken);
                layout->addWidget(line);

            }
        }
    }

    qDebug()<<"number of loaded Plugin widgets:"<< pluginsWidgetList.count();

    //    QString FullFileName= QString(TEST_IMAGES_DIR) + "circle-test.tiff";
    //    _viewer->DisplayImage(FullFileName);
    //    FullFileName= QString(TEST_IMAGES_DIR) + "hand-test.tiff";
    //    _viewer->DisplayImage(FullFileName);

}

ExposureDialog::~ExposureDialog()
{
    delete ui;
}
