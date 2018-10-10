#include "devicemgr.h"
#include <QDebug>
#include "Utils/logmgr.h"

DeviceMgr::DeviceMgr(QObject *parent, MainWindow &mainWindow, LoginDialog &loginDlg) :
    QObject(parent),
    m_mainWindow(mainWindow),
    m_loginDlg(loginDlg)
{
    LogMgr::instance()->LogSysInfo(tr("Device Manager <DeviceMgr> is constructing..."));
}

void DeviceMgr::WireConnections()
{
        connect(&m_mainWindow,&MainWindow::NotifyMainWindowIsLoaded,this,&DeviceMgr::ShowLoginDialog);
}

void DeviceMgr::OnNewStudyWorkFlowIsTriggered()
{

}

void DeviceMgr::OnQuickStudyWorkFlowIsTriggered()
{

}

void DeviceMgr::OnUpdatePACSSettingIsTriggered()
{

}

void DeviceMgr::OnLoadStudyIsTriggered()
{

}

void DeviceMgr::OnUpdateWorklistSettingsIsTriggered()
{

}

void DeviceMgr::OnOpenStudyWorkFlowIsTriggered()
{

}

void DeviceMgr::ShowLoginDialog()
{
  LogMgr::instance()->LogSysInfo(tr("Login dialog is activated"));
  m_loginDlg.show();
  if (m_loginDlg.result() == QDialog::Rejected)
  {
      LogMgr::instance()->LogSysInfo(tr("Login canceled."));
      LogMgr::instance()->LogAppInfo(tr("Login canceled."));
  }
}
