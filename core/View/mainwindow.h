#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "worklistdialog.h"
//#include "logindialog.h"

class NewPatientDialog;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void NotifyMainWindowIsLoaded();
    void NotifyNewStudyWorkFlowIsTriggered();
    void NotifyQuickStudyWorkFlowIsTriggered();
    void NotifyUpdatePACSSettingIsTriggered();
    void NotifyLoadStudyIsTriggered();
    void NotifyUpdateWorklistSettingsIsTriggered();
    void NotifyOpenStudyWorkFlowIsTriggered();

private slots:
    void on_actionNewStudytriggered();
    void on_actionQuickStarttriggered();
    void on_actionUpdatePACSServerSettingstriggered();
    void on_actionLoadStudytriggered();
//    void on_newPatient_accepted();
    void on_actionUpdateWorklistSettingstriggered();
    void on_actionOpenStudytriggered();
//    void on_Patient_selected(QSqlRecord record);
//    void on_Login_Successfully();
//    void on_Login_Failed();

protected:
    void showEvent( QShowEvent* event ) override;
private:
    Ui::MainWindow *ui;
//    NewPatientDialog* _dialog;
//    WorkListDialog* wrkDlg;
//    LoginDialog* loginDlg;
//    QSqlTableModel* _model,*_model2;
};

#endif // MAINWINDOW_H
