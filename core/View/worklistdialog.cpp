#include "worklistdialog.h"
#include "ui_worklistdialog.h"

#include <QSqlField>
#include <QSqlRecord>



WorkListDialog::WorkListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkListDialog)
{
    ui->setupUi(this);
}

void WorkListDialog::SetColumnHidden(int column, bool value)
{
    ui->tableView->setColumnHidden(column,value);
}

void WorkListDialog::SetColumnTitle(int column, QString title)
{
    model->setHeaderData(column, Qt::Horizontal, title);
}

WorkListDialog::~WorkListDialog()
{
    delete ui;
}

void WorkListDialog::on_reloadBtn_clicked()
{

}


void WorkListDialog::on_tableView_doubleClicked(const QModelIndex &index)
{
    emit NotifySelectedRecord(index);
}
