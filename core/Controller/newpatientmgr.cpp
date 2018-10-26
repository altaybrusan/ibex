#include "newpatientmgr.h"
#include "View/newpatientdialog.h"

NewPatientMgr::NewPatientMgr(QObject *parent, NewPatientDialog &dialog) :
    QObject(parent),
    m_dialog(dialog)
{

}

void NewPatientMgr::OnActivateNewPatientDialog()
{
    m_dialog.show();
}
