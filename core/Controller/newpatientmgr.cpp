#include "newpatientmgr.h"
#include "View/newpatientdialog.h"
#include "Utils/logmgr.h"

NewPatientMgr::NewPatientMgr(QObject *parent,
                             NewPatientDialog &dialog,
                             RegistrationFormModel &model) :
    QObject(parent),
    m_model(model),
    m_dialog(dialog)
{    
  m_dialog.SetFormModel(model);
}

void NewPatientMgr::OnActivateNewPatientDialog()
{
    LogMgr::instance()->LogAppInfo(tr("new patient registration workflow is started"));
    m_dialog.show();
}
