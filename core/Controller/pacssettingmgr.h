#ifndef PACSSETTINGMGR_H
#define PACSSETTINGMGR_H

#include <QObject>
#include <QMap>

class PacsSettingsDialog;


class PacsSettingMgr : public QObject
{
    Q_OBJECT
public:
    explicit PacsSettingMgr(QObject *parent,PacsSettingsDialog& dialog);
    QString GetPACSServerName();
    QString GetStorageServerName();
    int GetPACSServerport();

public slots:
    void OnActivatePacsSettingsDialog();

private:
PacsSettingsDialog& m_pacsDlg;
};

#endif // PACSSETTINGMGR_H
