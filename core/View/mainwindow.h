#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "worklistdialog.h"

class NewPatientDialog;
class LoadImageDialog;
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent, LoadImageDialog& loadImageDialog);
    ~MainWindow();
signals:
    void NotifyMainWindowIsLoaded();
    void NotifyNewStudyWorkFlowIsTriggered();
    void NotifyQuickStudyWorkFlowIsTriggered();
    void NotifyUpdatePACSSettingIsTriggered();
    void NotifyLoadStudyIsTriggered();
    void NotifyUpdateWorklistSettingsIsTriggered();
    void NotifyOpenStudyWorkFlowIsTriggered();
    void NotifyWorklistLoadIsTriggered();
    void NotiftToolsSettingsIsTriggered();

private slots:

    //void on_actionUpdatePACSServerSettingstriggered();
//    void on_newPatient_accepted();
//    void on_Patient_selected(QSqlRecord record);

    void on_action_Update_PACS_Server_Settings_triggered();
    void on_action_Update_Worklist_Settings_triggered();
    void on_action_Load_Study_triggered();
    void on_action_Open_Study_triggered();
    void on_action_Quick_Start_triggered();

    void on_action_Select_triggered();

    void on_action_New_Study_triggered();

    void on_action_About_triggered();

    void on_action_Get_Tools_Status_triggered();

protected:
    void showEvent( QShowEvent* event ) override;
private:
    Ui::MainWindow *ui;
    LoadImageDialog& m_loadImageDlg;
};

#endif // MAINWINDOW_H
