#ifndef EXPOSUREDIALOG_H
#define EXPOSUREDIALOG_H

#include <QDialog>
#include <QSqlRecord>
namespace Ui {
class ExposureDialog;
}

class ExposureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExposureDialog(QWidget *parent = 0);
    void SetRecord(QSqlRecord* record);
    ~ExposureDialog();

private:
    Ui::ExposureDialog *ui;
    QSqlRecord* _record;
};

#endif // EXPOSUREDIALOG_H
