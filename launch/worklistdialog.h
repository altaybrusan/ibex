#ifndef WORKLISTDIALOG_H
#define WORKLISTDIALOG_H

#include <QDialog>
#include <qsqltablemodel>
namespace Ui {
    class WorkListDialog;
}

class WorkListDialog : public QDialog
{
    Q_OBJECT

public:
    enum WORKLIST_FIELDS
    {
      studyid,
      accessionnum,
      patientid,
      patientname,
      otherpatientid,
      otherpatientname,
      age,
      occupation,
      dob,
      sex,
      medicalalert,
      contrastallergies,
      smokingstatus,
      patientcomments,
      patienthistory,
      pregnancystatus,
      lastmenstrualdate,
      specialneeds,
      patientstate,
      admittingtime,
      admissionid,
      visitdate,
      visitstatus,
      visitcomments,
      refphysician,
      scheduledstartdatetime,
      scheduledaetitle,
      regsource,
      studyinstanceuid,
      studystatus,
      studypriority,
      studycomments,
      requestingphysician,
      requestedproceduredescription,
      requestedcontrastagent,
      studystartdatetime,
      studycompletiondatetime,
      scheduledprocedurestepid,
      scheduledprocedurestepdescription,
      requestedprocedureid,
      premedication,
      procedurecode,
      procedurecodevalue,
      procedurecodemeaning,
      mppsinstanceuid,
      mppsstatus,
      modality,
      operatorname,
      reserve1,
      reserve2,
      reserve3
    };
    Q_ENUM(WORKLIST_FIELDS)
    explicit WorkListDialog(QWidget *parent = 0);
    ~WorkListDialog();

private slots:
    void on_reloadBtn_clicked();

private:
    void InitializeTableView();
    void ParsRISResponseAndInsertIntoTableModel();
    QSqlDatabase _database;
    QSqlTableModel *model;
    Ui::WorkListDialog *ui;
};

#endif // WORKLISTDIALOG_H
