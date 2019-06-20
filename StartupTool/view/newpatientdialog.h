#ifndef NEWPATIENTDIALOG_H
#define NEWPATIENTDIALOG_H

#include <QStringListModel>
#include <QDialog>
#include <QFile>

#include "database.h"


namespace Ui {
    class NewPatientDialog;
}
namespace StartupTool
{

    class NewPatientDialog : public QDialog
    {
        Q_OBJECT

    public:
        explicit NewPatientDialog(QWidget *parent = 0);
        ~NewPatientDialog();

    private slots:
        void on_acceptBtn_clicked();

    private:
        Ui::NewPatientDialog *ui;
        DataProvider::DataBase* _dataProvider = NULL;
        QFile* _bodyPartFile;
        QStringListModel* _bodyPartModel;
    };


}


#endif // NEWPATIENTDIALOG_H
