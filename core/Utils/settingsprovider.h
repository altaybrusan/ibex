#ifndef SETTINGSPROVIDER_H
#define SETTINGSPROVIDER_H

#include <QObject>
#include <QtXml>
#include <QFile>

class SettingsProvider : public QObject
{
    Q_OBJECT
public:
    explicit SettingsProvider(QObject *parent = nullptr);
    void UpdateSettingFile(QString settingFileFullPath);
    bool OpenSettingFile();
    bool LoadSettingFile();
    QDomElement GetRootElement();
    QStringList ListElemnts(QDomElement root,
                            QString tagname,
                            QString attribute);


public slots:
private:
    QString m_filePath;
    QFile m_settingFile;
    QDomDocument document;
};

#endif // SETTINGSPROVIDER_H
