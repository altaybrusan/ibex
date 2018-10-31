#ifndef ANATOMICREGION_H
#define ANATOMICREGION_H
#include "Model/DICOM_ENUMS.h"
#include <QObject>


class AnatomicRegionElement : public QObject
{
    Q_OBJECT

public:
    explicit AnatomicRegionElement(QObject *parent = nullptr);
    AnatomicRegionElement(const AnatomicRegionElement &region);
    AnatomicRegionElement &operator=(const AnatomicRegionElement &lhs);
    bool operator==(const AnatomicRegionElement &lhs);
    void SetBodyPart(iBEX::BODY_PART part);
    void SetBodyPartView(iBEX::PATIENT_POSISTION position);
    void SetCodeValue(QString code);
    void setCodeMeaning(QString meaning);


    iBEX::BODY_PART GetBodyPart() const;
    iBEX::PATIENT_POSISTION GetBodyPartView() const;
    QString GetCodeValue() const;
    QString GetCodeMeaning() const;

signals:

public slots:

  private:
    iBEX::BODY_PART m_bodyPart;
    iBEX::PATIENT_POSISTION m_position;
    QString m_codeValue;
    QString m_codeMeaning;
};

#endif // ANATOMICREGION_H
