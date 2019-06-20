#ifndef DATABASESERVICE_H
#define DATABASESERVICE_H
#include <QObject>
#include <QSqlDatabase>

class DatabaseConnector : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseConnector(QObject *parent = nullptr);
    void AddDatabase(QString driver, QString dbName);
    bool ConnectToDatabase();
    QSqlDatabase* GetDatabase();
    ~DatabaseConnector();

signals:

public slots:
private:
    QString m_driver;
    QSqlDatabase m_database;
};

#endif // DATABASESERVICE_H
