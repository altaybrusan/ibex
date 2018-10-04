#ifndef DICOMTOOLS_H
#define DICOMTOOLS_H

#include <QObject>

class DicomTools : public QObject
{
    Q_OBJECT
public:
    explicit DicomTools(QObject *parent = nullptr);
    static QString GenerateAccessionNumber();

signals:

public slots:
private:
    QString year,month,date,hour,minute,msec,;
};

#endif // DICOMTOOLS_H
