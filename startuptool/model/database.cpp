#include "database.h"
namespace DataProvider
{
    //Database connection path
    static auto DATABASE_FULL_PATH= QStringLiteral("../../assets/db/dataBase");

    // Each instance of "DataBase" class creates a QSqlDatabase object.
    // this object holds the connection string inside. Inorder to avoid
    // repetitive connection strings the QSqlDatabase is made static to be
    // shared between all instances of QSqlDatabase objects.
    static QSqlDatabase _db;

    /*! This is a veri naive class to start to query the Database with qt and SQLite
     * In the next iterations this class will be passed to another plugin tool called
     * database tool
    */
    DataBase::DataBase(QObject *parent) : QObject(parent)
    {
        if(!_db.isValid())
        {
            _db = QSqlDatabase::addDatabase("QSQLITE");
            _db.setDatabaseName(DATABASE_FULL_PATH);
        }

        if(!_db.open())
        {

            qDebug()<<_db.lastError().text();
            emit NotifyErrorDetected(_db.lastError().text());
        }
        _db.close();

    }

    void DataBase::WriteNewRecord(QString table,
                                  QMap<QString,QString>& fieldsMap,
                                  QMap<QString,QString>& procedureMap)
    {


        QMapIterator<QString, QString> _iterator(fieldsMap);
        while (_iterator.hasNext()) {
            _iterator.next();
            qDebug() << _iterator.key() << ": " << _iterator.value() << endl;
        }

    }

    DataBase::~DataBase()
    {
        _db.close();
        _db.removeDatabase(_db.connectionName());
        qDebug()<<"The connection to database is closed and Database is being deleted";
    }
}

