#include "anatomicregionelement.h"

AnatomicRegionElement::AnatomicRegionElement(QObject *parent) : QObject(parent)
{

}

void AnatomicRegionElement::SetBodyPart(iBEX::BODY_PART bodyPart)
{
    m_bodyPart= bodyPart;
}

void AnatomicRegionElement::SetCodeValue(QString code)
{
    m_codeValue=code;
}

void AnatomicRegionElement::setCodeMeaning(QString meaning)
{
    m_codeMeaning =meaning;
}

iBEX::BODY_PART AnatomicRegionElement::GetBodyPart()
{
    return m_bodyPart;
}

QString AnatomicRegionElement::GetCodeValue()
{
    return m_codeValue;
}

QString AnatomicRegionElement::GetCodeMeaning()
{
    return m_codeMeaning;
}
