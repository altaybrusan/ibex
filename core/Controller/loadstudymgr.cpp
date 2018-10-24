#include "loadstudymgr.h"
#include <ctkDICOMDatabase.h>
#include <QSharedPointer>
#include "View/loadstudydialog.h"
#include "Utils/logmgr.h"


LoadStudyMgr::LoadStudyMgr(QObject *parent,
                           LoadStudyDialog &dialog,
                           QString dbFilename,
                           QString sqlSchematicsFileName
                           ) :
    m_dialog(dialog),
    QObject(parent)
{
    LogMgr::instance()->LogSysInfo("Load Study manager is initiating...");
    //if database does not exists then create it otherwise use it

    // it is not best practice to costruct the database here in object constructor
    // in the next iteration move it to a seperate function
    m_dbptr =
      QSharedPointer<ctkDICOMDatabase>(new ctkDICOMDatabase(this));

    m_dbptr->updateSchema(sqlSchematicsFileName.toUtf8());
    m_dbptr->openDatabase(dbFilename,"iBEX-LOCAL-PACS");
    m_dialog.UpdateRetrieveDatabase(m_dbptr);
    connect(&m_dialog,&LoadStudyDialog::NotifyLoadStudyDialogIsClosing,
            this,[=](){
        LogMgr::instance()->LogAppInfo(tr("loading study is closing"));
        LogMgr::instance()->LogSysInfo(tr("load study is closing."));
        m_dialog.close();
    });
}

void LoadStudyMgr::ActivateLoadingStudy()
{
    LogMgr::instance()->LogAppInfo(tr("load study is started"));
    LogMgr::instance()->LogSysInfo(tr("load study is activated."));
    m_dialog.show();
}





