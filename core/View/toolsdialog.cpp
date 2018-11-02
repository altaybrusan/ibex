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
    if(ui->retypePasswordlineEdit->text() == ui->passwordLineEdit->text())
    {
        ui->passwordLineEdit->setStyleSheet("border: 1px solid white");
        ui->retypePasswordlineEdit->setStyleSheet("border: 1px solid black");
        emit NotifyAddUser();
    }
    else
    {
     ui->passwordLineEdit->setStyleSheet("border: 1px solid red");
     ui->retypePasswordlineEdit->setStyleSheet("border: 1px solid red");
    }


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

void ToolsDialog::ClearCrenential()
{
    ui->userLineEdit->clear();
    ui->passwordLineEdit->clear();
    ui->retypePasswordlineEdit->clear();
}
