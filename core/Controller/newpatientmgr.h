#ifndef NEWPATIENTMGR_H
#define NEWPATIENTMGR_H

#include <QObject>
class NewPatientDialog;

class NewPatientMgr : public QObject
{
    Q_OBJECT
public:
    explicit NewPatientMgr(QObject *parent, NewPatientDialog& dialog);

signals:

public slots:
   void OnActivateNewPatientDialog();
private:
    NewPatientDialog& m_dialog;
};

#endif // NEWPATIENTMGR_H
