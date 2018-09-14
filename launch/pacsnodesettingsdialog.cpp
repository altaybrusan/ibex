#include "pacsnodesettingsdialog.h"
#include "ui_pacsnodesettingsdialog.h"
#include "ctkDICOMServerNodeWidget.h"
#include "QVariant"
#include <QFile>
//#include <QFileInfo>
#include <QtXml>
#include <QDebug>

PacsNodeSettingsDialog::PacsNodeSettingsDialog(QWidget *parent) :
    QDialog(parent),
    _dicomservernodeWidget(new ctkDICOMServerNodeWidget(this)),
    ui(new Ui::PacsNodeSettingsDialog)
{
    ui->setupUi(this);
    QFile settingFile(":/configs/configs/_pacs.xml");
    //QFileInfo fileInfo(":/configs/configs/_pacs.xml");

    if(!settingFile.open(QIODevice::Text))
    {
        qDebug()<<"Can not open PACS Server configuration file";
    }
    else
    {
         settingFile.close();
    }


//    QMap<QString, QVariant> defaultServerNode;
//    defaultServerNode["Name"] = QString("ExampleHost2");
//    defaultServerNode["CheckState"] = static_cast<int>(Qt::Checked);
//    defaultServerNode["AETitle"] = QString("AETITLE2");
//    defaultServerNode["Address"] = QString("dicom2.example.com");
//    defaultServerNode["Port"] = QString("11113");
//    defaultServerNode["CGET"] = static_cast<int>(Qt::Checked);
//    _dicomservernodeWidget->addServerNode(defaultServerNode);
//    _dicomservernodeWidget->saveSettings();
//    _dicomservernodeWidget->readSettings();

    QHBoxLayout* layout=new QHBoxLayout(ui->frame);
    layout->addWidget(_dicomservernodeWidget);
}

QString PacsNodeSettingsDialog::GetCallingServerAET()
{
    return _dicomservernodeWidget->callingAETitle();
}
QString PacsNodeSettingsDialog::GetStorageAETitle()
{
    return _dicomservernodeWidget->storageAETitle();
}

int PacsNodeSettingsDialog::GetCallingServerPort()
{
    return _dicomservernodeWidget->storagePort();
}

PacsNodeSettingsDialog::~PacsNodeSettingsDialog()
{
    _dicomservernodeWidget->saveSettings();
    _dicomservernodeWidget->readSettings();
    delete ui;
}
