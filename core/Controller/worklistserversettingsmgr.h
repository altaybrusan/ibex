#ifndef WORKLISTSERVERSETTINGSMGR_H
#define WORKLISTSERVERSETTINGSMGR_H

#include <QObject>

class WorklistServerSettingsDialog;
class WorklistServerSettingsMgr : public QObject
{
    Q_OBJECT
public:
    explicit WorklistServerSettingsMgr(QObject *parent,
                                       WorklistServerSettingsDialog & dialog,
                                       QString settingFile);

signals:

public slots:
    void OnActivateWorklistSettingsDialog();
private slots:
    void OnDialogAccepted();

private:
    QString m_settingsFileName;
    WorklistServerSettingsDialog& m_worklisSettingstDlg;

};

#endif // WORKLISTSERVERSETTINGSMGR_H
