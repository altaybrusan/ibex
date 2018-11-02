#include "toolsmgr.h"
#include "View/toolsdialog.h"
#include "Utils/databasemgr.h"
#include "Utils/logmgr.h"
#include <QSqlRecord>

ToolsMgr::ToolsMgr(QObject *parent, ToolsDialog &dialog) :
    QObject(parent),
    m_dialog(dialog)
{
    connect(&m_dialog,&ToolsDialog::NotifyAddUser,this,&ToolsMgr::OnAddUser);
    connect(&m_dialog,&ToolsDialog::NotifyRemoveUser,this,&ToolsMgr::OnRemoveUser);
    m_dbMgr = DataBaseMgr::instance();

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

    m_dbMgr->AppendIntoUserTable(_record);


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
        }
    }



}

void ToolsMgr::OnActivateToolsDialog()
{
    LogMgr::instance()->LogAppInfo(tr("tool box is activated"));
    LogMgr::instance()->LogSysInfo(tr("tool box is activated"));
    m_dialog.show();
}

