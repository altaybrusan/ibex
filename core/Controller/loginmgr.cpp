#include "loginmgr.h"
#include <QSqlQuery>
#include "Utils/logmgr.h"
#include "View/logindialog.h"

LoginMgr::LoginMgr(QObject *parent, LoginDialog &loginDlg) :
    QObject(parent),
    m_loginDlg(loginDlg)
{

    connect(&m_loginDlg, &LoginDialog::accepted,this,&LoginMgr::OnCheckCredintials);
    connect(&m_loginDlg, &LoginDialog::rejected,this,
            [=]{emit NotifyLoginCancelled();});

}

void LoginMgr::ActivateLoginProcess()
{
    m_loginDlg.show();
}

void LoginMgr::OnCheckCredintials()
{
    //Check the database for the loged in user
    // the password should be hashed.

    QString name =m_loginDlg.GetUsername();
    QString password = m_loginDlg.GetPassword();

    QSqlQuery query;
    if(query.exec("SELECT * FROM userTbl"))
    {
        LogMgr::instance()->LogSysInfo(tr("Checking database for user"));

        bool _isfound = false;
        while(query.next())
        {
            QString _uid = "User ID:" + query.value(0).toString();
            QString _pass = "User Password:" +query.value(2).toString();
            LogMgr::instance()->LogSysInfo(_uid + _pass);

            if(query.value(1).toString() == name &&
               query.value(2).toString() == password)
            {
                _isfound =true;
                LogMgr::instance()->LogSysInfo(tr(" %1 successfully signed in").arg(name));
                LogMgr::instance()->LogAppInfo(tr(" %1 successfully signed in").arg(name));
                emit NotifySuccessfulSignin();
                break;
            }
        }
        if(!_isfound)
        {
            LogMgr::instance()->LogSysInfo(tr("unsuccessful sign in"));
            LogMgr::instance()->LogAppInfo(tr("unsuccessful sign in"));
            ActivateLoginProcess();
        }
    }
}
