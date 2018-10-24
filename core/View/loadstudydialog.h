#ifndef LOADSTUDYDIALOG_H
#define LOADSTUDYDIALOG_H

#include <QDialog>

namespace Ui {
class LoadStudyDialog;
}
class ctkDICOMDatabase;
class LoadStudyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoadStudyDialog(QWidget *parent = 0);
    void UpdateRetrieveDatabase(QSharedPointer<ctkDICOMDatabase> dbPointer);
    ~LoadStudyDialog();

signals:
    void NotifyLoadStudyDialogIsClosing();

private:
    Ui::LoadStudyDialog *ui;
};

#endif // LOADSTUDYDIALOG_H
