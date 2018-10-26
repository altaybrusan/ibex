#include "anatomicregionelement.h"

AnatomicRegionElement::AnatomicRegionElement(QObject *parent) : QObject(parent)
{

}

AnatomicRegionElement::AnatomicRegionElement(const AnatomicRegionElement &lhs)
{
    m_bodyPart = lhs.GetBodyPart();
    m_codeValue = lhs.GetCodeValue();
    m_codeMeaning = lhs.GetCodeMeaning();
}

AnatomicRegionElement &AnatomicRegionElement::operator=(const AnatomicRegionElement &lhs)
{
    m_bodyPart = lhs.GetBodyPart();
    m_codeValue = lhs.GetCodeValue();
    m_codeMeaning = lhs.GetCodeMeaning();

    return *this;
}

bool AnatomicRegionElement::operator==(const AnatomicRegionElement &lhs)
{
   return m_bodyPart == lhs.GetBodyPart();

}

void AnatomicRegionElement::SetBodyPart(iBEX::BODY_PART part)
{
    m_bodyPart= part;
}

void AnatomicRegionElement::SetCodeValue(QString code)
{
    m_codeValue=code;
}

void AnatomicRegionElement::setCodeMeaning(QString meaning)
{
    m_codeMeaning =meaning;
}


iBEX::BODY_PART AnatomicRegionElement::GetBodyPart() const
{
    return m_bodyPart;
}

QString AnatomicRegionElement::GetCodeValue() const
{
    return m_codeValue;
}

QString AnatomicRegionElement::GetCodeMeaning() const
{
    return m_codeMeaning;
}
