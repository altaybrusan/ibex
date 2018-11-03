#include "algorithmpluginmgr.h"
#include "Utils/logmgr.h"

#include <QPluginLoader>
#include <QDir>
#include <QFileInfo>
#include <QCoreApplication>



AlgorithmPluginMgr::AlgorithmPluginMgr(QObject *parent,QString path) :
    QObject(parent),
    m_path(path)
{
    m_pluginsDir = qApp->applicationDirPath();
    m_pluginsDir.cd("plugins");

}

void AlgorithmPluginMgr::LoadPlugins()
{

    LogMgr::instance()->LogSysInfo("current directory:"+m_pluginsDir.currentPath());


    foreach (QString fileName, m_pluginsDir.entryList(QDir::Files))
    {
        QPluginLoader pluginLoader(m_pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin)
        {
          IAlgorithm* algorithm = dynamic_cast<IAlgorithm*>(plugin);
          if(algorithm)
          {

              if(!m_algorithmContainer.contains(algorithm->GetAlgorithmUID()))
              {
                 //Algorithm is not already registered
                 LogMgr::instance()->LogSysDebug("new algorithm is found");
                 m_algorithmContainer.insert(algorithm->GetAlgorithmUID(),algorithm);
              }
              else
              {
                  LogMgr::instance()->LogSysDebug("algorithm already registered");
              }
          }
        }
    }

    LogMgr::instance()->LogSysInfo("total number of plugins:"+ QString::number(m_algorithmContainer.count()));

}

QMap<int, IAlgorithm *> AlgorithmPluginMgr::GetWidgetList()
{
    return m_algorithmContainer;

}
