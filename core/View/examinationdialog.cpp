#include "examinationdialog.h"
#include "ui_examinationdialog.h"
#include "imageviewer.h"
#include <QPluginLoader>
#include "Utils/logmgr.h"
#include <QDir>
#include <QCoreApplication>
#include "Model/registrationformmodel.h"
#include "Model/anatomicregionelement.h"
#include <QSqlField>
#include "idevice.h"
#include <QStandardItemModel>


ExaminationDialog::ExaminationDialog(QWidget *parent, ImageViewer &viewer) :
    QDialog(parent),
    m_viewer(viewer),
    ui(new Ui::ExaminationDialog)
{
    ui->setupUi(this);
    LoadDevicePlugins();

}

void ExaminationDialog::UpdatePatientForm(RegistrationFormModel &model)
{
    QString _fullName = model.GetPatientName();

    if(!model.GetPatientMiddleName().isEmpty())
     _fullName = _fullName + "^"+ model.GetPatientMiddleName();
    if(!model.GetPatientLastName().isEmpty())
        _fullName = _fullName + "^" + model.GetPatientLastName();

    ui->fullNameLineEdit->setText(_fullName);
    ui->accessionNumLineEdit->setText(model.GetAccessionNumber());
    ui->dobLineEdit->setText(model.GetPatientDOB());
    ui->sexLineEdit->setText(model.GetPatientGender());

    QMetaEnum _bodyPartMetaEnum = QMetaEnum::fromType<iBEX::BODY_PART>();
    QMetaEnum _bodyPartPositionMetaEnum = QMetaEnum::fromType<iBEX::PATIENT_POSISTION>();
    table =new QStandardItemModel(model.GetAnatomicRegionList().count(), 2);
    for(int row=0;row<model.GetAnatomicRegionList().count();row++)
    {
        iBEX::BODY_PART _part = model.GetAnatomicRegionList().at(row).GetBodyPart();
        iBEX::PATIENT_POSISTION _pos =model.GetAnatomicRegionList().at(row).GetBodyPartView();


        QString _bodyPartName = QString::fromUtf8(_bodyPartMetaEnum.valueToKey(static_cast<int>(_part)));
        QString _bodyPartPos = QString::fromUtf8(_bodyPartPositionMetaEnum.valueToKey(static_cast<int>(_pos)));

        QStandardItem *bodyPartItem = new QStandardItem(_bodyPartName);
        QStandardItem *bodyPartPosItem = new QStandardItem(_bodyPartPos);

        table->setItem(row, 0 , bodyPartItem);
        table->setItem(row, 1 , bodyPartPosItem);
    }

   table->setHorizontalHeaderItem(0,new QStandardItem(tr("Body part")));
   table->setHorizontalHeaderItem(1,new QStandardItem(tr("View")));
   ui->procedureTableView->horizontalHeader()->setStretchLastSection(true);
   ui->procedureTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
   ui->procedureTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
   ui->procedureTableView->setModel(table);


}

void ExaminationDialog::Show()
{
   m_viewer.ClearImageViewer();
   ui->displayFrame->layout()->addWidget(&m_viewer);
   m_viewer.DisplayImage("C:/temp/113.tiff");
   this->show();
}

ExaminationDialog::~ExaminationDialog()
{
    delete ui;
}

void ExaminationDialog::LoadDevicePlugins()
{
    QDir pluginsDir(qApp->applicationDirPath());
   /*
    #if defined(Q_OS_WIN)
        if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
            pluginsDir.cdUp();
    #elif defined(Q_OS_MAC)
        if (pluginsDir.dirName() == "MacOS") {
            pluginsDir.cdUp();
            pluginsDir.cdUp();
            pluginsDir.cdUp();
        }
    #endif
   */

    IDevice* device;
    LogMgr::instance()->LogSysInfo("current directory:"+pluginsDir.currentPath());
    pluginsDir.cd("plugins");
    QVBoxLayout *layout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    QList<QWidget*>  _deviceWidgetList;

    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
         LogMgr::instance()->LogSysInfo("processing plugin:"+fileName);

        if (plugin) {
            device = qobject_cast<IDevice *>(plugin);
            if (device)
            {
                // There must be a mechanism to order the loaded widgets.
                int device_type=device->GetDeviceType();
                LogMgr::instance()->LogSysInfo("device type:"+QString::number(device_type));
                _deviceWidgetList.append(device->GetWidget());
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

     LogMgr::instance()->LogSysInfo("total number of loaded plugins:"+QString::number(_deviceWidgetList.count()));

}
