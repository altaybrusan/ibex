#include "filtersdialog.h"
#include "ui_filtersdialog.h"

FiltersDialog::FiltersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FiltersDialog)
{
    ui->setupUi(this);
}

void FiltersDialog::AddItemToList(QString filterName)
{
    new QListWidgetItem(filterName,ui->filtersListWidget);

}

FiltersDialog::~FiltersDialog()
{
    delete ui;
}
