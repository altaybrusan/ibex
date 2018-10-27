#include "newpatientmgr.h"
#include "View/newpatientdialog.h"

NewPatientMgr::NewPatientMgr(QObject *parent,
                             NewPatientDialog &dialog,
                             RegistrationFormModel &model) :
    QObject(parent),
    m_model(model),
    m_dialog(dialog)
{

  //m_dialog.SetFormModel(model);
}

void NewPatientMgr::OnActivateNewPatientDialog()
{
    m_dialog.show();
}
