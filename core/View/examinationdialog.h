#ifndef EXAMINATIONDIALOG_H
#define EXAMINATIONDIALOG_H

#include <QDialog>
#include <QSqlRecord>
#include "View/imageviewer.h"

namespace Ui {
class ExaminationDialog;
}

class ExaminationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExaminationDialog(QWidget *parent, ImageViewer& viewer);
    void SetRecord(QSqlRecord* record);
    void Show();
    ~ExaminationDialog();

private:

    void LoadDevicePlugins();
    Ui::ExaminationDialog *ui;
    ImageViewer& m_viewer;
    QSqlRecord* _record;
};

#endif // EXPOSUREDIALOG_H
