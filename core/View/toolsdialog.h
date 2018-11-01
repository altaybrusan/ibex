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
    ~ToolsDialog();

private:
    Ui::ToolsDialog *ui;
};

#endif // TOOLSDIALOG_H
