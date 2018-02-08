#ifndef PACSNODESETTINGSDIALOG_H
#define PACSNODESETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class PacsNodeSettingsDialog;
}

class PacsNodeSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PacsNodeSettingsDialog(QWidget *parent = 0);
    ~PacsNodeSettingsDialog();

private:
    Ui::PacsNodeSettingsDialog *ui;
};

#endif // PACSNODESETTINGSDIALOG_H
