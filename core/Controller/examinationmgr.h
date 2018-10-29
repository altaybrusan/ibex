#ifndef EXPOSUREDIALOGMGR_H
#define EXPOSUREDIALOGMGR_H

#include <QObject>
#include "View/examinationdialog.h"
class RegistrationFormModel;
class ExaminationMgr : public QObject
{
    Q_OBJECT
public:
    explicit ExaminationMgr(QObject *parent,ExaminationDialog& dialog );

signals:

public slots:
    void OnActivateExamination();
    void OnActivateExaminationAfterRegistration(RegistrationFormModel& model);
private:
    ExaminationDialog& m_dialog;

};

#endif // EXPOSUREDIALOGMGR_H
