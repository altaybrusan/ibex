#include "worklistserversettingsmgr.h"
#include "Utils/settingsprovider.h"
#include "Utils/logmgr.h"

WorklistServerSettingsMgr::WorklistServerSettingsMgr(QObject *parent, QString settingFileName) :
    QObject(parent),
    m_settingFile(settingFileName)
{
    SettingsProvider _provider(this);
    _provider.UpdateSettingFile(settingFileName);

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

    LogMgr::instance()->LogSysInfo(tr("iBEX settings are loaded successfully."));

}
