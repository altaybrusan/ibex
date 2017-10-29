#ifndef NEWPATIENTDIALOG_H
#define NEWPATIENTDIALOG_H

#include <QDialog>

namespace Ui {
    class NewPatientDialog;
}

class NewPatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewPatientDialog(QWidget *parent = 0);
    ~NewPatientDialog();

private:
    Ui::NewPatientDialog *ui;
};

#endif // NEWPATIENTDIALOG_H
