#include "toolsmgr.h"
#include "View/toolsdialog.h"
#include "Utils/databasemgr.h"
#include "Utils/logmgr.h"
#include "Utils/settingsprovider.h"
#include <QSqlRecord>
#include <QMessageBox>
#include <QtXml>
#include <QFile>

ToolsMgr::ToolsMgr(QObject *parent, ToolsDialog &dialog, QString settingFileName) :
    QObject(parent),
    m_provider(*new SettingsProvider(nullptr)),
    m_settingsFileName(settingFileName),
    m_dialog(dialog)
{
    connect(&m_dialog,&ToolsDialog::NotifyAddUser,this,&ToolsMgr::OnAddUser);
    connect(&m_dialog,&ToolsDialog::NotifyRemoveUser,this,&ToolsMgr::OnRemoveUser);
     connect(&m_dialog,&ToolsDialog::NotifyDialogAccepted,this,&ToolsMgr::OnDialogAccepted);
    m_dbMgr = DataBaseMgr::instance();

    m_provider.setParent(this);
    m_provider.UpdateSettingFile(m_settingsFileName);
    if(!m_provider.OpenSettingFile())
    {
        LogMgr::instance()->LogSysError(tr("can not open tools setting file."));
        return;
    }

    if(!m_provider.LoadSettingFile())
    {
        LogMgr::instance()->LogSysError(tr("tools file is not valid."));
        return;
    }

    LogMgr::instance()->LogSysInfo(tr("worklist settings are loaded successfully."));

}

void ToolsMgr::OnAddUser()
{
    LogMgr::instance()->LogAppInfo(tr("trying to add new user"));
    LogMgr::instance()->LogSysInfo(tr("trying to add new user"));

    m_dbMgr->OpenDatabase();
    m_dbMgr->FetchDataFromDatabase();
    QSqlRecord _record = m_dbMgr->GetRecordTemplateForUserTable();

    int _id = m_dbMgr->GetNumberOfUsers()+1;
    QString _user = m_dialog.GetUser();
    QString _password = m_dialog.GetPassword();
    int _level =0;

    _record.setValue("userid",_id);
    _record.setValue("username",_user);
    _record.setValue("password",_password);
    _record.setValue("userlevel",_level);

    if(!m_dbMgr->isRecordinUserTable(_record))
    {
        m_dbMgr->AppendIntoUserTable(_record);
        m_dialog.ClearCrenential();
        QMessageBox::information(&m_dialog,"Information","new user is registered",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(&m_dialog,"Information","This credentials already registered in database",QMessageBox::Ok);
    }

}

void ToolsMgr::OnRemoveUser()
{
    QString _user = m_dialog.GetUser();
    QString _password = m_dialog.GetPassword();
    int _level =0;

    LogMgr::instance()->LogAppInfo("trying to remove user: "+_user);
    LogMgr::instance()->LogSysInfo("trying to remove user: "+_user);

    for(int row=1;row<=m_dbMgr->GetNumberOfUsers();row++)
    {
        QSqlRecord _record = m_dbMgr->GetRecordTemplateForUserTable();
        _record.setValue("userid",row);
        _record.setValue("username",_user);
        _record.setValue("password",_password);
        _record.setValue("userlevel",_level);

        if(m_dbMgr->isRecordinUserTable(_record))
        {
            LogMgr::instance()->LogSysInfo("starting to delete");
            m_dbMgr->DeleteRecordFromUserTableAt(row);
            QMessageBox::information(&m_dialog,"Information","the user is removed from database",QMessageBox::Ok);
            m_dialog.ClearCrenential();
        }
    }

}

void ToolsMgr::OnActivateToolsDialog()
{
    LogMgr::instance()->LogAppInfo(tr("tool box is activated"));
    LogMgr::instance()->LogSysInfo(tr("tool box is activated"));
    LoadSystemSettings();
    m_dialog.show();
}

void ToolsMgr::OnDialogAccepted()
{
    QFile settingFile(m_settingsFileName);
    if(!settingFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        LogMgr::instance()->LogSysError(tr("can not open tools settings file."));
        return;
    }
    else
    {
        LogMgr::instance()->LogSysDebug(tr("tool settings file successfully opened."));
        //get the root element
        QDomDocument document;

        if(!document.setContent(&settingFile))
        {
            LogMgr::instance()->LogSysError(tr("Failed to load tools settings file."));
            return;
        }

        QDomElement root = document.firstChildElement();
        auto node =root.firstChildElement("Manufacturer").firstChild();
        node.setNodeValue(m_dialog.GetManufacturer());
        node = root.firstChildElement("InstitutionName").firstChild();
        node.setNodeValue(m_dialog.GetInstitutionName());
        node = root.firstChildElement("StationName").firstChild();
        node.setNodeValue(m_dialog.GetStationName());
        node = root.firstChildElement("ManufacturersModelName").firstChild();
        node.setNodeValue(m_dialog.GetManufacturersModelName());
        settingFile.resize(0);
        QByteArray xml = document.toByteArray();
        settingFile.write(xml);
        settingFile.close();
    }
}

void ToolsMgr::LoadSystemSettings()
{
    auto root = m_provider.GetRootElement();
    m_dialog.UpdateManufacturer(root.firstChildElement("Manufacturer").firstChild().nodeValue());
    m_dialog.UpdateInstitutionName(root.firstChildElement("InstitutionName").firstChild().nodeValue());
    m_dialog.UpdateStationName(root.firstChildElement("StationName").firstChild().nodeValue());
    m_dialog.UpdateManufacturersModelName(root.firstChildElement("ManufacturersModelName").firstChild().nodeValue());

}

