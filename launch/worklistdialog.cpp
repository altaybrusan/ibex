#include "worklistdialog.h"
#include "ui_worklistdialog.h"

WorkListDialog::WorkListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkListDialog)
{
    ui->setupUi(this);
}

WorkListDialog::~WorkListDialog()
{
    delete ui;
}
