#include "toolsdialog.h"
#include "ui_toolsdialog.h"

ToolsDialog::ToolsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ToolsDialog)
{
    ui->setupUi(this);
}

ToolsDialog::~ToolsDialog()
{
    delete ui;
}
