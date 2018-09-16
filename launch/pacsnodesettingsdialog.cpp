#include "pacsnodesettingsdialog.h"
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

PacsNodeSettingsDialog::PacsNodeSettingsDialog(QWidget *parent) :
    QDialog(parent),
    _dicomservernodeWidget(new ctkDICOMServerNodeWidget(this)),
    ui(new Ui::PacsNodeSettingsDialog)
{
    ui->setupUi(this);
    QApplication::setOverrideCursor(Qt::WaitCursor);

    QFile settingFile("./configs/_pacs.xml");

    if(!settingFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can not open PACS Server configuration file";
        return;
    }
    else
    {
        //get the root element
        QDomDocument document;

        if(!document.setContent(&settingFile))
        {
            qDebug() << "Failed to load document";
            return;
        }
        settingFile.close();

        QDomElement root = document.firstChildElement();

        QStringList _Namelist = ListElements(root,"Server", "Name");
        QStringList _AETitlelist = ListElements(root,"Server", "AETitle");
        QStringList _Addresslist = ListElements(root,"Server", "Address");
        QStringList _Portlist = ListElements(root,"Server", "Port");
        QStringList _CGETlist = ListElements(root,"Server", "CGET");
        QList<int> lengths;
        lengths
                <<_Namelist.length()
                <<_AETitlelist.count()
                <<_Addresslist.count()
                <<_Portlist.count()
                <<_CGETlist.count();

        //clear all default server nodes
        for (int indx=0; indx<_dicomservernodeWidget->serverNodes().count();indx++)
        {
            _dicomservernodeWidget->removeCurrentServerNode();
        }


        int max=*std::max_element(lengths.begin(),lengths.end());
        QMap<QString, QVariant> defaultServerNode;
        for(int i=0;i<max;i++)
        {

            defaultServerNode["Name"] = _Namelist.at(i);
            //defaultServerNode["CheckState"] = static_cast<int>(Qt::Checked);
            defaultServerNode["AETitle"] = _AETitlelist.at(i);
            defaultServerNode["Address"] = _Addresslist.at(i);
            defaultServerNode["Port"] = _Portlist.at(i);
            if(_CGETlist.at(i) == "True")
                defaultServerNode["CGET"] = static_cast<int>(Qt::Checked);
            else
                defaultServerNode["CGET"] = static_cast<int>(Qt::Unchecked);

            _dicomservernodeWidget->addServerNode(defaultServerNode);
        }

        _dicomservernodeWidget->saveSettings();
        _dicomservernodeWidget->readSettings();


    }

    QHBoxLayout* layout=new QHBoxLayout(ui->frame);
    layout->addWidget(_dicomservernodeWidget);
    QApplication::restoreOverrideCursor();
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
