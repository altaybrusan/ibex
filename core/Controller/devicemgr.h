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
#include "View/examinationdialog.h"
#include "Controller/examinationmgr.h"
#include "Controller/worklistmgr.h"

class DeviceMgr : public QObject
{
    Q_OBJECT
public:
    explicit DeviceMgr(QObject *parent,
                       MainWindow & mainWindow,
                       LoginMgr& loginMgr,
                       PacsSettingMgr& pacsSettingsMgr,
                       WorklistServerSettingsMgr& worklistdialogMgr,
                       LoadStudyMgr& loadStudyMgr,
                       ExaminationMgr& examinationMgr,
                       WorklistMgr& worklistMgr);
    void WireConnections();


signals:

public slots:

private:
    MainWindow& m_mainWindow;
    LoadStudyMgr& m_loadStudyMgr;
    LoginMgr& m_loginMgr;
    PacsSettingMgr& m_pacsSettingsMgr;
    WorklistServerSettingsMgr& m_worklisSettingstMgr;
    ExaminationMgr& m_examinationMgr;
    WorklistMgr& m_worklistMgr;


    void ShutdownDevice();

};

#endif // DEVICEMGR_H
