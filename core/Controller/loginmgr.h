#ifndef LOGINMGR_H
#define LOGINMGR_H

#include <QObject>
class LoginDlg;
class LoginMgr : public QObject
{
    Q_OBJECT
public:
    explicit LoginMgr(QObject *parent, LoginDlg& loginDlg);

signals:

public slots:
private:
    LoginDlg& m_loginDlg;
};

#endif // LOGINMGR_H
