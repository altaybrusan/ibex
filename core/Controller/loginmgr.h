#ifndef LOGINMGR_H
#define LOGINMGR_H

#include <QObject>
class LoginDialog;
class LoginMgr : public QObject
{
    Q_OBJECT
public:
    explicit LoginMgr(QObject *parent, LoginDialog &loginDlg);
    QString GetActiveUser();


signals:
    void NotifySuccessfulSignin();
    void NotifyLoginCancelled();

public slots:

     void ActivateLoginProcess();
private slots:
    void OnCheckCredintials();
private:
    LoginDialog& m_loginDlg;
};

#endif // LOGINMGR_H
