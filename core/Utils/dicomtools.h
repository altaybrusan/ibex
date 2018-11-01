#ifndef DICOMTOOLS_H
#define DICOMTOOLS_H

#include <QObject>

class DicomTools : public QObject
{
    Q_OBJECT
public:
    explicit DicomTools(QObject *parent = nullptr);
    static QString GenerateAccessionNumber();
    static QString GenerateStudyId();

signals:

public slots:
private:

};

#endif // DICOMTOOLS_H
