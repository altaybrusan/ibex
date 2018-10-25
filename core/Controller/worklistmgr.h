#ifndef WORKLISTMGR_H
#define WORKLISTMGR_H

#include <QObject>
class WorklistDialog;
class WorklistModel;
class WorklistMgr : public QObject
{
    Q_OBJECT
public:
    explicit WorklistMgr(QObject *parent,WorklistDialog& dialog,WorklistModel& model,QString settingFile);

signals:

public slots:
    void OnFetchRISRequestReceived();
    void OnNewRowIsSelected(int row);
    void OnActivateWorklistDialog();
private:
    void InitializeWorklistTableView();
    void InitializeWorklistTableModel();
    void ParsRISResponseAndInsertIntoTableModel();


    WorklistDialog& m_dialog;
    WorklistModel& m_model;
    QString m_settingsFileName;
};

#endif // WORKLISTMGR_H
