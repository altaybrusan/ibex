#include "logindialog.h"
#include "ui_logindialog.h"
#include <QCryptographicHash>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

}

QString LoginDialog::GetUsername()
{
  return ui->userLineEdit->text();
}

QString LoginDialog::GetPassword()
{
   return QString::QString(QCryptographicHash::hash(ui->passwordlineEdit->text().toUtf8(),QCryptographicHash::Md5).toHex());
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
