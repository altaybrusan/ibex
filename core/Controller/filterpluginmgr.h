#ifndef ALGORITHMPLUGINMGR_H
#define ALGORITHMPLUGINMGR_H

#include <QObject>
#include <QDir>
#include "ialgorithm.h"
#include <QMap>

class FilterPluginMgr : public QObject
{
    Q_OBJECT
public:
    explicit FilterPluginMgr(QObject *parent, QString path);

    void LoadPlugins();
    QMap<int,IAlgorithm*> GetWidgetList();

signals:

public slots:
private:
    QString m_path;
    QDir m_pluginsDir;
    QMap<int,IAlgorithm*> m_algorithmContainer;

};

#endif // ALGORITHMPLUGINMGR_H
