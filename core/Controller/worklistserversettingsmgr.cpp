#include "worklistserversettingsmgr.h"
#include "Utils/settingsprovider.h"
#include "Utils/logmgr.h"
#include <QtXml>
#include "View/worklistserversettingsdialog.h"

WorklistServerSettingsMgr::WorklistServerSettingsMgr(QObject *parent,
                                                     WorklistServerSettingsDialog &dialog,
                                                     QString settingFile) :
    QObject(parent),
    m_worklisSettingstDlg(dialog),
    m_settingsFileName(settingFile)
{
    SettingsProvider _provider(this);
    _provider.UpdateSettingFile(m_settingsFileName);

    if(!_provider.OpenSettingFile())
    {
        LogMgr::instance()->LogSysError(tr("Can not open Worklist server setting file."));
        return;
    }

    if(!_provider.LoadSettingFile())
    {
        LogMgr::instance()->LogSysError(tr("worklist server Setting file is not valid."));
        return;
    }

    LogMgr::instance()->LogSysInfo(tr("worklist settings are loaded successfully."));

    auto root =_provider.GetRootElement();
    QStringList strList = _provider.ListElements(root,"Server","IP");
    m_worklisSettingstDlg.SetWorklistServerIP(strList.at(0));

    strList = _provider.ListElements(root,"Server","Port");
    m_worklisSettingstDlg.SetWorklistServerPort((static_cast<QString>(strList.at(0)).toInt()));

    strList = _provider.ListElements(root,"Server","AETitle");
    m_worklisSettingstDlg.SetWorklistServerAETitle(strList.at(0));

}

void WorklistServerSettingsMgr::OnActivateWorklistSettingsDialog()
{
    m_worklisSettingstDlg.show();

}

void WorklistServerSettingsMgr::OnDialogAccepted()
{
//    QDomDocument document;
//    QFile settingFile("./configs/_worklist.xml");
//    if(!settingFile.open(QIODevice::ReadWrite | QIODevice::Text))
//    {
//        qDebug()<<"Can not open worklist configuration file";
//        return;
//    }
//    else
//    {
//        qDebug()<<"worklist configuration file successfully opened.";
//        //get the root element
//        QDomDocument document;

//        if(!document.setContent(&settingFile))
//        {
//            qDebug() << "Failed to load document";
//            return;
//        }

//        QDomElement root = document.firstChildElement();
//        auto node = root.elementsByTagName("Server").at(0).toElement();
//        node.setAttribute("IP",ui->ipAddresslineEdit->text());
//        node.setAttribute("AETitle",ui->AETitleLineEdit->text());
//        node.setAttribute("Port",ui->portLineEdit->text());
//        settingFile.resize(0);
//        QByteArray xml = document.toByteArray();
//        settingFile.write(xml);
//        settingFile.close();
//        this->close();
}
