#ifndef EXAMINATIONDIALOG_H
#define EXAMINATIONDIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include "View/imageviewer.h"


namespace Ui {
class ExaminationDialog;

}
class RegistrationFormModel;
class ExaminationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExaminationDialog(QWidget *parent, ImageViewer& viewer);
    void UpdatePatientForm(RegistrationFormModel& model);
    void Show();
    ~ExaminationDialog();

private:

    void LoadDevicePlugins();
    Ui::ExaminationDialog *ui;
    QStandardItemModel* table;
    ImageViewer& m_viewer;

};

#endif // EXPOSUREDIALOG_H
