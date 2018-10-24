#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "worklistdialog.h"

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
    //void on_actionUpdatePACSServerSettingstriggered();
//    void on_newPatient_accepted();
    void on_actionOpenStudytriggered();
//    void on_Patient_selected(QSqlRecord record);
//    void on_Login_Successfully();
//    void on_Login_Failed();
    void on_action_Update_PACS_Server_Settings_triggered();
    void on_action_Update_Worklist_Settings_triggered();
    void on_action_Load_Study_triggered();
    void on_action_Open_Study_triggered();
    void on_action_Quick_Start_triggered();

protected:
    void showEvent( QShowEvent* event ) override;
private:
    Ui::MainWindow *ui;
//    QSqlTableModel* _model,*_model2;
};

#endif // MAINWINDOW_H
