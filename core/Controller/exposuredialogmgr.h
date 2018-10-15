#ifndef EXPOSUREDIALOGMGR_H
#define EXPOSUREDIALOGMGR_H

#include <QObject>

class ExposureDialogMgr : public QObject
{
    Q_OBJECT
public:
    explicit ExposureDialogMgr(QObject *parent = nullptr);

signals:

public slots:
};

#endif // EXPOSUREDIALOGMGR_H