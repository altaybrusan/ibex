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
    QString  GetCallingServerAET();
    QString GetStorageAETitle();
    int  GetCallingServerPort();
    void ClearAllPACSNodes();
    void AddPACSNodes(QMap<QString, QVariant> nodes);


    ~PacsSettingsDialog();

private slots:

private:
    Ui::PacsSettingsDialog *ui;
    ctkDICOMServerNodeWidget* _dicomservernodeWidget;
};

#endif // PACSNODESETTINGSDIALOG_H
