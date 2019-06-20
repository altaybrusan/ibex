#ifndef IROLE_H
#define IROLE_H

#include <QString>

class IRole
{
public:
    virtual  ~IRole(){}
    IRole() {}
};

QT_BEGIN_NAMESPACE
#define RoleInterface_iid "tr.edu.boun.ibex.RoleInterface"
Q_DECLARE_INTERFACE(IRole, RoleInterface_iid)
QT_END_NAMESPACE
#endif // IROLE_H
