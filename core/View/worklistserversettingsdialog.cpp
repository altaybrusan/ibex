#include "worklistserversettingsdialog.h"
#include "ui_worklistserversettingsdialog.h"
#include <QtXml>
#include <QFile>
#include <QRegExpValidator>
#include <QRegExp>


QRegExp rxPort("^([0-9]{1,4}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])$");
QRegExp rxIP("^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$");

WorklistServerSettingsDialog::WorklistServerSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorklistServerSettingsDialog)
{
    ui->setupUi(this);

    QValidator *portValidator = new QRegExpValidator(rxPort, this);
    ui->portLineEdit->setValidator(portValidator);
    QValidator *ipValidator = new QRegExpValidator(rxIP, this);
    ui->ipAddresslineEdit->setValidator(ipValidator);
}

QString WorklistServerSettingsDialog::GetWorklistServerAETitle()
{
    return ui->AETitleLineEdit->text();
}

QString WorklistServerSettingsDialog::GetWorklistServerIP()
{
    return ui->ipAddresslineEdit->text();
}

QString WorklistServerSettingsDialog::GetWorklistServerPort()
{
    return ui->portLineEdit->text();
}

void WorklistServerSettingsDialog::SetWorklistServerAETitle(QString aetitle)
{
    ui->AETitleLineEdit->setText(aetitle);
}

void WorklistServerSettingsDialog::SetWorklistServerIP(QString ipaddress)
{
    if(rxIP.exactMatch(ipaddress))
        ui->ipAddresslineEdit->setText(ipaddress);
}

void WorklistServerSettingsDialog::SetWorklistServerPort(QString port)
{
    if(rxPort.exactMatch(port))
      ui->portLineEdit->setText(port);
}

WorklistServerSettingsDialog::~WorklistServerSettingsDialog()
{
    delete ui;
}

void WorklistServerSettingsDialog::on_buttonBox_accepted()
{
    emit NotifyAccepted();
}

void WorklistServerSettingsDialog::on_buttonBox_rejected()
{
    //this->close();
    emit NotifyRejected();
}
