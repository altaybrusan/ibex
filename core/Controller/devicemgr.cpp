#include "devicemgr.h"
#include "Utils/logmgr.h"
#include <QApplication>

DeviceMgr::DeviceMgr(QObject *parent,
                     MainWindow &mainWindow,
                     LoginMgr &loginMgr,
                     PacsSettingMgr &pacsSettingsMgr,
                     WorklistServerSettingsMgr &worklistdialogMgr,
                     LoadStudyMgr &loadStudyMgr,
                     ExaminationMgr &examinationMgr,
                     WorklistMgr& worklistMgr,
                     NewPatientMgr &newpatientMgr,
                     ToolsMgr &toolsMgr,
                     FilterPluginMgr &filterMgr) :
    QObject(parent),
    m_mainWindow(mainWindow),
    m_loadStudyMgr(loadStudyMgr),
    m_loginMgr(loginMgr),
    m_pacsSettingsMgr(pacsSettingsMgr),
    m_worklisSettingstMgr(worklistdialogMgr),
    m_examinationMgr(examinationMgr),
    m_newPatientMgr(newpatientMgr),
    m_worklistMgr(worklistMgr),
    m_toolsMgr(toolsMgr),
    m_filtersPluginMgr(filterMgr)
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
  connect(&m_mainWindow,&MainWindow::NotifyLoadStudyIsTriggered,&m_loadStudyMgr,&LoadStudyMgr::OnActivateLoadingStudy);
  connect(&m_mainWindow,&MainWindow::NotifyWorklistLoadIsTriggered,&m_worklistMgr,&WorklistMgr::OnActivateWorklistDialog);
  connect(&m_mainWindow,&MainWindow::NotifyQuickStudyWorkFlowIsTriggered,&m_examinationMgr,&ExaminationMgr::OnActivateExamination);
  connect(&m_mainWindow,&MainWindow::NotifyNewStudyWorkFlowIsTriggered,&m_newPatientMgr,&NewPatientMgr::OnActivateNewPatientDialog);
  connect(&m_mainWindow,&MainWindow::NotiftToolsSettingsIsTriggered,&m_toolsMgr,&ToolsMgr::OnActivateToolsDialog);
  connect(&m_mainWindow,&MainWindow::NotifyEnlistFilterIsTriggered,&m_filtersPluginMgr,&FilterPluginMgr::OnActivateFilterPluginDialog);

}

void DeviceMgr::ShutdownDevice()
{
    QApplication::quit();
}
