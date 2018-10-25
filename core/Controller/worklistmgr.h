#ifndef WORKLISTMGR_H
#define WORKLISTMGR_H

#include <QObject>
class WorkListDialog;
class WorklistMgr : public QObject
{
    Q_OBJECT
public:
    explicit WorklistMgr(QObject *parent,WorkListDialog& dialog);

signals:

public slots:
    void OnFetchRISRequestReceived();
    void OnNewRowIsSelected(int row);
private:
    void InitializeWorklistTableView();
    void InitializeWorklistTableModel();
    void ParsRISResponseAndInsertIntoTableModel();


    WorkListDialog& m_worklistDlg;
};

#endif // WORKLISTMGR_H
