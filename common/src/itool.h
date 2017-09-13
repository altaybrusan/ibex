#ifndef ITOOL_H
#define ITOOL_H
#include <QString>
#include "irole.h"

class ITool
{
public:
    virtual  ~ITool(){}
    ITool() {}
    virtual QString GetToolName()=0;
    virtual IRole GetRequiredRole()=0;
};

QT_BEGIN_NAMESPACE
#define ToolInterface_iid "tr.edu.boun.ibex.ToolInterface"
Q_DECLARE_INTERFACE(ITool, ToolInterface_iid)
QT_END_NAMESPACE
#endif // ITOOL_H
