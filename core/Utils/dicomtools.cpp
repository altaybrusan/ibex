#include "dicomtools.h"

DicomTools::DicomTools(QObject *parent) : QObject(parent)
{

}

QString DicomTools::GenerateAccessionNumber()
{
     year=QString::number(QDateTime::currentDateTime().date().year());
     month=QString::number(QDateTime::currentDateTime().date().month());
     date=QString::number(QDateTime::currentDateTime().date().day());
     hour=QString::number(QDateTime::currentDateTime().time().hour());
     minute=QString::number(QDateTime::currentDateTime().time().minute());
     msec=QString::number(QDateTime::currentDateTime().time().msec());
     return year+month+date+hour+minu+msec;


}
