#ifndef NEWPATIENTMGR_H
#define NEWPATIENTMGR_H

#include <QObject>
class NewPatientDialog;
class RegistrationFormModel;

class NewPatientMgr : public QObject
{
    Q_OBJECT
public:
    explicit NewPatientMgr(QObject *parent, NewPatientDialog& dialog,     RegistrationFormModel& model);

signals:

public slots:
   void OnActivateNewPatientDialog();
private:
    RegistrationFormModel& m_model;
    NewPatientDialog& m_dialog;

};

#endif // NEWPATIENTMGR_H
