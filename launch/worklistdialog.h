#ifndef WORKLISTDIALOG_H
#define WORKLISTDIALOG_H

#include <QDialog>
#include <qsqltablemodel>
#include <QMap>

namespace Ui {
    class WorkListDialog;
}

class WorkListDialog : public QDialog
{
    Q_OBJECT

public:

    QMap<int,QString> WorkListFieldTag={
        {0,"0020,0010"},{1,"0008,0050"},{2,"0010,0020"},
        {3,"0010,0010"},{4,"0010,1000"},{5,"0010,1001"},
        {6,"0010,1010"},{7,"0010,2180"},{8,"0010,0030"},
        {9,"0010,0040"},{10,"0010,2000"},{11,"0010,2110"},
        {12,"0010,21A0"},{13,"0010,4000"},{14,"0010,21B0"},
        {15,"0010,21C0"},{16,"0010,21D0"},{17,"0038,0050"},
        {18,"0038,0500"},{19,"0038,0021"},{20,"0038,0010"},
        {21,""},{22,"0038,0008"},{23,"0038,4000"},
        {24,""},{25,""},{26,"0040,0001"},
        {27,""},{28,"0020,000D"},{29,"0032,000A"},
        {30,"0032,000C"},{31,"0032,4000"},{32,"0032,1032"},
        {33,"0032,1060"},{34,"0032,1070"},{35,"0032,1000"},
        {36,"0032,1050"},{37,"0040,0009"},{38,"0040,0007"},
        {39,"0040,1001"},{40,"0040,0012"},{41,"0008,1032"},
        {42,""},{43,""},{44,""},
        {45,""},{46,"0008,0060"},{47,"0008,1070"},
        {48,""},{49,""},{50,""},
    };
    enum WORKLIST_FIELDS
    {
      studyid,         //(0020,0010) 0
      accessionnum,    //(0008,0050) 1
      patientid,       //(0010,0020) 2
      patientname,     //(0010,0010) 3
      otherpatientid,  //(0010,1000) 4
      otherpatientname,//(0010,1001) 5
      age,             //(0010,1010) 6
      occupation,      //(0010,2180) 7
      dob,             //(0010,0030) 8
      sex,             //(0010,0040) 9
      medicalalert,      //(0010,2000) 10
      contrastallergies, //(0010,2110) 11
      smokingstatus,     //(0010,21A0) 12
      patientcomments,   //(0010,4000) 13
      patienthistory,    //(0010,21B0) 14
      pregnancystatus,   //(0010,21C0) 15
      lastmenstrualdate, //(0010,21D0) 16
      specialneeds,      //(0038,0050) 17
      patientstate,      //(0038,0500) 18
      admittingtime,     //(0038,0021) 19
      admissionid,       //(0038,0010) 20
      visitdate,         //?           21
      visitstatus,       //(0038,0008)*22
      visitcomments,     //(0038,4000) 23
      refphysician,      //(0008,0090) 24
      scheduledstartdatetime,//(0040,0244) 25
      scheduledaetitle,   //(0040,0001) 26
      regsource,          //            27
      studyinstanceuid,   //(0020,000D) 28
      studystatus,        //(0032,000A)R 29
      studypriority,      //(0032,000C)R 30
      studycomments,      //(0032,4000)R 31
      requestingphysician,//(0032,1032)  32
      requestedproceduredescription,//(0032,1060) 33
      requestedcontrastagent, //(0032,1070) 34
      studystartdatetime,     //(0032,1000)R (0032,1001)R  35
      studycompletiondatetime, //(0032,1050)R (0032,1051)R 36
      scheduledprocedurestepid, //(0040,0009)              37
      scheduledprocedurestepdescription,//(0040,0007)      38
      requestedprocedureid, //(0040,1001)                  39
      premedication, //(0040,0012)                         40
      procedurecode, //(0008,1032)*                        41
      procedurecodevalue,//                                42
      procedurecodemeaning,//                              43
      mppsinstanceuid,//                                   44
      mppsstatus,//                                        45
      modality, //(0008,0060)                              46
      operatorname,//(0008,1070)                           47
      reserve1,//                                          48
      reserve2,//                                          49
      reserve3//                                           50
    };
    Q_ENUM(WORKLIST_FIELDS)
    explicit WorkListDialog(QWidget *parent = 0);
    ~WorkListDialog();

private slots:
    void on_reloadBtn_clicked();

private:
    void InitializeTableViewColumns();
    void IntializeTableViewModel();
    void ParsRISResponseAndInsertIntoTableModel();
    QSqlDatabase _database;
    QSqlTableModel *model;
    Ui::WorkListDialog *ui;
};

#endif // WORKLISTDIALOG_H
