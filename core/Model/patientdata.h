#ifndef PATIENTDEMOGRAPHICDATA_H
#define PATIENTDEMOGRAPHICDATA_H

#include <QObject>

class PatientData : public QObject
{
    Q_OBJECT
public:
    explicit PatientData(QObject *parent = nullptr);

    enum DemographyKeys
    {
        LastName,
        FirstName,
        MiddleName,
        PatientID,
        DOB,
        Gender,
        ReferrinPhysician,
        AdmissionNumber,
        AccessionNumber
    };


signals:

public slots:

private:
    QStringList m_ProcedureList;
};

#endif // PATIENTDEMOGRAPHICDATA_H
