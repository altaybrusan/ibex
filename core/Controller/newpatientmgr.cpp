#include "newpatientmgr.h"
#include "View/newpatientdialog.h"
#include "Utils/logmgr.h"
#include "Controller/examinationmgr.h"
#include "Utils/databasemgr.h"
#include "Model/DICOM_ENUMS.h"

#include <QSqlRecord>

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
      //_model->setTable("StudyTbl");
      DataBaseMgr _databaseMgr;

      QSqlRecord _record = _databaseMgr.GetRecordTemplateForStudyTable();

      char uid[100];
      QString StudyId =GenerateStudyID();
      _record.setValue("studyid",StudyId);
      _record.setValue("viewid",_dialog->GetSelectedProceduresList().at(0));
      _record.setValue("seriesinstanceuid",dcmGenerateUniqueIdentifier(uid, SITE_SERIES_UID_ROOT));
      _record.setValue("seriesstartdatetime",QDateTime::currentDateTime().date().toString("yyyy.MM.dd"));
      QString sop =dcmGenerateUniqueIdentifier(uid, SITE_INSTANCE_UID_ROOT);
      _record.setValue("primarysopuid",sop);
      _record.setValue("secondarysopuid",sop+".1");
      _record.setValue("imageacqdatetime",QDateTime::currentDateTime().time().toString());

      _record.setValue("imagesendstatus","SCHEDULED");
      _record.setValue("imageprintstatus","SCHEDULED");
      _model->insertRecord(_model->rowCount(),_record);

      if(_model->submitAll())
      {
          qDebug()<<"Successfully sumited to the db.";
      }
      else
      {
          qDebug()<<"Failed to sumite to the db.";
      }


          QSqlRecord _record2 = _model2->record();
          // initialize the record with dummy data
          for(int a=0;a<=_record2.count();a++)
          {
              _record2.setValue(a,QString::number(1));
          }
          _record2.setValue("studyid: ",StudyId);
          _record2.setValue("accessionnum",_dialog->GetPatientInfo(NewPatientDialog::AccessionNumber));

          QString fullname;

          if(_dialog->GetPatientInfo(NewPatientDialog::MiddleName) != "")
          {
              fullname = _dialog->GetPatientInfo(NewPatientDialog::FirstName)+"^"+
                         _dialog->GetPatientInfo(NewPatientDialog::MiddleName)+"^"+
                         _dialog->GetPatientInfo(NewPatientDialog::LastName);
          }
          else
          {
              fullname = _dialog->GetPatientInfo(NewPatientDialog::FirstName)+"^"+
                         _dialog->GetPatientInfo(NewPatientDialog::LastName);
          }

          _record2.setValue("patientname",fullname);
          _record2.setValue("patientid",_dialog->GetPatientInfo(NewPatientDialog::PatientID));
          _record2.setValue("sex",_dialog->GetPatientInfo(NewPatientDialog::Gender));
          _record2.setValue("refphysician",_dialog->GetPatientInfo(NewPatientDialog::ReferrinPhysician));
          _record2.setValue("admittingtime",QDateTime::currentDateTime().date().toString(Qt::ISODate));
          _record2.setValue("studyinstanceuid",dcmGenerateUniqueIdentifier(uid, SITE_SERIES_UID_ROOT));
          _record2.setValue("visitcomment","LOCAL");
          _record2.setValue("studystatus","SCHEDULED");
          _record2.setValue("studystartdatetime",QDate::currentDate().toString(Qt::ISODate));


          //OTHER FIELDS ARE NOT INSERTED YET
          _model2->insertRecord(_model2->rowCount(),_record2);

          if(_model2->submitAll())
          {
              qDebug()<<"Successfully sumited to the worklist table.";
          }
          else
          {
              qDebug()<<"Failed to submit to the worklist table. Due to: "<<_model2->lastError().text();;
          }


      //_database.close();

      m_examinationMgr.OnActivateExaminationAfterRegistration(model);

  });
}

void NewPatientMgr::OnActivateNewPatientDialog()
{
    LogMgr::instance()->LogAppInfo(tr("new patient registration workflow is started"));
    m_dialog.show();
}
