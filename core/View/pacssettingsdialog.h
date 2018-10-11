#ifndef PACSNODESETTINGSDIALOG_H
#define PACSNODESETTINGSDIALOG_H

#include <QDialog>
class ctkDICOMServerNodeWidget;

namespace Ui {
class PacsSettingsDialog;
}

class PacsSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PacsSettingsDialog(QWidget *parent = 0);
    QString  GetPACSServerAET();
    QString GetStorageServerAETitle();
    int  GetPACSServerPort();

    ~PacsSettingsDialog();

private slots:

private:
    Ui::PacsSettingsDialog *ui;
    ctkDICOMServerNodeWidget* _dicomservernodeWidget;
};

#endif // PACSNODESETTINGSDIALOG_H
