#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private slots:
    void on_action_New_Study_triggered();

    void on_action_Quick_Start_triggered();

    void on_action_Update_PACS_Server_Settings_triggered();

    void on_action_Load_Study_triggered();

    void on_newPatient_accepted();



private:
    Ui::MainWindow *ui;
    NewPatientDialog* _dialog;
};

#endif // MAINWINDOW_H
