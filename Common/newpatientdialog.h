#ifndef NEWPATIENTDIALOG_H
#define NEWPATIENTDIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include "bodypartselectionsquare.h"

namespace Ui {
    class NewPatientDialog;
}

class NewPatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewPatientDialog(QWidget *parent = 0);
    ~NewPatientDialog();

private slots:
    void OnBodyPartStatusChanged(iBEX::BodyPart bodyPart,bool isSelected);

private:
    Ui::NewPatientDialog *ui;
    QGraphicsScene* scene;
    QGraphicsEllipseItem* ellipse;

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
