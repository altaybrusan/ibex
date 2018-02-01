#include "exposuredialog.h"
#include "ui_exposuredialog.h"

ExposureDialog::ExposureDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExposureDialog)
{
    ui->setupUi(this);
}

ExposureDialog::~ExposureDialog()
{
    delete ui;
}
