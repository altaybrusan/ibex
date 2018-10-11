#include "pacssettingmgr.h"
#include "View/pacssettingsdialog.h"
#include "Utils/settingsprovider.h"
#include "Utils/logmgr.h"

PacsSettingMgr::PacsSettingMgr(QObject *parent,PacsSettingsDialog& dialog) :
    QObject(parent),
    m_pacsDlg(dialog)
{

}

QString PacsSettingMgr::GetPACSServerName()
{
    return m_pacsDlg.GetPACSServerAET();
}

QString PacsSettingMgr::GetStorageServerName()
{
    return m_pacsDlg.GetStorageServerAETitle();
}

int PacsSettingMgr::GetPACSServerport()
{
    return m_pacsDlg.GetPACSServerPort();
}

void PacsSettingMgr::OnActivatePacsSettingsDialog()
{
    LogMgr::instance()->LogAppInfo(tr("PACS settings activated"));
    m_pacsDlg.show();
}
