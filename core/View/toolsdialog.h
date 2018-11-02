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

    ~ToolsDialog();
signals:
    void NotifyAddUser();
    void NotifyRemoveUser();

private slots:


    void on_addUserBtn_clicked();

    void on_removeUserBtn_clicked();

private:
    Ui::ToolsDialog *ui;

};

#endif // TOOLSDIALOG_H
