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

class NewPatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewPatientDialog(QWidget *parent = 0);
    enum DemographyKeys
    {
        LastName,
        FirstName,
        MiddleName,
        PatientID,
        DOB,
        Gender,
        ReferrinPhysician,
        AdmissionNumber,
        AccessionNumber
    };
    ~NewPatientDialog();

private slots:
    void OnBodyPartStatusChanged(iBEX::BodyPart bodyPart,bool isSelected);
    void ActivateOkBtn();
    void on_buttonBox_accepted();

private:
    Ui::NewPatientDialog *ui;
    QGraphicsScene* scene;
    QGraphicsEllipseItem* ellipse;
    QMap<DemographyKeys,QString> demographics;
    BodyPartSelectionSquare *head,*thorax,
    *abdomen,*pelvis,*fermur,
    *knee,*tibia,*ankel,*foot,
    *hand,*finger,*wrist,*elbow,*Scapula,*shoulder;

    QStringList _selectedBodyPartList;
    int _numberOfselectedBodyParts;
    BodyPartSelectionSquare* _temp;


    QValidator *validator;
};

#endif // NEWPATIENTDIALOG_H
