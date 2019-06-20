#ifndef LOADSTUDYMGR_H
#define LOADSTUDYMGR_H

#include <QObject>
#include <QSharedPointer>
#include "ctkDICOMDatabase.h"

class LoadStudyDialog;


class LoadStudyMgr : public QObject
{
    Q_OBJECT
public:
    explicit LoadStudyMgr(QObject *parent, LoadStudyDialog& dialog,
                          QString dbFilename,
                          QString sqlSchematicsFileName);
    void SetLocalPacsDatabase(QString fileName);
    void UpdateLocalPacsDatabase();

signals:

public slots:

    void OnActivateLoadingStudy();


private:
    LoadStudyDialog& m_dialog;
    QString m_fileName;
    QSharedPointer<ctkDICOMDatabase> m_dbptr;
};

#endif // LOADSTUDYMGR_H
