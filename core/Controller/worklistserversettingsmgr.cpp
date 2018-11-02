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
        LogMgr::instance()->LogSysError(tr("worklist server setting file is not valid."));
        return;
    }

    LogMgr::instance()->LogSysInfo(tr("worklist settings are loaded successfully."));

    auto root =_provider.GetRootElement();
    QStringList strList = _provider.ListElements(root,"Server","IP");
    m_worklisSettingstDlg.SetWorklistServerIP(strList.at(0));

    strList = _provider.ListElements(root,"Server","Port");
    m_worklisSettingstDlg.SetWorklistServerPort(strList.at(0));

    strList = _provider.ListElements(root,"Server","AETitle");
    m_worklisSettingstDlg.SetWorklistServerAETitle(strList.at(0));

    connect(&m_worklisSettingstDlg,&WorklistServerSettingsDialog::NotifyRejected,
            this,[=](){
             LogMgr::instance()->LogAppInfo(tr("Updating the worklit settings is cancled."));
              m_worklisSettingstDlg.close();});
    connect(&m_worklisSettingstDlg,&WorklistServerSettingsDialog::NotifyAccepted,
            this,&WorklistServerSettingsMgr::OnDialogAccepted);

}

void WorklistServerSettingsMgr::OnActivateWorklistSettingsDialog()
{
    m_worklisSettingstDlg.show();

}

void WorklistServerSettingsMgr::OnDialogAccepted()
{
    QFile settingFile(m_settingsFileName);
    if(!settingFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        LogMgr::instance()->LogSysError(tr("can not open worklist settings file."));
        return;
    }
    else
    {
        LogMgr::instance()->LogSysDebug(tr("worklist settings file successfully opened."));
        //get the root element
        QDomDocument document;

        if(!document.setContent(&settingFile))
        {
            LogMgr::instance()->LogSysError(tr("Failed to load workstation settings file."));
            return;
        }

        QDomElement root = document.firstChildElement();
        auto node = root.elementsByTagName("Server").at(0).toElement();
        node.setAttribute("IP",m_worklisSettingstDlg.GetWorklistServerIP());
        node.setAttribute("AETitle",m_worklisSettingstDlg.GetWorklistServerAETitle());
        node.setAttribute("Port",m_worklisSettingstDlg.GetWorklistServerPort());
        settingFile.resize(0);
        QByteArray xml = document.toByteArray();
        settingFile.write(xml);
        settingFile.close();
        m_worklisSettingstDlg.close();
    }
}
