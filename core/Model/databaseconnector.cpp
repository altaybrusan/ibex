#include "databaseconnector.h"
#include <QSqlDatabase>
#include "Utils/logmgr.h"
#include <QSqlError>
DatabaseConnector::DatabaseConnector(QObject *parent) :
    QObject(parent)
{

}

void DatabaseConnector::AddDatabase(QString driver,QString dbName)
{
    m_database = QSqlDatabase::addDatabase(driver);
    m_database.setDatabaseName(dbName);
}

bool DatabaseConnector::ConnectToDatabase()
{

    if (!m_database.open())
    {
        LogMgr::instance()->LogSysFail("Can not open databse connection:"+ m_database.lastError().text());
        return false;
    }
    else
    {
        LogMgr::instance()->LogSysInfo(tr("Database connection is estabilished."));

    }
    return true;
}

DatabaseConnector::~DatabaseConnector()
{
    m_database.close();
    LogMgr::instance()->LogSysInfo(tr("Database connection is closed."));

}
