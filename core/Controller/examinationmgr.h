#ifndef EXPOSUREDIALOGMGR_H
#define EXPOSUREDIALOGMGR_H

#include <QObject>
#include "View/examinationdialog.h"
class ExaminationMgr : public QObject
{
    Q_OBJECT
public:
    explicit ExaminationMgr(QObject *parent,ExaminationDialog& dialog );

signals:

public slots:
    void OnActivateExamination();
private:
    ExaminationDialog& m_dialog;
};

#endif // EXPOSUREDIALOGMGR_H
