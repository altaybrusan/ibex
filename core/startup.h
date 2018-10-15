#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>
#include "Model/databaseconnector.h"
class MainWindow;
class LoginDialog;
class DeviceMgr;
class LoginMgr;
class PacsSettingMgr;
class PacsSettingsDialog;
class WorklistServerSettingsMgr;
class WorklistServerSettingsDialog;
class LoadStudyDialog;
class LoadStudyMgr;


class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup();
    void Show() const;
    ~Startup();

private:
    MainWindow& m_mainWindow;
    LoadStudyDialog& m_loadStudyDlg;
    LoadStudyMgr& m_loadStudyMgr;
    LoginDialog& m_loginDlg;
    LoginMgr& m_loginMgr;
    DatabaseConnector& m_dbConnector;
    QString m_dbName,m_dbDriver;
    PacsSettingsDialog& m_pacsSettingsDlg;
    PacsSettingMgr& m_pacsSettingsMgr;
    WorklistServerSettingsDialog& m_worklistDlg;
    WorklistServerSettingsMgr& m_worklistMgr;
    DeviceMgr& m_device;



    void LoadiBEXSettings();
    void FailedToLoad();
    explicit Startup(const Startup& rhs)=delete;
    Startup& operator=(const Startup& rhs)=delete;
};

#endif // STARTUP_H
