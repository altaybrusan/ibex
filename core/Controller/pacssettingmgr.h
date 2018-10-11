#ifndef PACSSETTINGMGR_H
#define PACSSETTINGMGR_H

#include <QObject>
#include <QMap>
class SettingsProvider;
class PacsSettingsDialog;


class PacsSettingMgr : public QObject
{
    Q_OBJECT
public:
    explicit PacsSettingMgr(QObject *parent,PacsSettingsDialog& pacsSettingsDialog);
    void LoadSettings(QString filePath);
signals:
    void NotifyFailedLoadingSettings();

public slots:

private:
PacsSettingsDialog& m_pacsDlg;
QMap<QString, QVariant> m_serverNodes;
};

#endif // PACSSETTINGMGR_H
