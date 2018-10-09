#include "dicomtools.h"
#include <QDateTime>

DicomTools::DicomTools(QObject *parent) : QObject(parent)
{

}

QString DicomTools::GenerateAccessionNumber()
{
    QString year= QString::number(QDateTime::currentDateTime().date().year());
    QString month= QString::number(QDateTime::currentDateTime().date().month());
    QString date= QString::number(QDateTime::currentDateTime().date().day());
    QString hour= QString::number(QDateTime::currentDateTime().time().hour());
    QString minute= QString::number(QDateTime::currentDateTime().time().minute());
    QString msec= QString::number(QDateTime::currentDateTime().time().msec());
     return year+month+date+hour+minute+msec;


}
