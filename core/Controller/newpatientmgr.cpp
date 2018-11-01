#include "newpatientmgr.h"
#include "View/newpatientdialog.h"
#include "Utils/logmgr.h"
#include "Controller/examinationmgr.h"
#include "Utils/databasemgr.h"

NewPatientMgr::NewPatientMgr(QObject *parent,
                             NewPatientDialog &dialog,
                             RegistrationFormModel &model,
                             ExaminationMgr &examController) :
    QObject(parent),
    m_model(model),
    m_examinationMgr(examController),
    m_dialog(dialog)
{    
  m_dialog.SetFormModel(model);
  connect(&dialog,&NewPatientDialog::NotifyRegistrationFormCompleted,
          this,[&](){
      LogMgr::instance()->LogSysInfo("tring to call examination dialog");

      m_examinationMgr.OnActivateExaminationAfterRegistration(model);

  });
}

void NewPatientMgr::OnActivateNewPatientDialog()
{
    LogMgr::instance()->LogAppInfo(tr("new patient registration workflow is started"));
    m_dialog.show();
}
