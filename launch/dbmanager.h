#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>

class DbManager
{
public:
    DbManager();
    bool OpenConnection();
    void CloseConnection();
private:
    QSqlDatabase _database;
};

#endif // DBMANAGER_H
