#include "demoplugin.h"
#include "irole.h"

DemoPlugin::DemoPlugin(QObject *parent) : QObject(parent)
{

}

QString DemoPlugin::GetToolName()
{
    return "DEMO TOOL";

}

IRole DemoPlugin::GetRequiredRole()
{
  IRole _role= IRole();
  return _role;
}

QString DemoPlugin::GetToolMenuPath()
{
    return "A/B/C";

}
