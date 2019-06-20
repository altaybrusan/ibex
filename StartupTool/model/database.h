#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>

namespace DataProvider
{
    class DataBase : public QObject
    {
        Q_OBJECT
    public:
        explicit DataBase(QObject *parent = nullptr);
        void WriteNewRecord(QString table,
                            QMap<QString, QString> &fieldsMap,
                            QMap<QString, QString> &procedureMap);

        ~DataBase();
    signals:
        void NotifyErrorDetected(const QString& errorMsg) const;


    public slots:

    private:

    };

}


#endif // DATABASE_H
