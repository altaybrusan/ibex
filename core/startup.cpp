#include "startup.h"
#include "Model/databaseconnector.h"
#include "View/mainwindow.h"
#include "View/logindialog.h"
#include "Controller/loginmgr.h"
#include "Controller/devicemgr.h"
#include "Controller/worklistserversettingsmgr.h"
#include "Utils/logmgr.h"
#include "Utils/settingsprovider.h"
#include "View/pacssettingsdialog.h"
#include "View/worklistserversettingsdialog.h"
#include "Controller/pacssettingmgr.h"
#include "View/loadstudydialog.h"
#include "Controller/loadstudymgr.h"
#include "View/examinationdialog.h"
#include "Controller/examinationmgr.h"
#include "View/worklistdialog.h"
#include "Model/worklistmodel.h"
#include "Controller/worklistmgr.h"
#include "View/newpatientdialog.h"
#include "Controller/newpatientmgr.h"
#include "Model/registrationformmodel.h"
#include <QtXml>
#include <QDomNode>
#include <QMessageBox>
#include <QApplication>

#define IBEX_STTINGS_FILE "./configs/_ibexsettings.xml"
#define WRKLST_SETTING_FILE "./configs/_worklist.xml"
#define LOCAL_PACS_FILE "./database/localpacs.db"
#define LOCALDB_SCHEMA_FILE "./configs/dicom-schema.sql"
Startup::Startup() : QObject(nullptr),
    m_mainWindow(*new MainWindow(nullptr)),
    m_loadStudyDlg(*new LoadStudyDialog(nullptr)),
    m_loadStudyMgr(*new LoadStudyMgr(nullptr,m_loadStudyDlg,LOCAL_PACS_FILE,LOCALDB_SCHEMA_FILE)),
    m_loginDlg(*new LoginDialog(nullptr)),
    m_loginMgr(*new LoginMgr(nullptr,m_loginDlg)),
    m_dbConnector(*new DatabaseConnector(nullptr)),
    m_pacsSettingsDlg(*new PacsSettingsDialog(nullptr)),
    m_pacsSettingsMgr(*new PacsSettingMgr(nullptr,m_pacsSettingsDlg)),
    m_worklistSettingsDlg(*new WorklistServerSettingsDialog(nullptr)),
    m_worklistSettingsMgr(*new WorklistServerSettingsMgr(nullptr,m_worklistSettingsDlg,WRKLST_SETTING_FILE)),
    m_examinationDlg(*new ExaminationDialog(nullptr)),
    m_examinationMgr(*new ExaminationMgr(nullptr,m_examinationDlg)),
    m_worklistDlg(*new WorklistDialog(nullptr)),
    m_worklistMdl(*new WorklistModel(nullptr)),
    m_worklistMgr(*new WorklistMgr(nullptr,m_worklistDlg,m_worklistMdl,WRKLST_SETTING_FILE)),
    m_newPatientDlg(*new NewPatientDialog(nullptr)),
    m_registrationFormModel(*new RegistrationFormModel(nullptr)),
    m_newPatientMgr(*new NewPatientMgr(nullptr,m_newPatientDlg,m_registrationFormModel)),
    m_device(*new DeviceMgr(nullptr,m_mainWindow,
                            m_loginMgr,
                            m_pacsSettingsMgr,
                            m_worklistSettingsMgr,
                            m_loadStudyMgr,
                            m_examinationMgr,
                            m_worklistMgr,
                            m_newPatientMgr))

{
    m_dbConnector.setParent(this);
    LoadiBEXSettings();
    m_dbConnector.AddDatabase(m_dbDriver,m_dbName);
    if(!m_dbConnector.ConnectToDatabase())
    {
        QMessageBox::critical(nullptr,"System crashed","A database connection failed. Please check the system log file");
        LogMgr::instance()->LogSysFail(tr("failed to connect to database"));
        LogMgr::instance()->LogAppFail(tr("unsuccessful start. Database connection failed"));
        exit(1);
    }
    m_loadStudyDlg.setParent(&m_mainWindow);
    m_loadStudyDlg.setWindowFlag( Qt::Window,true);
    m_loadStudyDlg.setModal(true);
    m_loadStudyMgr.setParent(this);

      m_loginDlg.setParent(&m_mainWindow);
      m_loginDlg.setWindowFlag( Qt::Window,true);
      m_loginDlg.setModal(true);
      m_loginDlg.setWindowTitle("Login Dialog");
      m_loginMgr.setParent(this);

      m_pacsSettingsDlg.setParent(&m_mainWindow);
      m_pacsSettingsDlg.setWindowFlag( Qt::Window,true);
      m_pacsSettingsDlg.setModal(true);
      m_pacsSettingsDlg.setWindowTitle("PACS Settings Dialog");
      m_pacsSettingsMgr.setParent(this);

      m_worklistSettingsDlg.setParent(&m_mainWindow);
      m_worklistSettingsDlg.setWindowFlag( Qt::Window,true);
      m_worklistSettingsDlg.setModal(true);
      m_worklistSettingsDlg.setWindowTitle("Worklist Settings Dialog");
      m_worklistSettingsMgr.setParent(this);

      m_examinationDlg.setParent(&m_mainWindow);
      m_examinationDlg.setWindowFlag( Qt::Window,true);
      m_examinationDlg.setModal(true);
      m_examinationDlg.setWindowTitle("Examination Dialog");
      m_examinationMgr.setParent(this);

      m_worklistDlg.setParent(&m_mainWindow);
      m_worklistDlg.setWindowFlag( Qt::Window,true);
      m_worklistDlg.setModal(true);
      m_worklistDlg.setWindowTitle("Select Task Dialog");
      m_worklistMdl.SetDatabase(m_dbConnector.GetDatabase());
      m_worklistMgr.setParent(this);

//      m_newPatientDlg.setParent(&m_mainWindow);
//      m_newPatientDlg.setWindowFlag( Qt::Window,true);
//      m_newPatientDlg.setModal(true);
//      m_newPatientDlg.setWindowTitle("Register New Patient Dialog");
//      m_newPatientMgr.setParent(this);

      m_device.setParent(this);
      m_device.WireConnections();

}

void Startup::Show() const
{
    m_mainWindow.show();
}

Startup::~Startup()
{

}

void Startup::LoadiBEXSettings()
{
    SettingsProvider _provider(this);
    _provider.UpdateSettingFile(IBEX_STTINGS_FILE);

    if(!_provider.OpenSettingFile())
    {
        LogMgr::instance()->LogSysError(tr("Can not open iBEX setting file."));
        FailedToLoad();
        return;

    }
    if(!_provider.LoadSettingFile())
    {
        LogMgr::instance()->LogSysError(tr("iBEX Setting file is not valid."));
        FailedToLoad();
        return;
    }

    LogMgr::instance()->LogSysInfo(tr("iBEX settings are loaded successfully."));
    auto root = _provider.GetRootElement();
    m_dbName = root.childNodes().at(0).firstChild().nodeValue();
    m_dbDriver = root.childNodes().at(1).firstChild().nodeValue();

}

void Startup::FailedToLoad()
{
    QApplication::quit();
}
