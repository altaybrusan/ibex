#include "filterpluginmgr.h"
#include "Utils/logmgr.h"

#include <QPluginLoader>
#include <QDir>
#include <QFileInfo>



FilterPluginMgr::FilterPluginMgr(QObject *parent,QString path) :
    QObject(parent),
    m_path(path)
{

}

void FilterPluginMgr::LoadPlugins()
{

    m_pluginsDir.setPath(m_path);
    LogMgr::instance()->LogSysInfo("algorithm plugins are loaded from: "+m_pluginsDir.path());


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

QMap<int, IAlgorithm *> FilterPluginMgr::GetWidgetList()
{
    return m_algorithmContainer;

}
