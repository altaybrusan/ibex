#include "loginmgr.h"

LoginMgr::LoginMgr(QObject *parent, LoginDlg &loginDlg) :
    QObject(parent),
    m_loginDlg(loginDlg)
{
}
