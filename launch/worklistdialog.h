#ifndef WORKLISTDIALOG_H
#define WORKLISTDIALOG_H

#include <QDialog>

namespace Ui {
    class WorkListDialog;
}

class WorkListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WorkListDialog(QWidget *parent = 0);
    ~WorkListDialog();

private:
    Ui::WorkListDialog *ui;
};

#endif // WORKLISTDIALOG_H
