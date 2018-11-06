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
    QListWidgetItem* item = new QListWidgetItem(filterName,ui->filtersListWidget);

    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);
}

FiltersDialog::~FiltersDialog()
{
    delete ui;
}
