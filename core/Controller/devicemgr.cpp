#include "devicemgr.h"
#include <QDebug>
#include "Utils/logmgr.h"
#include <QApplication>

DeviceMgr::DeviceMgr(QObject *parent, MainWindow &mainWindow,
                     LoginMgr &loginMgr,
                     PacsSettingsDialog &pacsSettingsDlg,
                     PacsSettingMgr &pacsSettingsMgr,
                     WorklistServerSettingsDialog &worklistSettingDlg,
                     WorklistServerSettingsMgr &worklistdialogMgr) :
    QObject(parent),
    m_mainWindow(mainWindow),
    m_loginMgr(loginMgr),
    m_pacsSettingsDlg(pacsSettingsDlg),
    m_pacsSettingsMgr(pacsSettingsMgr),
    m_worklistSettingsDlg(worklistSettingDlg),
    m_worklisSettingstMgr(worklistdialogMgr)
{

    LogMgr::instance()->LogSysInfo(tr("Device Manager <DeviceMgr> is constructing..."));

}

void DeviceMgr::WireConnections()
{
  connect(&m_mainWindow,&MainWindow::NotifyMainWindowIsLoaded,&m_loginMgr,&LoginMgr::ActivateLoginProcess);
  connect(&m_loginMgr,&LoginMgr::NotifyLoginCancelled,this,[=]
  {
      LogMgr::instance()->LogAppInfo(tr("log in process is cancelled."));
      LogMgr::instance()->LogSysInfo(tr("user cancelled sign-in"));
      ShutdownDevice();
  });
  connect(&m_mainWindow,&MainWindow::NotifyUpdatePACSSettingIsTriggered,&m_pacsSettingsMgr,&PacsSettingMgr::OnActivatePacsSettingsDialog);
  connect(&m_mainWindow,&MainWindow::NotifyUpdateWorklistSettingsIsTriggered,&m_worklisSettingstMgr,&WorklistServerSettingsMgr::OnActivateWorklistSettingsDialog);
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

void DeviceMgr::ShutdownDevice()
{
    QApplication::quit();
}
