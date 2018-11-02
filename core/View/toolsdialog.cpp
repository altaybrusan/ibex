#include "toolsdialog.h"
#include "ui_toolsdialog.h"
#include <QCryptographicHash>

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



void ToolsDialog::on_addUserBtn_clicked()
{
    emit NotifyAddUser();
}

void ToolsDialog::on_removeUserBtn_clicked()
{
    emit NotifyRemoveUser();
}

QString ToolsDialog::GetPassword()
{
    return QString::QString(QCryptographicHash::hash(ui->passwordLineEdit->text().toUtf8(),QCryptographicHash::Md5).toHex());
}

QString ToolsDialog::GetUser()
{
    return ui->userLineEdit->text();
}
