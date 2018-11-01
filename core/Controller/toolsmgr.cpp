#include "toolsmgr.h"
#include "View/toolsdialog.h"

ToolsMgr::ToolsMgr(QObject *parent, ToolsDialog &dialog) :
    QObject(parent),
    m_dialog(dialog)
{

}

void ToolsMgr::OnActivateToolsDialog()
{
    m_dialog.show();
}
