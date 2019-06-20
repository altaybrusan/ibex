#ifndef WORKLISTDIALOG_H
#define WORKLISTDIALOG_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
    class WorkListDialog;
}

class WorklistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WorklistDialog(QWidget *parent = 0);
    void SetColumnHidden(int column,bool value);
    void SetColumnTitle(int column,QString title);
    void SetViewModel(QSqlTableModel* model);
    ~WorklistDialog();

signals:
    void NotifyFetchRISRequestTriggered();
    void NotifySelectedRecord(int row);

private slots:
    void on_reloadBtn_clicked();
    void on_tableView_doubleClicked(const QModelIndex &index);

private:

    Ui::WorkListDialog *ui;
};

#endif // WORKLISTDIALOG_H
