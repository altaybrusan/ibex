#include "dbmanager.h"



DbManager::DbManager()
{
    _database = QSqlDatabase::addDatabase("QSQLITE");
    _database.setDatabaseName("./database/database.db");


}

bool DbManager::OpenConnection()
{
    if (!_database.open())
    {
        qDebug() << "Failed to open the database";
        return false;
    }
    else
    {
        qDebug()<<"Database connection is made...";
        return true;
    }
}

void DbManager::CloseConnection()
{
    if (_database.open())
    {
        _database.close();
        _database.removeDatabase(QSqlDatabase::defaultConnection);
    }
}
