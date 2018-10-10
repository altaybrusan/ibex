#include "devicemgr.h"
#include <QDebug>
#include "Utils/logmgr.h"
#include <QApplication>

DeviceMgr::DeviceMgr(QObject *parent, MainWindow &mainWindow, LoginMgr &loginMgr) :
    QObject(parent),
    m_mainWindow(mainWindow),
    m_loginMgr(loginMgr)
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

//void DeviceMgr::ShowLoginDialog()
//{
//  LogMgr::instance()->LogSysInfo(tr("Login dialog is activated"));
//  m_loginDlg.show();
//  if (m_loginDlg.result() == QDialog::Rejected)
//  {
//      LogMgr::instance()->LogSysInfo(tr("Login canceled."));
//      LogMgr::instance()->LogAppInfo(tr("Login canceled."));
//  }
//}
