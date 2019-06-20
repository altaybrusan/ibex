#include "dcmtk/config/osconfig.h"    /* make sure OS specific configuration is included first */
#include "newpatientmgr.h"
#include "View/newpatientdialog.h"
#include "Utils/logmgr.h"
#include "Controller/examinationmgr.h"
#include "Utils/databasemgr.h"
#include "Model/DICOM_ENUMS.h"
#include "dcmtk/dcmdata/dcuid.h"
#include "dcmtk/ofstd/ofstream.h"
#include "Utils/dicomtools.h"
#include "Model/RegistrationFormModel.h"

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
  m_dialog.SetFormModel(m_model);
  connect(&dialog,&NewPatientDialog::NotifyRegistrationFormCompleted,
          this,&NewPatientMgr::OnRegistrationFormCompleted);
}

void NewPatientMgr::OnActivateNewPatientDialog()
{
    LogMgr::instance()->LogAppInfo(tr("new patient registration workflow is started"));
    m_model.ClearForm();
    m_dialog.ResetForm();
    m_dialog.show();
}

void NewPatientMgr::OnRegistrationFormCompleted()
{
      LogMgr::instance()->LogSysInfo("trying to insert procedures into database StudyTbl");
      DataBaseMgr* _databaseMgr = DataBaseMgr::instance();
      _databaseMgr->OpenDatabase();
      if(!_databaseMgr->isConnectionOpen())
      {
          LogMgr::instance()->LogSysFail("can not open connection to database: NewPatientMgr");
          return;
      }

      _databaseMgr->FetchDataFromDatabase();
      QString StudyId = DicomTools::GenerateStudyId();
      for(int row = 0 ; row < m_model.GetAnatomicRegionList().count() ; row++)
      {
          QSqlRecord _record = _databaseMgr->GetRecordTemplateForStudyTable();
          for(int a=0;a<=_record.count();a++)
          {
            _record.setValue(a,QString::number(0));
          }
          char uid[100];
          _record.setValue("studyid",StudyId);
          QMetaEnum _metaView = QMetaEnum::fromType<iBEX::PATIENT_POSISTION>();
          int _indx = static_cast<int>(m_model.GetAnatomicRegionList().at(row).GetBodyPartView());
          QString _view = QString::fromUtf8(_metaView.valueToKey(_indx));
          _record.setValue("viewid",_view);
          QMetaEnum _metaBodyPart = QMetaEnum::fromType<iBEX::BODY_PART>();
          _indx = static_cast<int>(m_model.GetAnatomicRegionList().at(row).GetBodyPart());
          QString _bodyPart = QString::fromUtf8(_metaBodyPart.valueToKey(_indx));
          _record.setValue("bodypart",_bodyPart);
          _record.setValue("seriesinstanceuid",dcmGenerateUniqueIdentifier(uid, SITE_SERIES_UID_ROOT));
          _record.setValue("seriesstartdatetime",QDateTime::currentDateTime().date().toString("yyyy.MM.dd"));
          QString sop =dcmGenerateUniqueIdentifier(uid, SITE_INSTANCE_UID_ROOT);
          _record.setValue("primarysopuid",sop);
          _record.setValue("secondarysopuid",sop+".1");
          _record.setValue("imageacqdatetime",QDateTime::currentDateTime().time().toString());
          _record.setValue("imagesendstatus","SCHEDULED");
          _record.setValue("imageprintstatus","SCHEDULED");
          _databaseMgr->AppendIntoStudyTable(_record);
     }

      char uid[100];
      QSqlRecord _record = _databaseMgr->GetRecordTemplateForInstanceTable();
      // initialize the record with dummy data
      for(int a=0;a<=_record.count();a++)
      {
          _record.setValue(a,QString::number(0));
      }
      _record.setValue("studyid",StudyId);
      _record.setValue("accessionnum",m_model.GetAccessionNumber());
      QString _fullName;
      if(!m_model.GetPatientMiddleName().isEmpty())
          _fullName = _fullName + "^"+ m_model.GetPatientMiddleName();
      if(!m_model.GetPatientLastName().isEmpty())
          _fullName = _fullName + "^" + m_model.GetPatientLastName();
      _record.setValue("patientname",_fullName);
      _record.setValue("patientid",m_model.GetPatientId());
      _record.setValue("sex",m_model.GetPatientGender());
      _record.setValue("refphysician",m_model.GetReferringPhysician());
      _record.setValue("admittingtime",QDateTime::currentDateTime().date().toString(Qt::ISODate));
      _record.setValue("studyinstanceuid",dcmGenerateUniqueIdentifier(uid, SITE_SERIES_UID_ROOT));
      _record.setValue("visitcomment","LOCAL");
      _record.setValue("studystatus","SCHEDULED");
      _record.setValue("studystartdatetime",QDate::currentDate().toString(Qt::ISODate));
      //OTHER FIELDS ARE NOT INSERTED YET
      _databaseMgr->AppendIntoInstanceTable(_record);


      m_examinationMgr.OnActivateExaminationAfterRegistration(m_model);

}
