#include "worklistdialog.h"
#include "ui_worklistdialog.h"

#include <QSqlField>
#include <QSqlRecord>



WorklistDialog::WorklistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkListDialog)
{
    ui->setupUi(this);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

}

void WorklistDialog::SetColumnHidden(int column, bool value)
{
    ui->tableView->setColumnHidden(column,value);
}

void WorklistDialog::SetColumnTitle(int column, QString title)
{
   ui->tableView->model()->setHeaderData(column, Qt::Horizontal, title);
}

void WorklistDialog::SetViewModel(QSqlTableModel *model)
{
    ui->tableView->setModel(model);
}

WorklistDialog::~WorklistDialog()
{
    delete ui;
}

void WorklistDialog::on_reloadBtn_clicked()
{
    emit NotifyFetchRISRequestTriggered();
}


void WorklistDialog::on_tableView_doubleClicked(const QModelIndex &index)
{
    emit NotifySelectedRecord(index.row());
}
