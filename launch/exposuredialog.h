#ifndef EXPOSUREDIALOG_H
#define EXPOSUREDIALOG_H

#include <QDialog>

namespace Ui {
class ExposureDialog;
}

class ExposureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExposureDialog(QWidget *parent = 0);
    ~ExposureDialog();

private:
    Ui::ExposureDialog *ui;
};

#endif // EXPOSUREDIALOG_H
