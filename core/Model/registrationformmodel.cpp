#include "registrationformmodel.h"

RegistrationFormModel::RegistrationFormModel(QObject *parent) : QObject(parent)
{
    
}

void RegistrationFormModel::AddNewAnatomicRegion(AnatomicRegionElement region)
{

    m_anatomicRegionList.append(region);
}

void RegistrationFormModel::RemoveAnatomicRegion(AnatomicRegionElement region)
{
    m_anatomicRegionList.removeOne(region);

}


void RegistrationFormModel::UpdatePatientFirstName(QString name)
{
    m_name =name;

}

void RegistrationFormModel::UpdatePatientLastName(QString lastName)
{
    m_lastName=lastName;

}

void RegistrationFormModel::UpdatePatientMiddleName(QString middleName)
{
    m_middleName=middleName;

}

void RegistrationFormModel::UpdatePatientId(QString id)
{
    m_id=id;

}
void RegistrationFormModel::UpdatePatientDOB(QString dateOfBirth)
{
    m_dob = dateOfBirth;

}

void RegistrationFormModel::UpdatePatientGender(QString gender)
{
    m_gender=gender;

}

void RegistrationFormModel::UpdateReferringPhysician(QString physicianName)
{
    m_physician=physicianName;

}

void RegistrationFormModel::UpdateAdmissionNumber(QString admission)
{
    m_admission = admission;

}

void RegistrationFormModel::UpdateAccessionNumber(QString accession)
{
    m_accession = accession;
}

QString RegistrationFormModel::GetPatientName()
{
    return m_name;
}

QString RegistrationFormModel::GetPatientLastName()
{
    return m_lastName;
}

QString RegistrationFormModel::GetPatientMiddleName()
{
    return m_middleName;
}

QString RegistrationFormModel::GetPatientId()
{
    return m_id;
}

QString RegistrationFormModel::GetPatientDOB()
{
    return m_dob;

}

QString RegistrationFormModel::GetPatientGender()
{
    return m_gender;
}

QString RegistrationFormModel::GetReferringPhysician()
{
    return m_physician;
}

QString RegistrationFormModel::GetAdmissionNumber()
{
    return m_admission;
}

QString RegistrationFormModel::GetAccessionNumber()
{
    return m_accession;
}

void RegistrationFormModel::AppendRegion(AnatomicRegionElement &element)
{
    m_anatomicRegionList.append(element);
}

void RegistrationFormModel::RemoveRegion(AnatomicRegionElement &element)
{
    m_anatomicRegionList.removeOne(element);
}

bool RegistrationFormModel::IsContainRegion(AnatomicRegionElement &element)
{
    return m_anatomicRegionList.contains(element);
}

QList<AnatomicRegionElement> RegistrationFormModel::GetAnatomicRegionList()
{
    return m_anatomicRegionList;
}

