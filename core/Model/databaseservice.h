#ifndef DATABASESERVICE_H
#define DATABASESERVICE_H
#include <QObject>

class QSqlDatabase;

class DatabaseService : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseService(QObject *parent = nullptr);
    static bool Connect(QString driver,QString fullName,...);



signals:

public slots:
private:
    QSqlDatabase  _database;
};

#endif // DATABASESERVICE_H
