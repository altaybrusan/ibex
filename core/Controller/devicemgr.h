#ifndef DEVICEMGR_H
#define DEVICEMGR_H

#include <QObject>
#include "View/mainwindow.h"
#include "Controller/loginmgr.h"

class DeviceMgr : public QObject
{
    Q_OBJECT
public:
    explicit DeviceMgr(QObject *parent,
                       MainWindow & mainWindow,
                       LoginMgr& loginMgr);
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
    LoginMgr& m_loginMgr;

    void ShutdownDevice();

    //void ShowLoginDialog();
};

#endif // DEVICEMGR_H
