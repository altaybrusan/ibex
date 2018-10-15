#ifndef EXPOSUREDIALOG_H
#define EXPOSUREDIALOG_H

#include <QDialog>
#include <QSqlRecord>
namespace Ui {
class ExposureDialog;
}

class ExaminationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExaminationDialog(QWidget *parent = 0);
    void SetRecord(QSqlRecord* record);
    ~ExaminationDialog();

private:
    Ui::ExposureDialog *ui;
    QSqlRecord* _record;
};

#endif // EXPOSUREDIALOG_H
