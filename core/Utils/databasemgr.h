#ifndef DATABASEMGR_H
#define DATABASEMGR_H

#include <QObject>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <memory>

class DataBaseMgr : public QObject
{
    Q_OBJECT
public:
    ~DataBaseMgr();
    static DataBaseMgr* instance();

    void OpenDatabase();
    void FetchDataFromDatabase();
    bool isConnectionOpen();

    QSqlRecord GetRecordTemplateForInstanceTable();
    QSqlRecord GetRecordTemplateForStudyTable();
    QSqlRecord GetRecordTemplateForUserTable();
    QSqlRecord GetRecordTemplateForRejectedImageTable();

    void AppendIntoInstanceTable(QSqlRecord record);
    void AppendIntoStudyTable(QSqlRecord record);
    void AppendIntoUserTable(QSqlRecord record);
    void AppendIntoRejectedImageTable(QSqlRecord record);

    void DeleteRecordFromInstanceTableAt(int row);
    void DeleteRecordFromStudyTableAt(int row);
    void DeleteRecordFromUserTableAt(int row);
    void DeleteRecordFromRejectedImageTableAt(int row);

    bool isRecordinInstanceTable(QSqlRecord record);
    bool isRecordinStudyTable(QSqlRecord record);
    bool isRecordinUserTable(QSqlRecord record);
    bool isRecordinRejectedImageTable(QSqlRecord record);

    void UpdateInstanceTableAt(int row,QSqlRecord record);
    void UpdateStudyTableAt(int row,QSqlRecord record);
    void UpdateUserTableAt(int row,QSqlRecord record);
    void UpdateRejectedImageTableAt(int row,QSqlRecord record);

    int GetNumberOfUsers();

signals:

    void NotifyConnectionSuccess();
    void NotifyConnectionFailed();
    void NotifyFetchingDataStarted();
    void NotifyFetchingDataFinished();
    void NotifyDataFetchError(QString message);
    void NotifyWritingToDatabaseFailed(QString message);
    void NotifyDeletingFromDatabaseFailed(QString message);

private slots:
    void onDataFetchingFinished();

private:
    template<typename T,typename... Args>
    static std::unique_ptr<T> make_unique(Args&&... args)
    {
       return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }

    explicit DataBaseMgr(QObject *parent = nullptr);
    bool CheckRecordConsistancy(QSqlTableModel* model,QSqlRecord record);
    static DataBaseMgr* createInstance();
    QString RecordToQueryStringConverter(QSqlRecord record);

     QSqlDatabase m_database ;
     std::unique_ptr<QSqlTableModel> m_instanceModel ;
     std::unique_ptr<QSqlTableModel> m_studyModel ;
     std::unique_ptr<QSqlTableModel> m_userModel ;
     std::unique_ptr<QSqlTableModel> m_rejImgModel ; // rejected Image model
};

#endif // DATABASEMGR_H
