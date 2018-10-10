#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>
#include "Model/databaseconnector.h"
class MainWindow;
class LoginDialog;
class DeviceMgr;


class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup();
    void Show() const;
    ~Startup();

private:
    MainWindow& m_mainWindow;
    LoginDialog& m_loginDlg;
    DeviceMgr& m_device;
    DatabaseConnector& m_dbConnector;
    QString m_dbName,m_dbDriver;


    void LoadiBEXSettings();
    explicit Startup(const Startup& rhs)=delete;
    Startup& operator=(const Startup& rhs)=delete;
};

#endif // STARTUP_H
