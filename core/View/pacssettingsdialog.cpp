#include "pacssettingsdialog.h"
#include "ui_pacssettingsdialog.h"
#include "ctkDICOMServerNodeWidget.h"



PacsSettingsDialog::PacsSettingsDialog(QWidget *parent) :
    QDialog(parent),
    _dicomservernodeWidget(new ctkDICOMServerNodeWidget(this)),
    ui(new Ui::PacsSettingsDialog)
{
    ui->setupUi(this);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    QHBoxLayout* layout=new QHBoxLayout(ui->frame);
    layout->addWidget(_dicomservernodeWidget);
    QApplication::restoreOverrideCursor();
}

QString PacsSettingsDialog::GetPACSServerAET()
{
    return _dicomservernodeWidget->callingAETitle();
}
QString PacsSettingsDialog::GetStorageServerAETitle()
{
    return _dicomservernodeWidget->storageAETitle();
}

int PacsSettingsDialog::GetPACSServerPort()
{
    return _dicomservernodeWidget->storagePort();
}


PacsSettingsDialog::~PacsSettingsDialog()
{
    _dicomservernodeWidget->saveSettings();
    _dicomservernodeWidget->readSettings();
    delete ui;
}

