#ifndef DEVICEMGR_H
#define DEVICEMGR_H

#include <QObject>

class DeviceMgr : public QObject
{
    Q_OBJECT
public:
    explicit DeviceMgr(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DEVICEMGR_H
