#include <QString>
#include <QtTest>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlField>
#include <QSqlTableModel>



class TestDatabase : public QObject
{
    Q_OBJECT

public:
    TestDatabase();
    QString RecordToQueryStringConverter(QSqlRecord record);

private Q_SLOTS:
    void initTestCase();
    void TestWriteToTable1();
    void TestWriteToTable2();
    void TestReadFromTable1();
    void TestReadFromTable2();
    void TestChangeFieldInTable1();
    void TestSearchInTable1();
    void TestRecordConsistency();
    void TestAutoSqlStringMaker();
    void cleanupTestCase();
private:
    QSqlDatabase  _database;
    QSqlTableModel* _tbl1Dataset,* _tbl2Dataset;
};

TestDatabase::TestDatabase()
{
}

void TestDatabase::initTestCase()
{
    _database = QSqlDatabase::addDatabase("QSQLITE");
    _database.setDatabaseName("Demo.db");

    QVERIFY2(_database.open(),"Failed to open the database");
    _tbl1Dataset= new QSqlTableModel(this,_database) ;
    _tbl1Dataset->setTable("Tbl1");
    _tbl1Dataset->setEditStrategy(QSqlTableModel::OnManualSubmit);
    _tbl1Dataset->select();
    if(_tbl1Dataset->rowCount() != 0)
    {
        _tbl1Dataset->removeRows(0,_tbl1Dataset->rowCount());
    }

    _tbl2Dataset= new QSqlTableModel(this,_database) ;
    _tbl2Dataset->setTable("Tbl2");
    _tbl2Dataset->setEditStrategy(QSqlTableModel::OnManualSubmit);
    _tbl2Dataset->select();

    if(_tbl2Dataset->rowCount() != 0)
    {
        _tbl2Dataset->removeRows(0,_tbl2Dataset->rowCount());
    }

}

void TestDatabase::TestWriteToTable1()
{
    QSqlRecord _record = _tbl1Dataset->record();
    _record.setValue("F1","A1");
    _record.setValue("F2","A1");
    _record.setValue("F3","A1");
    _tbl1Dataset->insertRecord(-1,_record);

//    if(!_tbl1Dataset->lastError().text().isEmpty())
//     QWARN(_tbl1Dataset->lastError().text().toLatin1().data());

    QVERIFY2(_tbl1Dataset->submitAll(),"Sub-mission to Table 1 failed: ");
}

void TestDatabase::TestWriteToTable2()
{

    QSqlRecord _record = _tbl2Dataset->record();
    _record.setValue("F1","B1");
    _record.setValue("F2","B1");
    _record.setValue("F3","B1");
    _record.setValue("F4","B1");
    _tbl2Dataset->insertRecord(-1,_record);
    QVERIFY2(_tbl2Dataset->submitAll(),"Sub-mission to Table 2 failed: ");

}

void TestDatabase::TestReadFromTable1()
{
    QSqlRecord _record = _tbl1Dataset->record(0);

    QVERIFY2(_record.field(0).value().toString()== "A1","ERROR IN READING FROM TABLE 1");
    QVERIFY2(_record.field(1).value().toString()== "A1","ERROR IN READING FROM TABLE 1");
    QVERIFY2(_record.field(2).value().toString()== "A1","ERROR IN READING FROM TABLE 1");

}

void TestDatabase::TestReadFromTable2()
{
    QSqlRecord _record = _tbl2Dataset->record(0);
    QVERIFY2(_record.field(0).value().toString()== "B1","ERROR IN READING FROM TABLE 1");
    QVERIFY2(_record.field(1).value().toString()== "B1","ERROR IN READING FROM TABLE 1");
    QVERIFY2(_record.field(2).value().toString()== "B1","ERROR IN READING FROM TABLE 1");
    QVERIFY2(_record.field(3).value().toString()== "B1","ERROR IN READING FROM TABLE 1");
}

void TestDatabase::TestChangeFieldInTable1()
{
    for(int i=0; i<_tbl1Dataset->columnCount();i++)
    {
        QModelIndex _index = _tbl1Dataset->index(0,i);
        _tbl1Dataset->setData(_index,"A11");
    }
     QVERIFY2(_tbl1Dataset->submitAll(),"Failed to update field in table.");
}

void TestDatabase::TestSearchInTable1()
{
   QSqlQuery query;
   QString fieldValue ="A11";
   QString query_str ="SELECT * FROM tbl1 WHERE  F1='"+fieldValue+"'";
   QVERIFY2(query.exec(query_str),"CAN CONT PERFORM SEARCH");
   while(query.next())
    {
      qDebug()<<"F1:"<<query.value(0).toString();
      qDebug()<<"F2:"<<query.value(1).toString();
      qDebug()<<"F3:"<<query.value(2).toString();
   }
}

void TestDatabase::TestRecordConsistency()
{
    QSqlRecord _rec1 = _tbl1Dataset->record();
    QSqlRecord _rec2 = _tbl2Dataset->record();
    QVERIFY2(_rec1.count()==_rec2.count(),"The records are not consistent.");
    for(int i=0;i<_rec1.count();i++)
    {
        QVERIFY2(_rec1.fieldName(i) == _rec2.fieldName(i),"The records are not consistent.");
    }

}
QString TestDatabase::RecordToQueryStringConverter(QSqlRecord record)
{
    QString string ="";
    for (int index=0; index<record.count();index++)
    {
        string += record.fieldName(index)+"='"+record.field(index).value().toString()+"'";
    }
    return string;
}

void TestDatabase::TestAutoSqlStringMaker()
{

    QSqlRecord _record = _tbl1Dataset->record();
    _record.setValue("F1","D1");
    _record.setValue("F2","D1");
    _record.setValue("F3","D1");

    qDebug()<<RecordToQueryStringConverter(_record);

}

void TestDatabase::cleanupTestCase()
{
    if(_tbl1Dataset->isDirty())
        _tbl1Dataset->submitAll();

    if(_tbl2Dataset->isDirty())
        _tbl2Dataset->submitAll();

    _tbl1Dataset->deleteLater();
    _tbl2Dataset->deleteLater();

    _database.close();

}


QTEST_APPLESS_MAIN(TestDatabase)

#include "testdatabase.moc"
