#ifndef WORKLISTSERVERSETTINGSDIALOG_H
#define WORKLISTSERVERSETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
    class WorklistServerSettingsDialog;
}

class WorklistServerSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WorklistServerSettingsDialog(QWidget *parent = 0);

    QString GetWorklistServerAETitle();
    QString GetWorklistServerIP();
    QString GetWorklistServerPort();
    void SetWorklistServerAETitle(QString aetitle);
    void SetWorklistServerIP(QString ipaddress);
    void SetWorklistServerPort(QString port);

    ~WorklistServerSettingsDialog();

signals:
    void NotifyAccepted();
    void NotifyRejected();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::WorklistServerSettingsDialog *ui;
};

#endif // WORKLISTSERVERSETTINGSDIALOG_H
