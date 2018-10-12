#ifndef DEVICEMGR_H
#define DEVICEMGR_H

#include <QObject>
#include "View/mainwindow.h"
#include "View/pacssettingsdialog.h"
#include "Controller/loginmgr.h"
#include "Controller/pacssettingmgr.h"
#include "Controller/worklistserversettingsmgr.h"
#include "View/worklistserversettingsdialog.h"
#include "View/loadstudydialog.h"
#include "Controller/loadstudymgr.h"

class DeviceMgr : public QObject
{
    Q_OBJECT
public:
    explicit DeviceMgr(QObject *parent,
                       MainWindow & mainWindow,
                       LoginMgr& loginMgr,
                       PacsSettingsDialog& pacsSettingsDlg,
                       PacsSettingMgr& pacsSettingsMgr,
                       WorklistServerSettingsDialog& worklistSettingDlg,
                       WorklistServerSettingsMgr& worklistdialogMgr,
                       LoadStudyDialog& loadStudyDlg,
                       LoadStudyMgr& loadStudyMgr);
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
    LoadStudyMgr& m_loadStudyMgr;
    LoadStudyDialog& m_loadStudyDlg;
    LoginMgr& m_loginMgr;
    PacsSettingMgr& m_pacsSettingsMgr;
    PacsSettingsDialog& m_pacsSettingsDlg;
    WorklistServerSettingsDialog& m_worklistSettingsDlg;
    WorklistServerSettingsMgr& m_worklisSettingstMgr;


    void ShutdownDevice();

};

#endif // DEVICEMGR_H
