#ifndef LOADSTUDYDIALOG_H
#define LOADSTUDYDIALOG_H

#include <QDialog>

namespace Ui {
class LoadStudyDialog;
}

class LoadStudyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoadStudyDialog(QWidget *parent = 0);
    ~LoadStudyDialog();

private:
    Ui::LoadStudyDialog *ui;
};

#endif // LOADSTUDYDIALOG_H
