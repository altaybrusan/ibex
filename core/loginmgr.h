#ifndef LOGINMGR_H
#define LOGINMGR_H

#include <QObject>

class LoginMgr : public QObject
{
    Q_OBJECT
public:
    explicit LoginMgr(QObject *parent = nullptr);

signals:

public slots:
};

#endif // LOGINMGR_H