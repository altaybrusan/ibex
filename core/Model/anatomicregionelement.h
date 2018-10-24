#ifndef ANATOMICREGION_H
#define ANATOMICREGION_H
#include "Model/DICOM_ENUMS.h"
#include <QObject>

class AnatomicRegionElement : public QObject
{
    Q_OBJECT

public:
    explicit AnatomicRegionElement(QObject *parent = nullptr);


    void SetBodyPart(iBEX::BODY_PART );
    void SetCodeValue(QString code);
    void setCodeMeaning(QString meaning);

    iBEX::BODY_PART GetBodyPart();
    QString GetCodeValue();
    QString GetCodeMeaning();

signals:

public slots:

  private:
    iBEX::BODY_PART m_bodyPart;
    QString m_codeValue;
    QString m_codeMeaning;
};

#endif // ANATOMICREGION_H
