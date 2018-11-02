#ifndef TOOLSMGR_H
#define TOOLSMGR_H

#include <QObject>
class ToolsDialog;
class DataBaseMgr;

class ToolsMgr : public QObject
{
    Q_OBJECT
public:
    explicit ToolsMgr(QObject *parent, ToolsDialog& dialog);

signals:

private slots:
    void OnAddUser();
    void OnRemoveUser();

public slots:
    void OnActivateToolsDialog();
private:
    ToolsDialog& m_dialog;
    DataBaseMgr* m_dbMgr;

};

#endif // TOOLSMGR_H
