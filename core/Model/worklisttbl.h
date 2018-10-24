#ifndef WORKLISTTBL_H
#define WORKLISTTBL_H
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
#endif // WORKLISTTBL_H
