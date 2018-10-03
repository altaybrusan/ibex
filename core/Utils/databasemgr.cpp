#include "databasemgr.h"
#include "Utils/singleton.h"
#include <QtConcurrent/QtConcurrent>
#include <QtConcurrent/QtConcurrent>
#include <QFutureWatcher>
#include <QSqlField>
#include <QSqlQuery>



QFutureWatcher<void> watcher;
QFuture<void> result;
DataBaseMgr::DataBaseMgr(QObject *parent) : QObject(parent)
{
    connect(&watcher, SIGNAL(finished()), this, SLOT(onDataFetchingFinished()));
}

DataBaseMgr::~DataBaseMgr()
{

}

DataBaseMgr *DataBaseMgr::instance()
{
    return Singleton<DataBaseMgr>::instance(DataBaseMgr::createInstance);

}

void DataBaseMgr::OpenDatabse()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("./database/database.db");

    if(m_database.open())
    {
        emit NotifyConnectionSuccess();
    }
    else
    {
        emit NotifyConnectionFailed();
    }
}

void DataBaseMgr::FetchDataFromDatabase()
{
    if(m_database.isOpen())
    {
        emit NotifyFetchingDataStarted();
        m_worklistModel= make_unique<QSqlTableModel>(this,m_database) ;
        m_studyModel= make_unique<QSqlTableModel>(this,m_database) ;
        m_userModel= make_unique<QSqlTableModel>(this,m_database) ;
        m_rejImgModel= make_unique<QSqlTableModel>(this,m_database) ;

        result = QtConcurrent::run([&]{
            m_worklistModel->setTable("WorkListTbl");
            m_worklistModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
            m_worklistModel->select();

            m_studyModel->setTable("StudyTbl");
            m_studyModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
            m_studyModel->select();


            m_userModel->setTable("userTbl");
            m_userModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
            m_userModel->select();


            m_rejImgModel->setTable("RejectedImageTbl");
            m_rejImgModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
            m_rejImgModel->select();
        });
        watcher.setFuture(result);
    }
}

bool DataBaseMgr::isConnectionOpen()
{
   return m_database.isOpen();
}

QSqlRecord DataBaseMgr::GetRecordTemplateForWorklistTable()
{
    try
    {
     return m_worklistModel.get()->record();
    }
    catch(...)
    {
      emit NotifyDataFetchError(tr("Fetch data before making a template"));
    }
    return QSqlRecord();
}

QSqlRecord DataBaseMgr::GetRecordTemplateForStudyTable()
{
    try
    {
     return m_studyModel.get()->record();
    }
    catch(...)
    {
      emit NotifyDataFetchError(tr("Fetch data before making a template"));
    }
    return QSqlRecord();
}

QSqlRecord DataBaseMgr::GetRecordTemplateForUserTable()
{
    try
    {
     return m_userModel.get()->record();
    }
    catch(...)
    {
      emit NotifyDataFetchError(tr("Fetch data before making a template"));
    }
    return QSqlRecord();
}

QSqlRecord DataBaseMgr::GetRecordTemplateForRejectedImageTable()
{
    try
    {
     return m_rejImgModel.get()->record();
    }
    catch(...)
    {
      emit NotifyDataFetchError(tr("Fetch data before making a template"));
    }
    return QSqlRecord();
}

void DataBaseMgr::AppendIntoWorklistTable(QSqlRecord record)
{
   m_worklistModel.get()->insertRecord(-1,record);
   if(!m_worklistModel.get()->submitAll())
   {
      emit NotifyWritingToDatabaseFailed("Can not write into Worklist table");
   }
}

void DataBaseMgr::AppendIntoStudyTable(QSqlRecord record)
{
    m_studyModel.get()->insertRecord(-1,record);
    if(!m_studyModel.get()->submitAll())
    {
       emit NotifyWritingToDatabaseFailed("Can not write into study table.");
    }
}

void DataBaseMgr::AppendIntoUserTable(QSqlRecord record)
{
    m_userModel.get()->insertRecord(-1,record);
    if(!m_userModel.get()->submitAll())
    {
       emit NotifyWritingToDatabaseFailed("Can not write into user table.");
    }
}

void DataBaseMgr::AppendIntoRejectedImageTable(QSqlRecord record)
{
    m_rejImgModel.get()->insertRecord(-1,record);
    if(!m_rejImgModel.get()->submitAll())
    {
       emit NotifyWritingToDatabaseFailed("Can not write into rejected images table.");
    }
}

