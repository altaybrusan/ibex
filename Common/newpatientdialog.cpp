#include "newpatientdialog.h"
#include "ui_newpatientdialog.h"

NewPatientDialog::NewPatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPatientDialog)
{
    ui->setupUi(this);
}

NewPatientDialog::~NewPatientDialog()
{
    delete ui;
}
