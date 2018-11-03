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



//                 QDir testDir(qApp->applicationDirPath());
//                 testDir.cd("test");
//                  QString fileName = "C:\\Users\\Altay\\Documents\\Qt\\Projects\\ibex\\build\\release\\test\\phantom.tiff";
//                  vtkSmartPointer<vtkImageReader2> imageReader =vtkSmartPointer<vtkImageReader2>::New();
//                  vtkSmartPointer<vtkImageReader2Factory> imageFactory = vtkSmartPointer<vtkImageReader2Factory>::New();
//                  imageReader.TakeReference(imageFactory->CreateImageReader2(fileName.toLatin1()));
//                  if (!imageReader)
//                  {
//                      LogMgr::instance()->LogSysDebug("failed to instanciate image reader using: " + fileName);
//                      QMessageBox::warning(this,tr("error loading file"),tr("can not load the file"),QMessageBox::Ok);
//                      return;
//                  }
//                  else
//                  {
//                      //Read image
//                      imageReader->SetFileName(fileName.toLatin1());
//                      imageReader->Update();
//                      vtkSmartPointer<vtkImageData> _imgData =
//                              vtkSmartPointer<vtkImageData>::New();
//                      _imgData= imageReader->GetOutput();
//                      QList<vtkSmartPointer<vtkImageData>> _list;
//                      _list.append(_imgData);
//                      algorithm->SetInputData(_list);
//                      algorithm->UpdateParentWidget(ui->FilterArea);
//                  }

          }
        }
    }

    LogMgr::instance()->LogSysInfo("total number of plugins:"+ QString::number(m_algorithmContainer.count()));

}

QMap<int, IAlgorithm *> AlgorithmPluginMgr::GetWidgetList()
{
    return m_algorithmContainer;

}
