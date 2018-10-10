#ifndef DEVICEMGR_H
#define DEVICEMGR_H

#include <QObject>
#include "View/mainwindow.h"
#include "View/logindialog.h"

class DeviceMgr : public QObject
{
    Q_OBJECT
public:
    explicit DeviceMgr(QObject *parent,
                       MainWindow & mainWindow,
                       LoginDialog& loginDlg);
    void WireConnections();


signals:

public slots:
private slots:
    void OnNewStudyWorkFlowIsTriggered();
    void OnQuickStudyWorkFlowIsTriggered();
    void OnUpdatePACSSettingIsTriggered();
    void OnLoadStudyIsTriggered();
    void OnUpdateWorklistSettingsIsTriggered();
    void OnOpenStudyWorkFlowIsTriggered();
private:
    MainWindow& m_mainWindow;
    LoginDialog& m_loginDlg;

    void ShowLoginDialog();
};

#endif // DEVICEMGR_H
