#include "loadstudydialog.h"
#include "ui_loadstudydialog.h"
#include <ctkDICOMImportWidget.h>

LoadStudyDialog::LoadStudyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadStudyDialog)
{
    ui->setupUi(this);
    ctkDICOMImportWidget* _widget = new ctkDICOMImportWidget(this);
}

LoadStudyDialog::~LoadStudyDialog()
{
    delete ui;
}
