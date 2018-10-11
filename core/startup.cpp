#include "startup.h"
#include "Model/databaseconnector.h"
#include "View/mainwindow.h"
#include "View/logindialog.h"
#include "Controller/loginmgr.h"
#include "Controller/devicemgr.h"
#include "Utils/logmgr.h"
#include "Utils/settingsprovider.h"
#include <QtXml>
#include <QDomNode>
#include <QMessageBox>
#include <QApplication>

#define IBEX_STTINGS_FILE "./configs/_ibexsettings.xml"
#define IBEX_PACKS_SETTINGS_FILE "./configs/_pacs.xml"
Startup::Startup() : QObject(nullptr),
    m_mainWindow(*new MainWindow(nullptr)),
    m_loginDlg(*new LoginDialog(nullptr)),
    m_loginMgr(*new LoginMgr(nullptr,m_loginDlg)),
    m_dbConnector(*new DatabaseConnector(nullptr)),
    m_device(*new DeviceMgr(nullptr,m_mainWindow,m_loginMgr))

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
      m_loginDlg.setParent(&m_mainWindow);
      m_loginDlg.setWindowFlag( Qt::Window,true);
      m_loginDlg.setModal(true);

      m_loginMgr.setParent(this);
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
