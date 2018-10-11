#include "pacssettingmgr.h"
#include "Utils/settingsprovider.h"
#include "Utils/logmgr.h"
#include <QtXml>
#include "QVariant"

PacsSettingMgr::PacsSettingMgr(QObject *parent, PacsSettingsDialog& pacsSettingsDialog) :
    QObject(parent),
    m_pacsDlg(pacsSettingsDialog)
{

}

void PacsSettingMgr::LoadSettings(QString filePath)
{
    SettingsProvider _provider;
    _provider.UpdateSettingFile(filePath);
    if(!_provider.OpenSettingFile())
    {
        LogMgr::instance()->LogSysError(tr("can not open PACS setting file."));
        emit NotifyFailedLoadingSettings();
        return;
    }
    if(!_provider.LoadSettingFile())
    {
        LogMgr::instance()->LogSysError(tr("PACS setting file is not valid."));
        emit NotifyFailedLoadingSettings();
        return;
    }

    QDomElement root = _provider.GetRootElement();

    QStringList _Namelist = _provider.ListElements(root,"Server", "Name");
    QStringList _AETitlelist = _provider.ListElements(root,"Server", "AETitle");
    QStringList _Addresslist = _provider.ListElements(root,"Server", "Address");
    QStringList _Portlist = _provider.ListElements(root,"Server", "Port");
    QStringList _CGETlist = _provider.ListElements(root,"Server", "CGET");
    QList<int> lengths;
    lengths
            <<_Namelist.length()
            <<_AETitlelist.count()
            <<_Addresslist.count()
            <<_Portlist.count()
            <<_CGETlist.count();


    int max=*std::max_element(lengths.begin(),lengths.end());

    for(int i=0;i<max;i++)
    {

        m_serverNodes["Name"] = _Namelist.at(i);
        //defaultServerNode["CheckState"] = static_cast<int>(Qt::Checked);
        m_serverNodes["AETitle"] = _AETitlelist.at(i);
        m_serverNodes["Address"] = _Addresslist.at(i);
        m_serverNodes["Port"] = _Portlist.at(i);
        if(_CGETlist.at(i) == "True")
            m_serverNodes["CGET"] = static_cast<int>(Qt::Checked);
        else
            m_serverNodes["CGET"] = static_cast<int>(Qt::Unchecked);
    }

}
