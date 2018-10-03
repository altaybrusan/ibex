#include "databaseservice.h"
#include <QSqlDatabase>
DatabaseService::DatabaseService(QObject *parent) : QObject(parent)
{


}

bool DatabaseService::Connect(QString driver, QString fullName)
{
    // register into db
    QSqlDatabase  _database = QSqlDatabase::addDatabase(driver);
    _database.setDatabaseName(fullName);
    if (!_database.open())
    {
#ifdef QT_DEBUG
       qDebug() << "Failed to open the database";
#else

#endif
        return false;
    }
    else
    {
        qDebug()<<"Database connection is made...";
    }
    return true;
}
