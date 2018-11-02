#include "databasemgr.h"
#include "Utils/singleton.h"
#include <QtConcurrent/QtConcurrent>
#include <QtConcurrent/QtConcurrent>
#include <QFutureWatcher>
#include <QSqlField>
#include <QSqlQuery>
#include "Utils/logmgr.h"



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

void DataBaseMgr::OpenDatabase()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("./database/database.db");

    if(m_database.open())
    {
        LogMgr::instance()->LogSysInfo("DatabaseMgr successfully connected opened database");
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

        m_instanceModel= make_unique<QSqlTableModel>(this,m_database) ;
        m_studyModel = make_unique<QSqlTableModel>(this,m_database) ;
        m_userModel= make_unique<QSqlTableModel>(this,m_database) ;
        m_rejImgModel= make_unique<QSqlTableModel>(this,m_database) ;

        //result = QtConcurrent::run([=]{
            m_instanceModel->setTable("InstanceTbl");
            m_instanceModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
            m_instanceModel->select();


            m_studyModel.get()->setTable("StudyTbl");
            m_studyModel.get()->setEditStrategy(QSqlTableModel::OnManualSubmit);
            m_studyModel.get()->select();

            m_userModel->setTable("userTbl");
            m_userModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
            m_userModel->select();


            m_rejImgModel->setTable("RejectedImageTbl");
            m_rejImgModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
            m_rejImgModel->select();
        //});
        //watcher.setFuture(result);
    }
}

bool DataBaseMgr::isConnectionOpen()
{
   return m_database.isOpen();
}

QSqlRecord DataBaseMgr::GetRecordTemplateForInstanceTable()
{
    try
    {
     return m_instanceModel.get()->record();
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

void DataBaseMgr::AppendIntoInstanceTable(QSqlRecord record)
{
   m_instanceModel.get()->insertRecord(-1,record);
   if(!m_instanceModel.get()->submitAll())
   {
      emit NotifyWritingToDatabaseFailed("Can not write into instance table");
   }
   else
   {
       LogMgr::instance()->LogSysInfo("successfully sumbited to instance table.");
   }
}

void DataBaseMgr::AppendIntoStudyTable(QSqlRecord record)
{
    m_studyModel.get()->insertRecord(-1,record);
    if(!m_studyModel.get()->submitAll())
    {
       LogMgr::instance()->LogSysError("can not write into study table.");
       emit NotifyWritingToDatabaseFailed("Can not write into study table.");
    }
    else
    {
       LogMgr::instance()->LogSysInfo("successfully sumbited to study table");
    }
}

void DataBaseMgr::AppendIntoUserTable(QSqlRecord record)
{
    m_userModel.get()->insertRecord(-1,record);
    if(!m_userModel.get()->submitAll())
    {
       emit NotifyWritingToDatabaseFailed("Can not write into user table.");
    }
    else {
        LogMgr::instance()->LogSysInfo("successfully sumbited to user table");
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

void DataBaseMgr::DeleteRecordFromInstanceTableAt(int row)
{
    if(m_instanceModel.get()->removeRow(row))
    {
       if(m_instanceModel.get()->submitAll())
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
        emit NotifyDeletingFromDatabaseFailed(tr("Can not remove row from instance dataset"));
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
           LogMgr::instance()->LogSysError(tr("record is deleted from user table successfully"));
           return;
       }
       else
       {
           LogMgr::instance()->LogSysError(tr("can not submit delete command to user table"));
           emit NotifyDeletingFromDatabaseFailed(tr("can not submit delete command to user table"));
       }
    }
    else
    {
        LogMgr::instance()->LogSysError(tr("can not remove row from user table"));
        emit NotifyDeletingFromDatabaseFailed(tr("can not remove row from user table"));
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

bool DataBaseMgr::isRecordinInstanceTable(QSqlRecord record)
{
    QString condition = RecordToQueryStringConverter(record);
    QString str_query="SELECT * FROM instanceTbl WHERE "+condition;
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

    QString str_query = "SELECT * FROM userTbl WHERE  username= '"
                          + record.field(1).value().toString()+"'";
    LogMgr::instance()->LogSysInfo("The query string  is:"+ str_query);

    QSqlQuery query;
    query.exec(str_query);

    while(query.next())
    {
        if(query.value(2)== record.value(2).toString())
            return true;

    }
    return false;
}

bool DataBaseMgr::isRecordinRejectedImageTable(QSqlRecord record)
{
    QString condition = RecordToQueryStringConverter(record);
    QString str_query="SELECT * FROM RejectedImageTbl WHERE "+condition;
    QSqlQuery query;
    query.exec(str_query);
    return query.next();
}

void DataBaseMgr::UpdateInstanceTableAt(int row, QSqlRecord record)
{
    m_instanceModel.get()->insertRecord(row,record);
    m_instanceModel.get()->submitAll();
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

int DataBaseMgr::GetNumberOfUsers()
{
    return m_userModel.get()->rowCount();
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
        string += record.fieldName(index)+"= '"+record.field(index).value().toString()+"' ";
    }
    return string;
}
