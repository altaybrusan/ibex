#include "settingsprovider.h"

SettingsProvider::SettingsProvider(QObject *parent) : QObject(parent)
{    
}

void SettingsProvider::UpdateSettingFile(QString settingFileFullPath)
{
    m_filePath = settingFileFullPath;
    m_settingFile.setFileName(m_filePath);
}

bool SettingsProvider::OpenSettingFile()
{
    if(!m_settingFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        return false;
    }
    return true;
}

bool SettingsProvider::LoadSettingFile()
{
    if(!document.setContent(&m_settingFile))
    {
        return false;
    }
    m_settingFile.close();
    return true;

}

QDomElement SettingsProvider::GetRootElement()
{
    return document.firstChildElement();
}

QStringList SettingsProvider::ListElemnts(QDomElement root, QString tagname, QString attribute)
{
    QStringList _elemntList;
    QDomNodeList items = root.elementsByTagName(tagname);

     for(int i = 0; i < items.count(); i++)
     {
        QDomNode itemnode = items.at(i);
        if(itemnode.isElement())
        {
            QDomElement itemele = itemnode.toElement();
            _elemntList.append(itemele.attribute(attribute));
        }
     }
     return _elemntList;

}