void DataBaseMgr::DeleteRecordFromWorklistTableAt(int row)
{
    if(m_worklistModel.get()->removeRow(row))
    {
       if(m_worklistModel.get()->submitAll())
       {
           return;
       }
       else
       {
           emit NotifyDeletingFromDatabaseFailed(tr("Can not submit delete command to workist table"));
       }
    }
    else
    {
        emit NotifyDeletingFromDatabaseFailed(tr("Can not remove row from worklist dataset"));
    }
}

void DataBaseMgr::DeleteRecordFromStudyTableAt(int row)
{
    if(m_studyModel.get()->removeRow(row))
    {
       if(m_studyModel.get()->submitAll())
       {
           return;
       }
       else
       {
           emit NotifyDeletingFromDatabaseFailed(tr("Can not submit delete command to study table"));
       }
    }
    else
    {
        emit NotifyDeletingFromDatabaseFailed(tr("Can not remove row from study dataset"));
    }

}

void DataBaseMgr::DeleteRecordFromUserTableAt(int row)
{
    if(m_userModel.get()->removeRow(row))
    {
       if(m_userModel.get()->submitAll())
       {
           return;
       }
       else
       {
           emit NotifyDeletingFromDatabaseFailed(tr("Can not submit delete command to user table"));
       }
    }
    else
    {
        emit NotifyDeletingFromDatabaseFailed(tr("Can not remove row from user dataset"));
    }

}

void DataBaseMgr::DeleteRecordFromRejectedImageTableAt(int row)
{
    if(m_userModel.get()->removeRow(row))
    {
       if(m_rejImgModel.get()->submitAll())
       {
           return;
       }
       else
       {
           emit NotifyDeletingFromDatabaseFailed(tr("Can not submit delete command to rejected image table"));
       }
    }
    else
    {
        emit NotifyDeletingFromDatabaseFailed(tr("Can not remove row from rejected image dataset"));
    }
}

bool DataBaseMgr::isRecordinWorklistTable(QSqlRecord record)
{
    QString condition = RecordToQueryStringConverter(record);
    QString str_query="SELECT * FROM WorkListTbl WHERE "+condition;
    QSqlQuery query;
    query.exec(str_query);
    return query.next();
}

bool DataBaseMgr::isRecordinStudyTable(QSqlRecord record)
{
    QString condition = RecordToQueryStringConverter(record);
    QString str_query="SELECT * FROM StudyTbl WHERE "+condition;
    QSqlQuery query;
    query.exec(str_query);
    return query.next();
}

bool DataBaseMgr::isRecordinUserTable(QSqlRecord record)
{
    QString condition = RecordToQueryStringConverter(record);
    QString str_query="SELECT * FROM userTbl WHERE "+condition;
    QSqlQuery query;
    query.exec(str_query);
    return query.next();
}

bool DataBaseMgr::isRecordinRejectedImageTable(QSqlRecord record)
{
    QString condition = RecordToQueryStringConverter(record);
    QString str_query="SELECT * FROM RejectedImageTbl WHERE "+condition;
    QSqlQuery query;
    query.exec(str_query);
    return query.next();
}

void DataBaseMgr::UpdateWorklistTableAt(int row, QSqlRecord record)
{
    m_worklistModel.get()->insertRecord(row,record);
    m_worklistModel.get()->submitAll();
}

void DataBaseMgr::UpdateStudyTableAt(int row, QSqlRecord record)
{
    m_studyModel.get()->insertRecord(row,record);
    m_studyModel.get()->submitAll();
}

void DataBaseMgr::UpdateUserTableAt(int row, QSqlRecord record)
{
    m_userModel.get()->insertRecord(row,record);
    m_userModel.get()->submitAll();

}

void DataBaseMgr::UpdateRejectedImageTableAt(int row, QSqlRecord record)
{
    m_rejImgModel.get()->insertRecord(row,record);
    m_rejImgModel.get()->submitAll();
}

void DataBaseMgr::onDataFetchingFinished()
{
    emit NotifyFetchingDataFinished();
}

bool DataBaseMgr::CheckRecordConsistancy(QSqlTableModel *model, QSqlRecord record)
{
    QSqlRecord _modelRecord=model->record();
    int fieldsCountmodelRecord = _modelRecord.count();
    int fieldsCountRecord = record.count();

    if(fieldsCountRecord!=fieldsCountmodelRecord)
    {
        return false;
    };
    for(int index=0;index<fieldsCountRecord;index++)
    {
        if(_modelRecord.fieldName(index) != record.fieldName(index))
        {
            return false;
        }
    }
    return true;
}

DataBaseMgr *DataBaseMgr::createInstance()
{
    return new DataBaseMgr();

}

QString DataBaseMgr::RecordToQueryStringConverter(QSqlRecord record)
{
    QString string ="";
    for (int index=0; index<record.count();index++)
    {
        string += record.fieldName(index)+"='"+record.field(index).value().toString()+"'";
    }
    return string;
}
