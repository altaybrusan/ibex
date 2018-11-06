#ifndef DEMOPLUGIN_H
#define DEMOPLUGIN_H

#include <QObject>
#include <QWidget>
#include "iforegroundtool.h"

class DemoPlugin : public QObject,IForeGroundTool
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "tr.edu.boun.ibex.ForeGroundToolInterface")
    Q_INTERFACES(IForeGroundTool)
public:
    explicit DemoPlugin(QObject *parent = nullptr);

signals:

public slots:

    // ITool interface
public:
    QString GetToolName();
    IRole GetRequiredRole();

    // IForeGroundTool interface
public:
    QString GetToolMenuPath();
};

#endif // DEMOPLUGIN_H
