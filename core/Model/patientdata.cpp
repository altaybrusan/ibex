#include "patientdata.h"

PatientData::PatientData(QObject *parent) : QObject(parent)
{
    
}

void PatientData::AddNewAnatomicRegion(AnatomicRegionElement region)
{

    m_anatomicRegionList.append(region);
}

void PatientData::RemoveAnatomicRegion(AnatomicRegionElement region)
{
    m_anatomicRegionList.removeOne(region);

}


void PatientData::UpdatePatientFirstName(QString name)
{
    m_name =name;

}

void PatientData::UpdatePatientLastName(QString lastName)
{
    m_lastName=lastName;

}

void PatientData::UpdatePatientMiddleName(QString middleName)
{
    m_middleName=middleName;

}

void PatientData::UpdatePatientId(QString id)
{
    m_id=id;

}
void PatientData::UpdatePatientDOB(QString dateOfBirth)
{
    m_dob = dateOfBirth;

}

void PatientData::UpdatePatientGender(QString gender)
{
    m_gender=gender;

}

void PatientData::UpdateReferringPhysician(QString physicianName)
{
    m_physician=physicianName;

}

void PatientData::UpdateAdmissionNumber(QString admission)
{
    m_admission = admission;

}

void PatientData::UpdateAccessionNumber(QString accession)
{
    m_accession = accession;
}

QString PatientData::GetPatientName()
{
    return m_name;
}

QString PatientData::GetPatientLastName()
{
    return m_lastName;
}

QString PatientData::GetPatientMiddleName()
{
    return m_middleName;
}

QString PatientData::GetPatientId()
{
    return m_id;
}

QString PatientData::GetPatientDOB()
{
    return m_dob;

}

QString PatientData::GetPatientGender()
{
    return m_gender;
}

QString PatientData::GetReferringPhysician()
{
    return m_physician;
}

QString PatientData::GetAdmissionNumber()
{
    return m_admission;
}

QString PatientData::GetAccessionNumber()
{
    return m_accession;
}

QList<AnatomicRegionElement> PatientData::GetAnatomicRegionList()
{
    return m_anatomicRegionList;
}

