#ifndef WORKLISTDIALOG_H
#define WORKLISTDIALOG_H

#include <QDialog>
#include <QSqlRecord>
#include <qsqltablemodel>
#include <QMap>

namespace Ui {
    class WorkListDialog;
}

class WorkListDialog : public QDialog
{
    Q_OBJECT

public:


    explicit WorkListDialog(QWidget *parent = 0);
    void SetColumnHidden(int column,bool value);
    void SetColumnTitle(int column,QString title);
    ~WorkListDialog();

signals:
    void NotifyRecoredSelected(QSqlRecord record);
    void NotifyFetchRISRequest();
    void NotifySelectedRecord(int row);

private slots:
    void on_reloadBtn_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:

    QSqlDatabase _database;
    QSqlTableModel *model;
    QSqlRecord selectedRecord;
    Ui::WorkListDialog *ui;
};

#endif // WORKLISTDIALOG_H
