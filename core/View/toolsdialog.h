#ifndef TOOLSDIALOG_H
#define TOOLSDIALOG_H

#include <QDialog>

namespace Ui {
    class ToolsDialog;
}

class ToolsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ToolsDialog(QWidget *parent = 0);
    QString GetPassword();
    QString GetUser();
    void ClearCrenential();
    void UpdateManufacturer(QString manufacturer);
    void UpdateInstitutionName(QString institutionName);
    void UpdateStationName(QString stationName);
    void UpdateManufacturersModelName(QString modelName);

    QString GetManufacturer();
    QString GetInstitutionName();
    QString GetStationName();
    QString GetManufacturersModelName();

    ~ToolsDialog();
signals:
    void NotifyAddUser();
    void NotifyRemoveUser();
    void NotifyDialogAccepted();

private slots:


    void on_addUserBtn_clicked();

    void on_removeUserBtn_clicked();

    void on_buttonBox_accepted();

private:
    Ui::ToolsDialog *ui;

};

#endif // TOOLSDIALOG_H
