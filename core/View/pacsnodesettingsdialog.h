#ifndef PACSNODESETTINGSDIALOG_H
#define PACSNODESETTINGSDIALOG_H

#include <QDialog>
class ctkDICOMServerNodeWidget;

namespace Ui {
class PacsNodeSettingsDialog;
}

class PacsNodeSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PacsNodeSettingsDialog(QWidget *parent = 0);
    QString  GetCallingServerAET();
    QString GetStorageAETitle();
    int  GetCallingServerPort();


    ~PacsNodeSettingsDialog();

private slots:

private:
    Ui::PacsNodeSettingsDialog *ui;
    ctkDICOMServerNodeWidget* _dicomservernodeWidget;
};

#endif // PACSNODESETTINGSDIALOG_H
