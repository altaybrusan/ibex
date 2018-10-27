#ifndef PATIENTDEMOGRAPHICDATA_H
#define PATIENTDEMOGRAPHICDATA_H

#include <QObject>
#include <Model/anatomicregionelement.h>

class RegistrationFormModel : public QObject
{
    Q_OBJECT
public:
    explicit RegistrationFormModel(QObject *parent = nullptr);
    void AddNewAnatomicRegion(AnatomicRegionElement region);
    void RemoveAnatomicRegion(AnatomicRegionElement region);
signals:

public slots:
    void UpdatePatientFirstName(QString name);
    void UpdatePatientLastName(QString lastName);
    void UpdatePatientMiddleName(QString middleName);
    void UpdatePatientId(QString id);
    void UpdatePatientDOB(QString dateOfBirth);
    void UpdatePatientGender(QString gender);
    void UpdateReferringPhysician(QString physicianName);
    void UpdateAdmissionNumber(QString admission);
    void UpdateAccessionNumber(QString accession);

    QString GetPatientName();
    QString GetPatientLastName();
    QString GetPatientMiddleName();
    QString GetPatientId();
    QString GetPatientDOB();
    QString GetPatientGender();
    QString GetReferringPhysician();
    QString GetAdmissionNumber();
    QString GetAccessionNumber();

    void AppendRegion(AnatomicRegionElement& element);
    void RemoveRegion(AnatomicRegionElement& element);

    QList<AnatomicRegionElement> GetAnatomicRegionList();

private:
    QList<AnatomicRegionElement> m_anatomicRegionList;
    QString m_name,m_lastName,
            m_middleName,m_id,
            m_dob,m_gender,m_physician,
            m_admission,m_accession;

};



#endif // PATIENTDEMOGRAPHICDATA_H
