#ifndef IFOREGROUNDTOOL_H
#define IFOREGROUNDTOOL_H
#include "itool.h"

class IForeGroundTool:public ITool
{
public:
    virtual  ~IForeGroundTool(){}
    IForeGroundTool(){}
    virtual QString GetToolMenuPath()=0;
//    virtual IRole GetRequiredRole()=0;
};

QT_BEGIN_NAMESPACE
#define ForeGroundToolnterface_iid "tr.edu.boun.ibex.ForeGroundToolInterface"
Q_DECLARE_INTERFACE(IForeGroundTool, ForeGroundToolnterface_iid)
QT_END_NAMESPACE
#endif // IFOREGROUNDTOOL_H
