#include "worklistserversettingsdialog.h"
#include "ui_worklistserversettingsdialog.h"
#include <QtXml>
#include <QFile>

QStringList ListElements2(QDomElement root, QString tagname, QString attribute)
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


WorklistServerSettingsDialog::WorklistServerSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorklistServerSettingsDialog)
{
    ui->setupUi(this);

    QDomDocument document;
    QFile settingFile("./configs/_worklist.xml");

    if(!settingFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug()<<"Can not open worklist configuration file";
        return;
    }
    else
    {
        qDebug()<<"worklist configuration file successfully opened.";
        //get the root element
        QDomDocument document;

        if(!document.setContent(&settingFile))
        {
            qDebug() << "Failed to load document";
            return;
        }
        settingFile.close();
        QDomElement root = document.firstChildElement();
        QStringList strList = ListElements2(root,"Server","IP");
        ui->ipAddresslineEdit->setText(strList.at(0));
        strList = ListElements2(root,"Server","Port");
        ui->portLineEdit->setText(strList.at(0));
        strList = ListElements2(root,"Server","AETitle");
        ui->AETitleLineEdit->setText(strList.at(0));
    }
}

WorklistServerSettingsDialog::~WorklistServerSettingsDialog()
{
    delete ui;
}

void WorklistServerSettingsDialog::on_buttonBox_accepted()
{
    QDomDocument document;
    QFile settingFile("./configs/_worklist.xml");
    if(!settingFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug()<<"Can not open worklist configuration file";
        return;
    }
    else
    {
        qDebug()<<"worklist configuration file successfully opened.";
        //get the root element
        QDomDocument document;

        if(!document.setContent(&settingFile))
        {
            qDebug() << "Failed to load document";
            return;
        }

        QDomElement root = document.firstChildElement();
        auto node = root.elementsByTagName("Server").at(0).toElement();
        node.setAttribute("IP",ui->ipAddresslineEdit->text());
        node.setAttribute("AETitle",ui->AETitleLineEdit->text());
        node.setAttribute("Port",ui->portLineEdit->text());
        settingFile.resize(0);
        QByteArray xml = document.toByteArray();
        settingFile.write(xml);
        settingFile.close();
        this->close();
    }

}

void WorklistServerSettingsDialog::on_buttonBox_rejected()
{
    this->close();
}
