#ifndef NEWPATIENTMGR_H
#define NEWPATIENTMGR_H

#include <QObject>
class NewPatientDialog;
class RegistrationFormModel;
class ExaminationMgr;
class NewPatientMgr : public QObject
{
    Q_OBJECT
public:
    explicit NewPatientMgr(QObject *parent,
                           NewPatientDialog& dialog,
                           RegistrationFormModel& model,
                           ExaminationMgr& examController);

signals:

public slots:
   void OnActivateNewPatientDialog();
private slots:
   void OnRegistrationFormCompleted();
private:
    RegistrationFormModel& m_model;
    NewPatientDialog& m_dialog;
    ExaminationMgr& m_examinationMgr;

};

#endif // NEWPATIENTMGR_H
