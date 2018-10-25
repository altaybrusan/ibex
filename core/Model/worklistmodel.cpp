#include "worklistmodel.h"
#include <QSqlTableModel>

WorklistModel::WorklistModel(QObject *parent) :
    QObject(parent)
{

}

void WorklistModel::MakeModel()
{
     m_model = new QSqlTableModel(new QSqlTableModel(this,*m_database));
     m_model->setTable("WorkListTbl");
     m_model->setEditStrategy(QSqlTableModel::OnFieldChange);
}

void WorklistModel::SetDatabase(QSqlDatabase *database)
{
    m_database = database;
}

void WorklistModel::AppendRecord(QSqlRecord &record)
{
    m_model->insertRecord(-1,record);
}

QSqlTableModel *WorklistModel::GetModel()
{
    return m_model;
}
