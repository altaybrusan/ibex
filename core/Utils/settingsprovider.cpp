#include "settingsprovider.h"

SettingsProvider::SettingsProvider(QString settingFileFullPath, QObject *parent) : QObject(parent)
{
    m_filePath = settingFileFullPath;
}

void SettingsProvider::UpdateSettingFile(QString settingFileFullPath)
{
    m_filePath = settingFileFullPath;
    m_settingFile.setFileName("m_filePath");
}

void SettingsProvider::OpenSettingFile()
{
    if(!m_settingFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        emit NotifyFileOpenFailed();
    }
}

void SettingsProvider::LoadSettingFile()
{
    if(!document.setContent(&m_settingFile))
    {
        emit NotifySettingLoadFailed();
    }
    m_settingFile.close();
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
