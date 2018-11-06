#include "filtersdialog.h"
#include "ui_filtersdialog.h"

FiltersDialog::FiltersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FiltersDialog)
{
    ui->setupUi(this);
}

FiltersDialog::~FiltersDialog()
{
    delete ui;
}
