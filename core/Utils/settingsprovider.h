#ifndef SETTINGSPROVIDER_H
#define SETTINGSPROVIDER_H

#include <QObject>
#include <QtXml>
#include <QFile>

class SettingsProvider : public QObject
{
    Q_OBJECT
public:
    explicit SettingsProvider(QString settingFileFullPath,
                              QObject *parent = nullptr);
    void UpdateSettingFile(QString settingFileFullPath);
    void OpenSettingFile();
    void LoadSettingFile();
    QDomElement GetRootElement();
    QStringList ListElemnts(QDomElement root,
                            QString tagname,
                            QString attribute);


signals:
    void NotifyFileOpenFailed();
    void NotifySettingLoadFailed();


public slots:
private:
    QString m_filePath;
    QFile m_settingFile;
    QDomDocument document;
};

#endif // SETTINGSPROVIDER_H
