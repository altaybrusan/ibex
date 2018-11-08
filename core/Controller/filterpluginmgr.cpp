#include "filterpluginmgr.h"
#include "Utils/logmgr.h"

#include <QPluginLoader>
#include <QDir>
#include <QFileInfo>
#include "View/filtersdialog.h"




FilterPluginMgr::FilterPluginMgr(QObject *parent,QString path) :
    QObject(parent),
    m_path(path),
    m_dialog(*new FiltersDialog(nullptr))
{

}

FilterPluginMgr::FilterPluginMgr(QObject *parent, FiltersDialog &Dialog, QString path):
    QObject(parent),
    m_path(path),
    m_dialog(Dialog)
{
    connect(&m_dialog,&FiltersDialog::NotifyItemCheckChanged,this,&FilterPluginMgr::OnItemCheckChanged);

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

void FilterPluginMgr::OnActivateFilterPluginDialog()
{
    LoadPlugins();
    for(int idx=1;idx<=m_algorithmContainer.count();idx++)
    {
        LogMgr::instance()->LogSysDebug("plugin name:"+m_algorithmContainer[idx]->AlgorithmName());
        m_dialog.AddItemToList(m_algorithmContainer[idx]->AlgorithmName());
    }
    m_dialog.show();
}

void FilterPluginMgr::OnItemCheckChanged(int row, bool check)
{
    // The FiltersDialog issues the index based on zero;
    // however, the QMap of algorithms index starts from one.

    int mapped_index =row+1;
    m_algorithmContainer[mapped_index]->SetAlgorithmEnabled(check);

}
