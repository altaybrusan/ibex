#ifndef TOOLSMGR_H
#define TOOLSMGR_H

#include <QObject>
class ToolsDialog;
class DataBaseMgr;
class SettingsProvider;
class ToolsMgr : public QObject
{
    Q_OBJECT
public:
    explicit ToolsMgr(QObject *parent, ToolsDialog& dialog, QString settingFileName);

signals:

private slots:
    void OnAddUser();
    void OnRemoveUser();

public slots:
    void OnActivateToolsDialog();
    void OnDialogAccepted();
private:
    ToolsDialog& m_dialog;
    SettingsProvider& m_provider;
    DataBaseMgr* m_dbMgr;
    QString m_settingsFileName;
    void LoadSystemSettings();

};

#endif // TOOLSMGR_H
