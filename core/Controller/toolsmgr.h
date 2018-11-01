#ifndef TOOLSMGR_H
#define TOOLSMGR_H

#include <QObject>
class ToolsDialog;

class ToolsMgr : public QObject
{
    Q_OBJECT
public:
    explicit ToolsMgr(QObject *parent, ToolsDialog& dialog);

signals:

public slots:
    void OnActivateToolsDialog();
private:
    ToolsDialog& m_dialog;
};

#endif // TOOLSMGR_H
