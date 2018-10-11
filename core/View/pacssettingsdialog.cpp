#include "pacssettingsdialog.h"
#include "ui_pacsnodesettingsdialog.h"
#include "ctkDICOMServerNodeWidget.h"
#include "QVariant"
#include <QFile>
#include <QtXml>
#include <QDebug>


QStringList ListElements(QDomElement root, QString tagname, QString attribute)
{
    QStringList _elemntList;
    QDomNodeList items = root.elementsByTagName(tagname);

     for(int i = 0; i < items.count(); i++)
     {
        QDomNode itemnode = items.at(i);
        if(itemnode.isElement())
        {
            QDomElement itemele = itemnode.toElement();
            _elemntList.append(itemele.attribute(attribute));
        }
     }
     return _elemntList;
}

PacsSettingsDialog::PacsSettingsDialog(QWidget *parent) :
    QDialog(parent),
    _dicomservernodeWidget(new ctkDICOMServerNodeWidget(this)),
    ui(new Ui::PacsSettingsDialog)
{
    ui->setupUi(this);
    QApplication::setOverrideCursor(Qt::WaitCursor);

//        _dicomservernodeWidget->saveSettings();
//        _dicomservernodeWidget->readSettings();


//    }

    QHBoxLayout* layout=new QHBoxLayout(ui->frame);
    layout->addWidget(_dicomservernodeWidget);
    QApplication::restoreOverrideCursor();
}

QString PacsSettingsDialog::GetCallingServerAET()
{
    return _dicomservernodeWidget->callingAETitle();
}
QString PacsSettingsDialog::GetStorageAETitle()
{
    return _dicomservernodeWidget->storageAETitle();
}

int PacsSettingsDialog::GetCallingServerPort()
{
    return _dicomservernodeWidget->storagePort();
}

void PacsSettingsDialog::ClearAllPACSNodes()
{
    //clear all default server nodes
    for (int indx=0; indx<_dicomservernodeWidget->serverNodes().count();indx++)
    {
        _dicomservernodeWidget->removeCurrentServerNode();
    }
}

void PacsSettingsDialog::AddPACSNodes(QMap<QString, QVariant> nodes)
{
    _dicomservernodeWidget->addServerNode(nodes);
}

PacsSettingsDialog::~PacsSettingsDialog()
{
    _dicomservernodeWidget->saveSettings();
    _dicomservernodeWidget->readSettings();
    delete ui;
}

