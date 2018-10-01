#ifndef WORKLISTMODEL_H
#define WORKLISTMODEL_H

#include <QObject>
#include <QSqlRecord>
class WorklistModel : public QObject
{
    Q_OBJECT
public:
    explicit WorklistModel(QObject *parent = nullptr);
    void OpenConnection();
    void CloseConnection();
    QSqlRecord GetAnEmptyRecordForWorklist();
    void InsertRecordIntoWorklist(QSqlRecord* record);


signals:

public slots:

private:

};

#endif // WORKLISTMODEL_H
