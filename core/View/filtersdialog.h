#ifndef FILTERSDIALOG_H
#define FILTERSDIALOG_H

#include <QDialog>
#include <QListWidget>

namespace Ui {
    class FiltersDialog;
}

class FiltersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FiltersDialog(QWidget *parent = 0);
    void AddItemToList(QString filterName);
    ~FiltersDialog();

private:
    Ui::FiltersDialog *ui;
};

#endif // FILTERSDIALOG_H
