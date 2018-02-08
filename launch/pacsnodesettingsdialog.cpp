#include "pacsnodesettingsdialog.h"
#include "ui_pacsnodesettingsdialog.h"
#include "ctkDICOMServerNodeWidget.h"

PacsNodeSettingsDialog::PacsNodeSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PacsNodeSettingsDialog)
{
    ui->setupUi(this);
    ctkDICOMServerNodeWidget* _dicomservernodeWidget= new ctkDICOMServerNodeWidget(this);
    QHBoxLayout* layout=new QHBoxLayout(ui->frame);
    layout->addWidget(_dicomservernodeWidget);
}

PacsNodeSettingsDialog::~PacsNodeSettingsDialog()
{
    delete ui;
}
