#ifndef WORKLISTMODEL_H
#define WORKLISTMODEL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlTableModel>

class WorklistModel : public QObject
{
    Q_OBJECT
public:
    explicit WorklistModel(QObject *parent);
    void MakeModel();
    void SetDatabase(QSqlDatabase* database);
    void AppendRecord(QSqlRecord& record);
    QSqlTableModel* GetModel();

signals:

public slots:
private:
      QSqlDatabase* m_database;
      QSqlTableModel* m_model;
};

#endif // WORKLISTMODEL_H
