#ifndef WORKLISTSERVERSETTINGSMGR_H
#define WORKLISTSERVERSETTINGSMGR_H

#include <QObject>

class WorklistServerSettingsMgr : public QObject
{
    Q_OBJECT
public:
    explicit WorklistServerSettingsMgr(QObject *parent,QString settingFileName);

signals:

public slots:

private:
    QString m_settingFile;
};

#endif // WORKLISTSERVERSETTINGSMGR_H
