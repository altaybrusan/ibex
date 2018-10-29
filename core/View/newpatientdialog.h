#ifndef NEWPATIENTDIALOG_H
#define NEWPATIENTDIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMap>
#include "bodypartselectionsquare.h"

namespace Ui {
    class NewPatientDialog;
}
class RegistrationFormModel;
class NewPatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewPatientDialog(QWidget *parent);
    void SetFormModel(RegistrationFormModel& formModel);
    void WireConnections();
    ~NewPatientDialog();
signals:
    void NotifyRegistrationFormCompleted();

private slots:
    void OnBodyPartStatusChanged(iBEX::BODY_PART bodyPart,bool isSelected);

    void RefreshOkBtn();

    void on_buttonBox_accepted();

    void on_lastNameLineEdit_editingFinished();

    void on_firstNameLineEdit_editingFinished();

    void on_middleNameLineEdit_editingFinished();

    void on_patientIdLineEdit_editingFinished();

    void on_dateEdit_editingFinished();

    void on_genderComboBox_currentIndexChanged(int index);

    void on_referringPhysicianLineEdit_editingFinished();

    void on_admissionNumberLineEdit_editingFinished();

    void on_accessionNumberLineEdit_editingFinished();

    void on_buttonBox_rejected();

private:

    Ui::NewPatientDialog *ui;

    QGraphicsScene* scene;
    QGraphicsEllipseItem* ellipse;
    BodyPartSelectionSquare *head,*thorax,
    *abdomen,*pelvis,*fermur,*knee,*tibia,
    *ankle,*foot, *hand,*finger,*wrist,*elbow,*Scapula,*shoulder;

    QStringList _selectedBodyPartList;
    int _numberOfselectedBodyParts;
    BodyPartSelectionSquare* _temp;    
    QValidator *validator;
    RegistrationFormModel* m_model=nullptr;
};


#endif // NEWPATIENTDIALOG_H
