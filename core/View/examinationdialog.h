#ifndef EXAMINATIONDIALOG_H
#define EXAMINATIONDIALOG_H

#include <QDialog>
#include <QSqlRecord>
namespace Ui {
class ExaminationDialog;
}

class ExaminationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExaminationDialog(QWidget *parent = 0);
    void SetRecord(QSqlRecord* record);
    ~ExaminationDialog();

private:

    void LoadDevicePlugins();
    Ui::ExaminationDialog *ui;
    QSqlRecord* _record;
};

#endif // EXPOSUREDIALOG_H
