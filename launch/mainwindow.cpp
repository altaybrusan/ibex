#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newpatientdialog.h"
#include "exposuredialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_New_Study_triggered()
{
    NewPatientDialog* _dialog= new NewPatientDialog(this);
    _dialog->show();
}

void MainWindow::on_action_Quick_Start_triggered()
{
    ExposureDialog* _dialog =new ExposureDialog(this);

    _dialog->show();

}
